#include"Leaderboard.h"


Leaderboard1::Leaderboard1()
{
	for (int i = 0; i < 10; ++i)
	{
		highScores[i] = 0;
		topTen[i] = nullptr;
	}
}

Leaderboard1::~Leaderboard1()
{
	for (int i = 0; i < 10; ++i) 
	{
		delete topTen[i];
	}
}

void Leaderboard1::updateScore(Player* player, int score, int index)
{
	for (int i = 0; i < 10; ++i)
	{
		if (topTen[i] && topTen[i]->getName() == player->getName())
		{
			if (score > highScores[i])
			{
				for (int j = i; j < 9; ++j)
				{
					highScores[j] = highScores[j + 1];
					topTen[j] = topTen[j + 1];
				}
				highScores[9] = 0;
				topTen[9] = nullptr;
			}
			else
			{
				return;
			}
			break;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		if (score > highScores[i])
		{
			for (int j = 9; j > i; --j)
			{
				highScores[j] = highScores[j - 1];
				topTen[j] = topTen[j - 1];
			}
			highScores[i] = score;
			topTen[i] = new Player();
			topTen[i]->setName(player->getName());
			topTen[i]->setHighScore(score, index);
			break;
		}
	}

}



void Leaderboard1::displayTopScores()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Leaderboard");
	sf::Font font;
	font.loadFromFile("main_menu1.ttf");

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("images/leaderboard.png");
	sf::Sprite background(backgroundTexture);

	sf::Texture gold;
	gold.loadFromFile("images/gold.png");
	sf::Sprite golds(gold);
	golds.setPosition(650, 90);

	sf::Texture silver;
	silver.loadFromFile("images/silver.png");
	sf::Sprite silver2(silver);
	silver2.setPosition(660, 180);

	sf::Texture bronze;
	bronze.loadFromFile("images/bronze.png");
	sf::Sprite bronze2(bronze);
	bronze2.setPosition(640, 245);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}
		window.clear();
		window.draw(background);
		window.draw(golds);
		window.draw(silver2);
		window.draw(bronze2);
		text.setFont(font);
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::White);
		text.setPosition(50, 50);
		text.setString("Leaderboard");
		window.draw(text);
		for (int i = 0; i < 10; ++i)
		{
			text.setFont(font);
			text.setCharacterSize(40);
			text.setFillColor(sf::Color::White);
			text.setPosition(50, 50 + (i+1) * 70);
			if (topTen[i])
			{
				text.setString(std::to_string(i + 1) + ". " + topTen[i]->getName() + " - " + std::to_string(highScores[i]));
			}
			else
			{
				text.setString(std::to_string(i + 1) + ". ---");
			}
			window.draw(text);
		}
		window.display();
	}
}




void Leaderboard1::saveLeaderboard(int k)
{
	string filename;
	if(k==0)
	{
		filename = "SnakeGameLeaderboard.txt";
	}
	else if (k == 1)
	{
		filename = "WordleLeaderboard.txt";
	}
	else if (k == 2)
	{
		filename = "HangmanLeaderboard.txt";
	}
	ofstream file(filename);
	if (file.is_open()) 
	{
		for (int i = 0; i < 10; ++i) 
		{
			if (topTen[i]) 
			{
				file << topTen[i]->getName() << " " << highScores[i] << "\n";
			}
		}
		file.close();
		cout << "Leaderboard saved successfully.\n";
	}
	else 
	{
		cerr << "Error saving leaderboard.\n";
	}
}

void Leaderboard1::loadLeaderboard(int k)
{
	string filename;
	if (k == 0)
	{
		filename = "SnakeGameLeaderboard.txt";
	}
	else if (k == 1)
	{
		filename = "WordleLeaderboard.txt";
	}
	else if (k == 2)
	{
		filename = "HangmanLeaderboard.txt";
	}
	ifstream file(filename);
	if (file.is_open()) 
	{
		string playerName;
		int score;
		int index = 0;

		while (file >> playerName >> score && index < 10) 
		{
			topTen[index] = new Player();
			topTen[index]->setName(playerName);
			topTen[index]->setHighScore(score, k);
			highScores[index] = score;
			++index;
		}

		file.close();
		cout << "Leaderboard loaded successfully.\n";
	}
	else 
	{
		cerr << "Error loading leaderboard.\n";
	}
}