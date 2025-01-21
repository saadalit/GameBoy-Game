#pragma once

using namespace std;


struct PixelPosition 
{
    float x;
    float y;
};

class Grid
{
public:
    static const int CELL_SIZE = 32;
    static const int WIDTH = 800 / CELL_SIZE;
    static const int HEIGHT = 800 / CELL_SIZE;

};
