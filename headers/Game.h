#pragma once
#include <SFML/Graphics.hpp>
#include "Leaderboard.h"
#include <iostream>
using namespace std;
class Game
{
protected:
	string name;
	int score;
public:
	Game();
	~Game();
	virtual void startGame() = 0;
	virtual void endGame(int) = 0;
	virtual void renderGame() = 0;
	virtual int getScore() = 0;
	
};

