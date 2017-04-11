#include "gtest/gtest.h"
#include "vector.h"

template <typename T>
class VectorTest : public ::testing::Test
{
    protected:
        VectorTest() : _v1(3.0, 4.0), _v2(-3.0, -4.0), _v3(0.0, 0.0), 
                       _v4(3.0, 4.0) {}

        const Vector<T> _v1;
        const Vector<T> _v2;
        const Vector<T> _v3;
        const Vector<T> _v4;
};

typedef ::testing::Types<double, float, int> MyTypes;
TYPED_TEST_CASE(VectorTest, MyTypes);

TYPED_TEST(VectorTest, Should_ReturnResult_WhenDistance)
{
    EXPECT_DOUBLE_EQ(this->_v1.distance(), 5.0);
    EXPECT_DOUBLE_EQ(this->_v2.distance(), 5.0);
    EXPECT_DOUBLE_EQ(this->_v3.distance(), 0.0);
    EXPECT_DOUBLE_EQ(this->_v4.distance(), 5.0);
}

TYPED_TEST(VectorTest, Should_ReturnResult_WhenEqualOperator)
{
    EXPECT_EQ(this->_v1, this->_v2); // BAD TEST
    EXPECT_EQ(this->_v1, this->_v4); 

    Vector<TypeParam> _v5(0.0, 0.0);
    EXPECT_EQ(this->_v3, _v5);
}

TYPED_TEST(VectorTest, Should_ReturnResult_WhenNotEqualOperator)
{
    EXPECT_NE(this->_v1, this->_v3);
    EXPECT_NE(this->_v2, this->_v3);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
