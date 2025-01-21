#include <SFML/Graphics.hpp>
#include"GameBoy.h"
#include"Menu.h"
#include"Leaderboard.h"

#include <iostream>
using namespace std;

int main()
{
	// change made

	GameBoy gameboy;
	int check = 0;
	while (check==0)
	{
		check = gameboy.setMenus();
		gameboy.start();
		gameboy.resetState();
	}
    return 0;
}