#include "SnakeSegment.h"

bool SnakeSegment::operator==(const SnakeSegment& other)
{
    return x == other.x && y == other.y;
}

SnakeSegment::SnakeSegment(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool SnakeSegment::operator==(const Point& other)
{
	return x == other.x && y == other.y;
}