#include <gtest/gtest.h>


bool IsPositive(int x) {
    return x > 0;
}

TEST(IsPositive, AllTrue) {
    ASSERT_TRUE(IsPositive(1));
    ASSERT_EQ(true, IsPositive(4));
}

TEST(IsPositive, AllFalse) {
    ASSERT_FALSE(IsPositive(-12313131));
    //ASSERT_TRUE(IsPositive(1));
    //ASSERT_FALSE(IsPositive(12313131));
    //ASSERT_EQ(true, IsPositive(4));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    /* code */
    return RUN_ALL_TESTS();
}
