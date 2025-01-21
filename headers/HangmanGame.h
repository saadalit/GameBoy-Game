#pragma once
#include"Game.h"
#include"Category.h"
#include<SFML/Audio.hpp>

class HangmanGame :public Game
{
private:
	sf::RenderWindow window;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	Category category;
	string hiddenWord;
	string gussedLetters;
	int gameType;
	int lives;
	int hiddenWordLength;
	int wrongGuesses;
	int letterFrequency;
	bool usedLetters[26];
	bool pause;
	int k;
	sf::Clock clock;
	sf::Time oneMinute;
	bool gameEnd;
	int win;
	Music music1;
	Music music2;
	Music music3;
	Music music4;
public:
	HangmanGame(int);
	~HangmanGame();
	void startGame();
	void renderGame();
	void checkInput(sf::Event& event);
	void checkWin();
	void checkLose();
	void checkLetter(char letter);
	void showWord(int);
	void drawHangman();
	void endGame(int);
	void showTime();
	int getScore();
};

