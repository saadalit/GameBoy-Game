#pragma once
#include"Player.h"
#include <SFML/Graphics.hpp>
#include<fstream>
#include <iostream>
using namespace std;
using namespace sf;

class Leaderboard1 
{
private:
    int highScores[10];     
    Player* topTen[10];    
    Text text;

public:
    Leaderboard1();
    ~Leaderboard1();
    void updateScore(Player* player, int score, int index);
    void displayTopScores();
    void saveLeaderboard(int k);
    void loadLeaderboard(int k);
};
