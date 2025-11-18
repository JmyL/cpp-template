#pragma once

#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
#include <deque>
#include <set>

inline auto naive_deduplicate(std::vector<std::string> input) {
    std::set<std::string> set;
    for (const auto &str : input) {
        set.emplace(str);
    }
    std::deque<std::string> ret;
    // ret.reserve(set.size());
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        if (auto sit = set.find(*it); sit != set.end()) {
            ret.emplace_front(std::move(*it));
            set.erase(sit);
        }
    }
    return ret;
}

inline auto deduplicate(std::vector<std::string> input) {
    using It = decltype(input)::const_iterator;
    struct Cmp {
        bool operator()(const It &a, const It &b) const { return *a < *b; }
    };
    std::set<It, Cmp> set;
    for (auto it = input.cbegin(); it != input.cend(); ++it) {
        set.emplace(it);
    }

    std::vector<std::string> ret;
    ret.reserve(set.size());
    for (auto it = input.crbegin(); it != input.crend(); ++it) {
        if (auto sit = set.find(std::prev(it.base())); sit != set.end()) {
            ret.push_back(std::move(*it));
            set.erase(sit);
        }
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}