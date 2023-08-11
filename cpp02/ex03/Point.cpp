#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float pointX, const float pointY) : x(pointX), y(pointY) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
    if (this != &other)
    {
        (Fixed) this->x = other.x;
        (Fixed) this->y = other.y;
    }
    return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}
