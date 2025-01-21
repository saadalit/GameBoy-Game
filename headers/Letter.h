#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Letter
{
private:
    RectangleShape box;
    Text text;
    char value;
    bool isCorrect;
    bool isPresent;
    const int letterSize = 70;
    Font font;

public:
    Letter();
    void setPosition(int x, int y);
    void setValue(char c);
    void setStatus(bool correct, bool present);
	void resetStatus();
    int getLetterSize();
    RectangleShape getBox();
    Text getText();
    char getValue();
};

