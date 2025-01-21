#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include"MainMenu.h"
#include"Game.h"
#include"SnakeGame.h"
#include"HangmanGame.h"
#include"WordleGame.h"
#include"Player.h"
#include"Leaderboard.h"
#include"WordleGame.h"

using namespace std;

class GameBoy
{
private:
	sf::RenderWindow window;
	Menu* menu[4];
	Game* currentGame;
	Player currPlayer;
	Font font;
	Leaderboard1* lead[3];
	int menuCheck;
	int snakeGameCheck;
	int hangmanGameCheck;
	int wordleGameCheck;
public:
	GameBoy();
	~GameBoy();
	void start();
	void shutDown();
	void enterPlayerName();
	int setMenus();
	void resetState();
	void showplayerInfo();
};

