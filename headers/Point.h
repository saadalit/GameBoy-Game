#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Point {
public:
    int x;
    int y;
    Point(int x = 0, int y = 0);
    bool operator==(const Point& other);
};