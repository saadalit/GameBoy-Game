#include "HangmanGame.h"

HangmanGame::HangmanGame(int z)
{
	gameType = z;
	gameEnd = false;
	if (gameType == 1)
	{
		oneMinute = sf::seconds(60);
	}
	name = "Hangman Game";
	window.create(sf::VideoMode(800, 800), name);
	srand(static_cast<unsigned>(time(0)));
	int randomNumber=0;
	if (gameType == 1 || gameType == 2)
	{
		randomNumber = rand() % 60;
	}
	else if (gameType == 3)
	{
		randomNumber = rand() % 20;
	}
	else if (gameType == 4)
	{
		randomNumber = rand() % 20 + 20;
	}
	else if (gameType == 5)
	{
		randomNumber = rand() % 20 + 40;
	}
	hiddenWord = category.getWord(randomNumber);
	backgroundTexture.loadFromFile("images/hangman(1).png");
	backgroundSprite.setTexture(backgroundTexture);
	name = "Hangman";
	score = 0;
	lives = 6;
	hiddenWordLength = hiddenWord.length();
	wrongGuesses = 0;
	for (int i = 0; i < hiddenWordLength; i++)
	{
		gussedLetters += '-';
	}
	letterFrequency = 0;
	for (int i = 0; i < 26; i++)
	{
		usedLetters[i] = false;
	}
	k = 0;
	pause = false;
	win = 0;

	music1.openFromFile("death-snake.ogg");
	music1.setPosition(0, 0, 0);
	music1.setVolume(100);
	music1.setLoop(0);

	music2.openFromFile("eat-food.ogg");
	music2.setPosition(0, 0, 0);
	music2.setVolume(100);
	music2.setLoop(0);

}

HangmanGame::~HangmanGame()
{
}

void HangmanGame::startGame()
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
			
		}
		checkInput(event);

		window.clear();
		renderGame();
		window.display();

		if (gameEnd)
		{
			renderGame();
			window.display();
			sf::sleep(sf::seconds(2));
			window.close();
		}


		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			pause = true;
			while (pause)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
				{
					pause = false;
				}
			}
		}
		
	}
}

void HangmanGame::renderGame()
{
	window.draw(backgroundSprite);
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Score: " + to_string(score));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setPosition(20, 10);
	window.draw(text);

	text.setString("Lives: " + to_string(lives));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setPosition(600, 10);
	window.draw(text);
	drawHangman();
	checkWin();
	checkLose();
	showWord(k);
	if (gameType == 1)
	{
		showTime();
	}
}

void HangmanGame::checkInput(sf::Event& event)
{
	if (event.type == sf::Event::TextEntered)
	{
		char input = tolower(static_cast<char>(event.text.unicode));

		if (input >= 'a' && input <= 'z')
		{
			if (!usedLetters[input - 'a'])
			{
				usedLetters[input - 'a'] = true;
				checkLetter(input);
			}
		}
	}
}

void HangmanGame::checkWin()
{
	if (gussedLetters == hiddenWord)
	{
		win++;
		if (win==1)
		{
			score += 30;
		}
		endGame(1);
	}
}

void HangmanGame::checkLose()
{
	if (lives == 0)
	{
		endGame(2);
	}
}

void HangmanGame::checkLetter(char letter)
{
	letterFrequency = 0;
	for (int i = 0; i < hiddenWord.length(); i++)
	{
		if (hiddenWord[i] == letter)
		{
			gussedLetters[i] = letter;
			letterFrequency++;
		}
	}
	if (letterFrequency==0)
	{
		lives--;
		wrongGuesses++;
		music1.play();
	}
	else
	{
		score += 5;
		music2.play();
	}
}

void HangmanGame::showWord(int a)
{
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");
	sf::Text text;
	text.setFont(font);
	if (a == 0)
	{
		text.setString(gussedLetters);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Black);
		text.setPosition(330, 700);
	}
	else if (a == 1)
	{
		text.setString("Word:"+hiddenWord);
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Black);
		text.setPosition(150, 700);
	}
	window.draw(text);
}

void HangmanGame::drawHangman()
{
	if (wrongGuesses == 1)
	{
		backgroundTexture.loadFromFile("images/hangman(2).png");
	}
	else if (wrongGuesses == 2)
	{
		backgroundTexture.loadFromFile("images/hangman(3).jpg");
	}
	else if (wrongGuesses == 3)
	{
		backgroundTexture.loadFromFile("images/hangman(4).jpg");
	}
	else if (wrongGuesses == 4)
	{
		backgroundTexture.loadFromFile("images/hangman(5).jpg");
	}
	else if (wrongGuesses == 5)
	{
		backgroundTexture.loadFromFile("images/hangman(6).jpg");
	}
	else if (wrongGuesses == 6)
	{
		backgroundTexture.loadFromFile("images/hangman(7).jpg");
	}

}

void HangmanGame::endGame(int a)
{
	gameEnd = true;
	if (a == 1)
	{
		backgroundTexture.loadFromFile("images/hangmanWin.jpg");
		music3.openFromFile("win-game.ogg");
		music3.setPosition(0, 0, 0);
		music3.setVolume(100);
		music3.setLoop(0);
		music3.play();
	}
	else if (a == 2)
	{
		sf::Font font;
		font.loadFromFile("main_menu1.ttf");
		sf::Text text;
		text.setFont(font);
		text.setString("You Lose");
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Black);
		text.setPosition(250, 350);
		window.draw(text);
		k=1;
		music4.openFromFile("lose-game.ogg");
		music4.setPosition(0, 0, 0);
		music4.setVolume(100);
		music4.setLoop(0);
		music4.play();
	}
}

void HangmanGame::showTime()
{
	sf::Time elapsed = clock.getElapsedTime();
	sf::Time remaining = oneMinute - elapsed;
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");
	sf::Text text;
	text.setFont(font);

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
	text.setPosition(300, 10);
	window.draw(text);

	if (remaining.asSeconds() <= 0)
	{
		endGame(2);
	}
}

int HangmanGame::getScore()
{
	return score;
}
