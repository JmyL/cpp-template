#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

int main(void) {
    auto input = std::vector<std::string>(
        {"abc", "dcf", "efg", "abc", "abc", "dcf", "hij"});
    // std::set<std::string> output;
    // for (const auto &s : std::views::reverse(input)) {
    //     output.insert(s);
    // }

    std::ranges::sort(input);

    std::cout << *input.begin() << std::endl;
    std::cout << *input.rbegin() << std::endl;
    
}