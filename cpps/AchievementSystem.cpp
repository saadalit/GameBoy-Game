#include"AchievementSystem.h"

AchievementSystem::AchievementSystem()
{
	for (int i = 0; i < 10; i++)
	{
		achievements[i] = "\0";
	}
	progress = "\0";
}

AchievementSystem::~AchievementSystem()
{
}

void AchievementSystem::trackAchievement(string achievement)
{
	for (int i = 0; i < 10; i++)
	{
		if (achievements[i] == "\0")
		{
			achievements[i] = achievement;
			break;
		}
	}
}

void AchievementSystem::updateProgress()
{
	progress = "\0";
	for (int i = 0; i < 10; i++)
	{
		if (achievements[i] != "\0")
		{
			progress += achievements[i] + "\n";
		}
	}
}