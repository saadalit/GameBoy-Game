#include"Player.h"

Player::Player()
{
	name = "\0";
	for (int i = 0; i < 3; i++)
	{
		highScores[i] = 0;
		achievements[i] = "\0";
	}
}

Player::~Player()
{
}

void Player::setName(string name)
{
	this->name = name;
}

string Player::getName()
{
	return name;
}

void Player::setHighScore(int score, int index)
{
	if (score > highScores[index])
	{
		highScores[index] = score;
	}
}

void Player::saveProgress(int score, string achievement)
{
	for (int i = 0; i < 3; i++)
	{
		if (score > highScores[i])
		{
			for (int j = 2; j > i; j--)
			{
				highScores[j] = highScores[j - 1];
				achievements[j] = achievements[j - 1];
			}
			highScores[i] = score;
			achievements[i] = achievement;
			break;
		}
	}
}

void Player::loadProgress()
{
	/*ifstream file;
	file.open("progress.txt");
	file >> name;
	file.close();*/
}

int Player::getHighScore(int index)
{
	return highScores[index];
}