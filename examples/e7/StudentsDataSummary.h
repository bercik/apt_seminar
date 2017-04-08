#ifndef STUDENTSDATASUMMARY_H
#define STUDENTSDATASUMMARY_H 

#include "StudentsDataProvider.h"

class StudentsDataSummary
{
    public:
        // dependecy injection
        StudentsDataSummary(IStudentsDataProvider& sdp) : _sdp(sdp) {}

        double averageAge() const throw(std::invalid_argument)
        {
            int sumAge = 0;
            int numberOfStudents = 0;

            while (_sdp.hasNext())
            {
                Student s = _sdp.getNext();
                sumAge += s.age;
                ++numberOfStudents;
            }

            if (numberOfStudents == 0)
            {
                throw std::invalid_argument(
                        "Can't calculate average from zero students");
            }

            _sdp.reset();

            return ((double)sumAge / (double)numberOfStudents);
        }

        int numberOfStudentsAboveGrade(unsigned short minGrade) 
            throw(std::invalid_argument)
        {
            // check if minGrade is in <2, 5> range
            if (minGrade < 2 || minGrade > 5)
            {
                throw std::invalid_argument(
                        "minGrade must be in <2, 5> range");
            }

            int numberOfStudents = 0;

            while (_sdp.hasNext())
            {
                Student s = _sdp.getNext();
                if (s.grade > minGrade)
                {
                    ++numberOfStudents;
                }
            }

            _sdp.reset();

            return numberOfStudents;
        }

    private:
        IStudentsDataProvider& _sdp;
};

#endif /* STUDENTSDATASUMMARY_H */
