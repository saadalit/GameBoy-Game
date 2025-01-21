#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
using namespace sf;
using namespace std;

#include "Game.h"
#include "SnakeSegment.h"
#include "Point.h"
#include"Grid.h"


class SnakeGame : public Game
{
	RenderWindow window;
    Texture snakeTexture;
    Texture foodTexture;
	Texture foodLenTexture;
	Texture foodSpeedTexture;
    Texture menuTexture;
    Texture horWall;
	Texture verWall;
	Texture hardWall;
    Sprite snakeSprite;
    Sprite foodSprite;
	Sprite foodLenSprite;
	Sprite foodSpeedSprite;
    Sprite menuSprite;
	Sprite horWallSprite[2];
	Sprite verWallSprite[2];
    Sprite hardWallSprite;
	Text scoreText;
	Text gameOverText;
	Font font;
    Music eatFood;
	Music hitWall;


    SnakeSegment snake[100]; 
    Point food;
    Point foodLen;
    Point foodSpeed;
	Grid grid;
	int easySpeed = 200;
	int mediumSpeed = 150;
	int hardSpeed = 100;
    int snakeLength = 3;
    int foodEaten;
    int temp;
    int difficulty;
    bool gameOver;
    SnakeSegment direction = { 1, 0 };
    void spawnFood();
    void handleInput();
    void update();
    void renderGame();


public:
	SnakeGame(int diff);
    void startGame();
    void endGame(int);
    int getScore();
};

#endif