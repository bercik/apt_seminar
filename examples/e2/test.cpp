#include "gtest/gtest.h"
#include "sum.h"

TEST(SumTest, Should_ReturnResult_When_PositiveArgs)
{
    ASSERT_EQ(4, sum(3, 1));
    ASSERT_EQ(5, sum(2, 3));
}

TEST(SumTest, Should_ReturnResult_When_NegativeArgs)
{
    ASSERT_EQ(-4, sum(-3, -1));
    ASSERT_EQ(-5, sum(-2, -3));
}

TEST(SumTest, Should_ReturnResult_When_MixedArgs)
{
    ASSERT_EQ(0, sum(2, -2)) << " this wouldn't be printed";
    EXPECT_EQ(5, sum(4, -1)) 
        << " don't worry, this test is badly written"; // BAD TEST
    ASSERT_EQ(1, sum(-2, 2)) << " this test will execute"; // BAD TEST
    ASSERT_EQ(-4, sum(-5, 0)) << " this won't"; // BAD TEST
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
