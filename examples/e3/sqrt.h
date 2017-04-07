#ifndef SQRT_H
#define SQRT_H 

#include <stdexcept>
#include <string>

// private method by convention
float _compute_pos_sqrt(const float x);

// this method returns square root of positive number
// if zero or negative number is given, invalid_argument exception is thrown
float sqrt(const float num) throw(std::invalid_argument)
{
    // check if given number is less or equal zero
    if (num <= 0.0f)
    {
        // if it is throw exception 
        throw std::invalid_argument("Number should be greater than 0. Got " + std::to_string(num));
    }

    // do some computations 
    float result = _compute_pos_sqrt(num);

    // return value
    return result;
}

// private methods 
float _compute_pos_sqrt(const float x) 
{
    union
    {
        int i;
        float x;
    } u;
    u.x = x;
    u.i = (1<<29) + (u.i >> 1) - (1<<22); 

    u.x =       u.x + x/u.x;
    u.x = 0.25f*u.x + x/u.x;

    return u.x;
}  

#endif /* SQRT_H */
