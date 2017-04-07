#include "gtest/gtest.h"
#include "sum.h"

TEST(SumTest, PositiveArgs)
{
    ASSERT_EQ(4, sum(3, 1));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
