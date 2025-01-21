#include "Dictionary.h"

Dictionary::Dictionary()
{
	words[0] = "tiger";
	words[1] = "horse";
	words[2] = "zebra";
	words[3] = "koala";
	words[4] = "lemur";
	words[5] = "panda";
	words[6] = "goose";
	words[7] = "whale";
	words[8] = "otter";
	words[9] = "skunk";
	words[10] = "moose";
	words[11] = "camel";
	words[12] = "shark";
	words[13] = "eagle";
	words[14] = "rhino";
	words[15] = "sheep";
	words[16] = "snake";
	words[17] = "mouse";
	words[18] = "bison";
	words[19] = "sloth";

	words[20] = "japan";
	words[21] = "italy";
	words[22] = "chile";
	words[23] = "kenya";
	words[24] = "nepal";
	words[25] = "qatar";
	words[26] = "india";
	words[27] = "spain";
	words[28] = "egypt";
	words[29] = "ghana";
	words[30] = "yemen";
	words[31] = "sudan";
	words[32] = "syria";
	words[33] = "niger";
	words[34] = "malta";

	words[35] = "apple";
	words[36] = "lexus";
	words[37] = "pepsi";
	words[38] = "rolex";
	words[39] = "honda";
	words[40] = "gucci";
	words[41] = "canon";
	words[42] = "tesla";
	words[43] = "prada";
	words[44] = "adobe";
	words[45] = "nokia";
	words[46] = "intel";
	words[47] = "fedex";
	words[48] = "prime";
	words[49] = "volvo";
}

Dictionary::~Dictionary()
{
}

string Dictionary::getWord(int i)
{
	if (i < 0 || i>49)
	{
		return "Invalid Index";
	}
	else
	{
		return words[i];
	}
}

bool Dictionary::isPresent(string word,int gameType)
{
	if (gameType == 1 || gameType == 2)
	{
		for (int i = 0; i < 50; i++)
		{
			if (words[i] == word)
			{
				return true;
			}
		}
	}
	else if (gameType == 3)
	{

		for (int i = 0; i < 20; i++)
		{
			if (words[i] == word)
			{
				return true;
			}
		}

	}
	else if (gameType == 4)
	{
		for (int i = 20; i < 35; i++)
		{
			if (words[i] == word)
			{
				return true;
			}
		}
	}
	else if (gameType == 5)
	{
		for (int i = 35; i < 50; i++)
		{
			if (words[i] == word)
			{
				return true;
			}
		}
	}
	return false;
}