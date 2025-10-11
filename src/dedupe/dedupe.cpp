#include <ranges>
#include <set>
#include <string>
#include <vector>
#include <iostream>

int main(void) { //
    auto input = std::vector<std::string>(
        {"abc", "dcf", "efg", "abc", "abc", "dcf", "hij"});
    std::set<std::string> output;
    for (const auto &s : std::views::reverse(input)) {
        output.insert(s);
    }
    std::cout << *output.begin() << std::endl;
}