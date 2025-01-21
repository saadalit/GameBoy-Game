#include<fstream>
#include "GameBoy.h"
#include "Leaderboard.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>


using namespace sf;

#ifndef MENU_H
#define MENU_H

class Menu 
{      
protected:
    RenderWindow window;
    Font font;
    Text menu;
    Text start;
    Text instructions;
    Text Leaderboard;
    Text exit;
    Text note;
    int men;

    Sprite menus;
    Texture menuback;
    Music music;
    Music click;
    Image icon1;


public:
    Menu();
    virtual void display_instructions() = 0;              
    virtual int display_menu(Leaderboard1* lead) = 0;
	
};


#endif
