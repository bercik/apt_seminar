#ifndef VECTOR_H
#define VECTOR_H 

#include <math.h>

class Vector
{
    public:
        Vector(double x, double y) : _x(x), _y(y) {}

        double length() const
        {
            return sqrt(_x*_x + _y*_y);
        }

        bool operator==(const Vector& vect) const
        {
            return (_x == vect._x && _y == vect._y);
        }

        bool operator!=(const Vector& vect) const
        {
            return !this->operator==(vect);
        }

        // friend std::ostream& operator<<(std::ostream& os,
        //         const Vector& vect)
        // {
        //     os << "(" << vect._x << ", " << vect._y << ")";
        //     return os;
        // }

    private:
        const double _x, _y;
};

#endif /* VECTOR_H */
