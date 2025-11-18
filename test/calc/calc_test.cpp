#include "calc/calc.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <random>

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;

template <typename T> void print(const T &vec) {
    for (const auto &elem : vec) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
}

TEST(ANaiveDeduplicate, Works) {
    std::vector<std::string> input = {"John",  "Paul", "Ringo",  "Paul", "Paul",
                                      "Ringo", "John", "George", "Paul"};

    auto ret = naive_deduplicate(input);

    EXPECT_THAT(ret, ElementsAre("Ringo", "John", "George", "Paul"));
    print(ret);
}

TEST(ADeduplicate, Works) {
    std::vector<std::string> input = {"John",  "Paul", "Ringo",  "Paul", "Paul",
                                      "Ringo", "John", "George", "Paul"};

    auto ret = deduplicate(input);

    EXPECT_THAT(ret, ElementsAre("Ringo", "John", "George", "Paul"));
    print(ret);
}
