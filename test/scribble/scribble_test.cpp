#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::ElementsAre;

#include <vector>

auto get_vector() {
    std::vector<int> v = {1, 2, 3, 4};
    return v;
}

TEST(AScribble, SumAddsTwoInts) {
    EXPECT_THAT(get_vector(), ElementsAre(1, 2, 3, 4)); //
}

TEST(AMap, LowerBoundAndUpperBound) {
    std::map<int, std::string> m = {{1, "a"}, {3, "b"}, {5, "c"}};

    auto it = m.lower_bound(3);
    EXPECT_EQ(3, it->first);

    it = m.upper_bound(3);
    EXPECT_EQ(5, it->first);
}