#pragma once
#include <SFML/Graphics.hpp>
#include"Game.h"
#include"Letter.h"
#include"Keyboard1.h"
#include"Dictionary.h"

class WordleGame :public Game
{
private:
	sf::RenderWindow window;
	Letter** letters;
	Keyboard1 keyboard;
	Dictionary dictionary;

	int columns;
	int rows;
	int currentRow;
	int currentColumn;
	string hiddenWord;
	string gussedLetters;
	int gameType;
	int lives;
	int wrongGuesses;
	bool usedLetters[26];
	sf::Clock clock;
	sf::Time oneMinute;
	bool gameEnd;
	int winOrLose;
	sf::Clock inputDelayClock;
	float inputDelay;
public:
	WordleGame(int);
	~WordleGame();
	void startGame();
	void renderGame();
	void showTime();
	void endGame(int);
	void handleInput(Event& event);
	void handleVirtualInput(char c);
	void checkWord();
	bool checkChar(char c);
	void showScore();
	int getScore();
};

