#include "Keyboard1.h"

Keyboard1::Keyboard1(float startX, float startY)
{
    float x = startX;
    float y = startY;
    int keysPerRow[3];
    keysPerRow[0] = 11;
    keysPerRow[1] = 10;
    keysPerRow[2] = 7;

    int keyIndex = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int i = 0; i < keysPerRow[row]; i++)
        {
            if (keyIndex >= 28)
            {
                break;
            }
            keys[keyCount].setPosition(x, y);
            keys[keyCount].setValue(keyLayout[keyIndex]);
            keyIndex++;
            keyCount++;
            x += keys->getLetterSize() + 5;
        }
        y += keys->getLetterSize() + 10;
        x = startX + (row + 1) * 20; 
    }
}

int Keyboard1::getKeysCount()
{
    return keyCount;
}

Letter Keyboard1::getKey(int i)
{
    return keys[i];
}

char Keyboard1::getClickedKey(int mouseX, int mouseY)
{
    for (int i = 0; i < 28; i++) 
    {
        sf::FloatRect bounds = keys[i].getBox().getGlobalBounds();
        if (mouseX >= bounds.left && mouseX <= bounds.left + bounds.width &&
            mouseY >= bounds.top && mouseY <= bounds.top + bounds.height) 
        {
			cout << keys[i].getValue() << endl;
            return keys[i].getValue();
        }
    }
    return '\0'; 
}

void Keyboard1::updateKeyStatus(char key, bool correct, bool present) 
{
    for (int i = 0; i < keyCount; i++) 
    { 
        if (keys[i].getValue() == key) 
        {
            keys[i].setStatus(correct, present);
            break;
        }
    }
}

void Keyboard1::resetKeys()
{
	for (int i = 0; i < keyCount; i++)
	{
		keys[i].resetStatus();
	}
}
