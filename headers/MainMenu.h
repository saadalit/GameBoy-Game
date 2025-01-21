#pragma once
#include"Menu.h"
#include"SnakeGameMenu.h"
#include"HangmanMenu.h"
#include"WordleMenu.h"


class MainMenu : public Menu
{
	Text Snake;
	Text Wordle;
	Text Hangman;
	Text playerInfo;

public:
	MainMenu();
	void display_instructions();
	int display_menu(Leaderboard1* lead);
	
};
