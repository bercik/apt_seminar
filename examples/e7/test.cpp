#include "gtest/gtest.h"
#include "StudentsDataSummary.h"
#include "StudentsDataProvider.h"

#include <vector>

using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::InSequence;
using ::testing::AtMost;
using ::testing::AtLeast;
using ::testing::_;
using ::testing::ExpectationSet;

class StudentsDataSummaryTest : public ::testing::Test
{
    protected:
        StudentsDataSummaryTest() : _sdpMock(), _sds(_sdpMock) {}

        MockIStudentsDataProvider _sdpMock;
        StudentsDataSummary _sds;

        std::vector<Student> _students
                { {18, 3}, {20, 4}, {17, 2}, {21, 5}, {20, 3} };
};






























TEST_F(StudentsDataSummaryTest, 
        Should_ThrowException_When_AverageAgeNoStudents)
{
    EXPECT_CALL(_sdpMock, hasNext())
        // .Times(1)
        .WillOnce(Return(false));

    EXPECT_THROW(_sds.averageAge(), std::invalid_argument);
}





























TEST_F(StudentsDataSummaryTest, 
        Should_ReturnResult_When_AverageAgeSomeStudents)
{
    InSequence dummy;

    for (size_t i = 0; i < _students.size(); ++i)
    {
        EXPECT_CALL(_sdpMock, hasNext())
            .WillOnce(Return(true));

        EXPECT_CALL(_sdpMock, getNext())
            .WillOnce(ReturnRef(_students[i]));
    }

    EXPECT_CALL(_sdpMock, hasNext())
        .WillOnce(Return(false));
    EXPECT_CALL(_sdpMock, reset())
        .Times(1);

    EXPECT_EQ(_sds.averageAge(), 19.2);
}





























TEST_F(StudentsDataSummaryTest, 
        Should_ThrowException_When_NumberOfStudentsAboveGradeMinGradeBelowTwoOrAboveFive)
{
    EXPECT_THROW(_sds.numberOfStudentsAboveGrade(1), std::invalid_argument);
    EXPECT_THROW(_sds.numberOfStudentsAboveGrade(6), std::invalid_argument);
    EXPECT_THROW(_sds.numberOfStudentsAboveGrade(0), std::invalid_argument);
}





























TEST_F(StudentsDataSummaryTest, 
        Should_ReturnZero_When_NumberOfStudensAboveGradeNoStudents)
{
    EXPECT_CALL(_sdpMock, hasNext())
        .Times(2)
        .WillRepeatedly(Return(false));

    EXPECT_CALL(_sdpMock, reset())
        .Times(2);

    EXPECT_DOUBLE_EQ(_sds.numberOfStudentsAboveGrade(3), 0.0);;
    EXPECT_DOUBLE_EQ(_sds.numberOfStudentsAboveGrade(2), 0.0);;
}





























TEST_F(StudentsDataSummaryTest, 
        Should_ReturnResult_When_NumberOfStudensAboveGradeSomeStudents)
{
    InSequence dummy;

    for (size_t i = 0; i < _students.size(); ++i)
    {
        EXPECT_CALL(_sdpMock, hasNext())
            .WillOnce(Return(true));

        EXPECT_CALL(_sdpMock, getNext())
            .WillOnce(ReturnRef(_students[i]));
    }

    EXPECT_CALL(_sdpMock, hasNext())
        .WillOnce(Return(false));
    EXPECT_CALL(_sdpMock, reset())
        .Times(1);
    
    EXPECT_EQ(_sds.numberOfStudentsAboveGrade(3), 2);
}





























TEST_F(StudentsDataSummaryTest, 
        Should_Pass_When_FooSomeArguments)
{
    EXPECT_CALL(_sdpMock, foo(10, 20.0))
        .Times(AtLeast(1));

    // failure 
    EXPECT_CALL(_sdpMock, foo(_, _))
        .Times(AtMost(2));

    // no failure
    // EXPECT_CALL(_sdpMock, foo(_, _))
    //     .Times(AtMost(2))
    //     .RetiresOnSaturation();

    EXPECT_EQ(_sdpMock.foo(10, 20.0), 0);
    EXPECT_EQ(_sdpMock.foo(10, 20.0), 0);
    EXPECT_EQ(_sdpMock.foo(10, 20.0), 0);
}



























int main(int argc, char **argv) 
{
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}
