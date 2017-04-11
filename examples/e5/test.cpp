#include "gtest/gtest.h"
#include "vector.h"

class VectorTest : public ::testing::Test
{
    protected:
        VectorTest() : _v1(3.0, 4.0), _v2(-3.0, -4.0), _v3(0.0, 0.0), 
                       _v4(3.0, 4.0) {}
        // ~VectorTest() {}

        const Vector _v1;
        const Vector _v2;
        const Vector _v3;
        const Vector _v4;
};

TEST_F(VectorTest, Should_ReturnResult_WhenLength)
{
    EXPECT_DOUBLE_EQ(_v1.length(), 5.0);
    EXPECT_DOUBLE_EQ(_v2.length(), 5.0);
    EXPECT_DOUBLE_EQ(_v3.length(), 0.0);
    EXPECT_DOUBLE_EQ(_v4.length(), 5.0);
}

TEST_F(VectorTest, Should_ReturnResult_WhenEqualOperator)
{
    EXPECT_EQ(_v1, _v2); // BAD TEST
    EXPECT_EQ(_v1, _v4); 
}

TEST_F(VectorTest, Should_ReturnResult_WhenNotEqualOperator)
{
    EXPECT_NE(_v1, _v3);
    EXPECT_NE(_v2, _v3);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
