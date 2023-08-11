#include "Point.hpp"

static float abs(float value)
{
    return (value >=0 ? value : -value);
}

static float area(Point a, Point b, Point c)
{
    float x1, y1;
    float x2, y2;
    float x3, y3;

    x1 = a.getX().toFloat();
    y1 = a.getY().toFloat();
    x2 = b.getX().toFloat();
    y2 = b.getY().toFloat();
    x3 = c.getX().toFloat();
    y3 = c.getY().toFloat();

    return (abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float abc = area(a, b, c);
    float pbc = area(point, b, c);
    float apc = area(a, point, c);
    float abp = area(a, b, point);

    return (abc == pbc + apc + abp);
}