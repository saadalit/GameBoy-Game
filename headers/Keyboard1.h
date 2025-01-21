#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"Letter.h"
using namespace std;

class Keyboard1
{
private:
	Letter keys[28];
	string keyLayout = "qwertyuiop;asdfghjkl,zxcvbnm";
	int keyCount = 0;
public:
	Keyboard1(float startX, float startY);
	int getKeysCount();
	Letter getKey(int i);
	char getClickedKey(int mouseX, int mouseY);
	void updateKeyStatus(char key, bool correct, bool present);
	void resetKeys();
};



