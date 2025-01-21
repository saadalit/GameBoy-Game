#pragma once
#include"Menu.h"

class SnakeGameMenu : public Menu
{
	Text Easy;
	Text Medium;
	Text Hard;
	int menHor;
public:
	SnakeGameMenu();
	void display_instructions();
	int display_menu(Leaderboard1* lead);
};
