#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class AchievementSystem
{
	string achievements[10];
	string progress;
public:
	AchievementSystem();
	~AchievementSystem();
	void trackAchievement(string achievement);
	void updateProgress();

};