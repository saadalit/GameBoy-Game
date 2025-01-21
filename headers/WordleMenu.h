#pragma once
#include"Menu.h"

class WordleMenu : public Menu
{
	Text Attempts;
	Text Timed;
	Text Untimed;
	Text Category;
	Text Category1;
	Text Category2;
	Text Category3;
public:
	WordleMenu();
	void display_instructions();
	int display_menu(Leaderboard1* lead);
	int display_categories();
	void displayAttempts();
};
