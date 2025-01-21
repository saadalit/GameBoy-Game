#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Player
{
	string name;
	int highScores[3];
	string achievements[3];

public:
	Player();
	~Player();
	void setName(string name);
	string getName();
	void setHighScore(int score, int index);
	int getHighScore(int index);
	void saveProgress(int score, string achievement);
	void loadProgress();
};
