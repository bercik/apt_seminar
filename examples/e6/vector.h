#ifndef VECTOR_H
#define VECTOR_H 

#include <math.h>

template <typename T>
class Vector
{
    public:
        Vector(T x, T y) : _x(x), _y(y) {}

        T length() const
        {
            return sqrt(_x*_x + _y*_y);
        }

        bool operator==(const Vector<T>& vect) const
        {
            return (_x == vect._x && _y == vect._y);
        }

        bool operator!=(const Vector<T>& vect) const
        {
            return !this->operator==(vect);
        }

        friend void PrintTo(const Vector<T>& vect, ::std::ostream* os) 
        {
            *os << "(" << vect._x << ", " << vect._y << ")";
        }

        // friend std::ostream& operator<<(std::ostream& os,
        //         const Vector& vect)
        // {
        //     os << "(" << vect._x << ", " << vect._y << ")";
        //     return os;
        // }

    private:
        const T _x, _y;
};

#endif /* VECTOR_H */
