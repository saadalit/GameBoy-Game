#pragma once
#include"Menu.h"

class HangmanMenu: public Menu
{
	Text Timed;
	Text Untimed;
	Text Category;
	Text Category1;
	Text Category2;
	Text Category3;
public:
	HangmanMenu();
	void display_instructions();
	int display_menu(Leaderboard1* lead);
	int display_categories();

};
