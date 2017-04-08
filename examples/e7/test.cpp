#include "gtest/gtest.h"
#include "StudentsDataSummary.h"
#include "StudentsDataProvider.h"

#include <vector>

using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::InSequence;

class StudentsDataSummaryTest : public ::testing::Test
{
    protected:
        StudentsDataSummaryTest() : _sdp(), _sds(_sdp) {}

        MockIStudentsDataProvider _sdp;
        StudentsDataSummary _sds;

        std::vector<Student> students
                { {18, 3}, {20, 4}, {17, 2}, {21, 5}, {20, 3} };
};

TEST_F(StudentsDataSummaryTest, 
        Should_ThrowException_When_AverageAgeNoStudents)
{
    EXPECT_CALL(_sdp, hasNext())
        .Times(1)
        .WillOnce(Return(false));

    EXPECT_THROW(_sds.averageAge(), std::invalid_argument);
}

TEST_F(StudentsDataSummaryTest, 
        Should_ReturnResult_When_AverageAgeSomeStudents)
{
    InSequence dummy;

    for (Student s : students)
    {
        EXPECT_CALL(_sdp, hasNext())
            .WillOnce(Return(true))
            .RetiresOnSaturation();

        EXPECT_CALL(_sdp, getNext())
            .WillOnce(Return(s))
            .RetiresOnSaturation();
    }

    EXPECT_CALL(_sdp, hasNext())
        .WillOnce(Return(false));
    EXPECT_CALL(_sdp, reset())
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
    EXPECT_CALL(_sdp, hasNext())
        .Times(2)
        .WillRepeatedly(Return(false));

    EXPECT_CALL(_sdp, reset())
        .Times(2);

    EXPECT_DOUBLE_EQ(_sds.numberOfStudentsAboveGrade(3), 0.0);;
    EXPECT_DOUBLE_EQ(_sds.numberOfStudentsAboveGrade(2), 0.0);;
}

TEST_F(StudentsDataSummaryTest, 
        Should_ReturnResult_When_NumberOfStudensAboveGradeSomeStudents)
{
    InSequence dummy;

    for (Student s : students)
    {
        EXPECT_CALL(_sdp, hasNext())
            .WillOnce(Return(true))
            .RetiresOnSaturation();

        EXPECT_CALL(_sdp, getNext())
            .WillOnce(Return(s))
            .RetiresOnSaturation();
    }

    EXPECT_CALL(_sdp, hasNext())
        .WillOnce(Return(false));
    EXPECT_CALL(_sdp, reset())
        .Times(1);
    
    EXPECT_EQ(_sds.numberOfStudentsAboveGrade(3), 2);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}
