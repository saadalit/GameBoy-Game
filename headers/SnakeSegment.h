#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"Point.h"
using namespace std;

class SnakeSegment 
{
public:
    int x;
    int y;
    SnakeSegment(int x = 0, int y = 0);
    bool operator==(const SnakeSegment& other);
	bool operator==(const Point& other);

};
