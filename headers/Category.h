#pragma once
#include<iostream>
using namespace std;

class Category
{
	string Words[60];
public:
	Category();
	~Category();
	string getWord(int i);
};

