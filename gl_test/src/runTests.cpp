#include "gtest/gtest.h"

TEST(AnyTest, shouldTestSomething) {
    //arrange
    int abc = 1 + 2;

    //assert
    ASSERT_EQ(abc, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
