#include "WordleGame.h"

WordleGame::WordleGame(int z) : keyboard(50, 600)
{
	gameType = z;
	gameEnd = false;
	if (gameType == 1)
	{
		oneMinute = sf::seconds(60);
	}
	name = "Wordle Game";
	window.create(sf::VideoMode(870, 870), name);
	srand(static_cast<unsigned>(time(0)));
	int randomNumber = 0;
	if (gameType == 1 || gameType == 2)
	{
		randomNumber = rand() % 50;
	}
	else if (gameType == 3)
	{
		randomNumber = rand() % 20;
	}
	else if (gameType == 4)
	{
		randomNumber = rand() % 15 + 20;
	}
	else if (gameType == 5)
	{
		randomNumber = rand() % 15 + 35;
	}
	hiddenWord = dictionary.getWord(randomNumber);
	name = "Wordle";
	score = 0;
	lives = 6;
	wrongGuesses = 0;
	for (int i = 0; i < 26; i++)
	{
		usedLetters[i] = false;
	}
	rows = 6;
	columns = 5;
	letters = new Letter * [rows];
	for (int i = 0; i < rows; i++)
	{
		letters[i] = new Letter[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			letters[i][j].setPosition(250 + j * (letters[i][j].getLetterSize() + 5), 125 + i * (letters[i][j].getLetterSize() + 5));
		}
	}
	currentColumn = 0;
	currentRow = 0;
	wrongGuesses = 0;
	winOrLose = 0;
	inputDelay = 0.5;
}

WordleGame::~WordleGame()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] letters[i];
	}
	delete[] letters;

}

void WordleGame::startGame()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			handleInput(event);
		}
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			float elapsedTime = inputDelayClock.getElapsedTime().asSeconds();

			if (elapsedTime > inputDelay) 
			{ 
				int mouseX = sf::Mouse::getPosition(window).x; 
				int mouseY = sf::Mouse::getPosition(window).y; 

				char keyPressed = keyboard.getClickedKey(mouseX, mouseY);

				if (keyPressed != '\0') 
				{ 
					handleVirtualInput(keyPressed); 
				}

				inputDelayClock.restart();
			}
		}
		window.clear(sf::Color::White);
		renderGame();
		window.display();

		if (gameEnd)
		{
			renderGame();
			window.display();
			sf::sleep(sf::seconds(2));
			window.close();
		}

	}
}

void WordleGame::renderGame()
{
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Wordle");
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Black);
	text.setPosition(300, 10);
	window.draw(text);

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			window.draw(letters[i][j].getBox());
			window.draw(letters[i][j].getText());
		}
	}

	for (int i = 0; i < keyboard.getKeysCount(); i++)
	{
		window.draw(keyboard.getKey(i).getBox());
		window.draw(keyboard.getKey(i).getText());
	}
	showScore();

	if (gameType == 1)
	{
		showTime();
	}
	if (gameEnd)
	{
		endGame(winOrLose);
	}
}

void WordleGame::showTime()
{
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");
	sf::Text text;
	text.setFont(font);
	sf::Time elapsed = clock.getElapsedTime();
	sf::Time remaining = oneMinute - elapsed;
	if (remaining.asSeconds() > 0)
	{
		text.setString("Time: " + to_string(static_cast<int>(remaining.asSeconds())));
	}
	else
	{
		text.setString("Time: 0");
	}
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setPosition(10, 10);
	window.draw(text);

	if (remaining.asSeconds() <= 0)
	{
		endGame(2);
	}
}

void WordleGame::handleInput(Event& event)
{
	if (gameEnd)
	{
		return;
	}

	if (event.type == Event::TextEntered)
	{
		char input = tolower(static_cast<char>(event.text.unicode));

		if (input >= 'a' && input <= 'z' && currentColumn < columns)
		{
			letters[currentRow][currentColumn].setValue(input);
			currentColumn++;
		}
		else if (input == '\b' && currentColumn > 0)
		{
			currentColumn--;
			letters[currentRow][currentColumn].setValue(' ');
		}
	}

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
	{
		
		if (currentColumn == columns)
		{
			checkWord();
		}
		sf::sleep(sf::seconds(0.5));
	}
}

void WordleGame::handleVirtualInput(char c)
{
	if (gameEnd)
	{
		return;
	}

	if (c >= 'a' && c <= 'z' && currentColumn < columns)
	{
		letters[currentRow][currentColumn].setValue(c);
		currentColumn++;
	}
	else if (c == ';' && currentColumn > 0)
	{
		currentColumn--;
		letters[currentRow][currentColumn].setValue(' ');
	}

	if (c == ',')
	{
		if (currentColumn == columns)
		{
			checkWord();
		}
	}
}

void WordleGame::checkWord()
{
	keyboard.resetKeys();

	string guess;
	for (int i = 0; i < columns; i++)
	{
		guess += letters[currentRow][i].getValue();
	}

	if (!dictionary.isPresent(guess,gameType))
	{
		return;
	}

	for (int i = 0; i < columns; i++)
	{
		bool correct;
		if (guess[i] == hiddenWord[i])
		{
			correct = true;
		}
		else
		{
			correct = false;
		}

		bool present;
		if (!correct && checkChar(guess[i]))
		{
			present = true;
		}
		else
		{
			present = false;
		}
		letters[currentRow][i].setStatus(correct, present);
		keyboard.updateKeyStatus(guess[i], correct, present);
	}

	if (guess == hiddenWord)
	{
		gameEnd = true;
		score = 12 - wrongGuesses * 2;
		winOrLose = 1;
	}
	else if (currentRow == rows - 1)
	{
		gameEnd = true;
		winOrLose = 2;
	}
	else
	{
		currentRow++;
		wrongGuesses++;
		currentColumn = 0;
	}

}

bool WordleGame::checkChar(char c)
{
	for (int i = 0; i < hiddenWord.length(); i++)
	{
		if (hiddenWord[i] == c)
		{
			return true;
		}
	}
	return false;
}

void WordleGame::endGame(int x)
{
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Black);
	text.setPosition(200, 300);
	if (x == 1)
	{
		text.setString("You Win");
		window.draw(text);
	}
	else if (x == 2)
	{
		text.setString("You Lose");
		window.draw(text);
		sf::Text text2;
		text2.setFont(font);
		text2.setCharacterSize(50);
		text2.setFillColor(sf::Color::Black);
		text2.setPosition(150, 550);
		text2.setString("Word:" + hiddenWord);
		window.draw(text2);
	}

}

void WordleGame::showScore()
{
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Score:" + to_string(score));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setPosition(675, 10);
	window.draw(text);
}

int WordleGame::getScore()
{
	return score;
}