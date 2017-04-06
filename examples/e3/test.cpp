#include "gtest/gtest.h"
#include "sqrt.h"

TEST(SqrtTest, PositiveArgs)
{
   EXPECT_FLOAT_EQ(2.0f, sqrt(4.0f));
   EXPECT_FLOAT_EQ(3.0f, sqrt(9.0f));
   EXPECT_FLOAT_EQ(5.196152423f, sqrt(27.0f));
   EXPECT_FLOAT_EQ(0.1f, sqrt(0.01f));
}

TEST(SqrtTest, ZeroVal)
{
   EXPECT_THROW(sqrt(0.0f), std::invalid_argument);
}

TEST(SqrtTest, DISABLED_NegativeArgs)
{
   EXPECT_THROW(sqrt(-2.0f), std::invalid_argument);
   EXPECT_THROW(sqrt(-6.0f), std::invalid_argument);
}

int main(int argc, char **argv) 
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
