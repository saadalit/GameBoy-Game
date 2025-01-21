#pragma once
#include<iostream>
using namespace std;

class Dictionary
{
	string words[50];
public:
	Dictionary();
	~Dictionary();
	string getWord(int i);
	bool isPresent(string word,int);
};
