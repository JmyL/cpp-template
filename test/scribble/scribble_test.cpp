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
