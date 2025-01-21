#include "Point.h"

bool Point::operator==(const Point& other)
{
    return x == other.x && y == other.y;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
