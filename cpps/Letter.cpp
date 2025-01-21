#include "Letter.h"

Letter::Letter()
{
	value = ' ';
	isCorrect = false;
	isPresent = false;
	box.setSize(Vector2f(letterSize, letterSize));
	box.setFillColor(Color::White);
	box.setOutlineColor(Color::Black);
	box.setOutlineThickness(2);

	font.loadFromFile("main_menu1.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::Black);
	text.setString(" ");

}

void Letter::setPosition(int x, int y)
{
	box.setPosition(x, y);
	text.setPosition(x + letterSize / 4, y + letterSize / 6);
}

void Letter::setValue(char c)
{
	value = c;
	text.setString(c);
}

void Letter::setStatus(bool correct, bool present)
{
	isCorrect = correct;
	isPresent = present;
	if (isCorrect)
	{
		box.setFillColor(Color::Green);
	}
	else if (isPresent)
	{
		box.setFillColor(Color::Yellow);
	}
	else
	{
		box.setFillColor(Color::Red);
	}
}

void Letter::resetStatus()
{
	box.setFillColor(Color::White);
}

int Letter::getLetterSize()
{
	return letterSize;
}

RectangleShape Letter::getBox()
{
	return box;
}

Text Letter::getText()
{
	return text;
}

char Letter::getValue()
{
	return value;
}