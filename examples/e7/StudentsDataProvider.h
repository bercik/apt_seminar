#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include "gmock/gmock.h"

struct Student
{
    unsigned int age;
    unsigned short grade; // <2, 5>
};

class IStudentsDataProvider
{
    public:
        virtual ~IStudentsDataProvider() {}

        virtual bool hasNext() const = 0;
        virtual const Student& getNext() = 0;
        // resets back to first student
        virtual void reset() = 0;

        // unused method
        virtual int foo(int a, double b) = 0;
};

class MockIStudentsDataProvider : public IStudentsDataProvider
{
    public:
        MOCK_CONST_METHOD0(hasNext, bool());
        MOCK_METHOD0(getNext, const Student&());
        MOCK_METHOD0(reset, void());

        MOCK_METHOD2(foo, int(int a, double b));
};

#endif
