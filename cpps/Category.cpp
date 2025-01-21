#include "Category.h"

Category::Category()
{
    Words[0] = "lion"; Words[1] = "tiger"; Words[2] = "elephant"; Words[3] = "cheetah"; Words[4] = "giraffe";
    Words[5] = "zebra"; Words[6] = "kangaroo"; Words[7] = "panda"; Words[8] = "bear"; Words[9] = "wolf";
    Words[10] = "fox"; Words[11] = "deer"; Words[12] = "rabbit"; Words[13] = "horse"; Words[14] = "monkey";
    Words[15] = "penguin"; Words[16] = "dolphin"; Words[17] = "whale"; Words[18] = "eagle"; Words[19] = "owl";

    Words[20] = "pakistan"; Words[21] = "india"; Words[22] = "china"; Words[23] = "usa"; Words[24] = "canada";
    Words[25] = "nigeria"; Words[26] = "germany"; Words[27] = "france"; Words[28] = "italy"; Words[29] = "brazil";
    Words[30] = "chile"; Words[31] = "japan"; Words[32] = "russia"; Words[33] = "uae"; Words[34] = "uk";
    Words[35] = "spain"; Words[36] = "mexico"; Words[37] = "egypt"; Words[38] = "turkey"; Words[39] = "morocoo";

    Words[40] = "apple"; Words[41] = "microsoft"; Words[42] = "google"; Words[43] = "amazon"; Words[44] = "samsung";
    Words[45] = "toyota"; Words[46] = "cocacola"; Words[47] = "pepsi"; Words[48] = "nike"; Words[49] = "adidas";
    Words[50] = "sony"; Words[51] = "intel"; Words[52] = "dell"; Words[53] = "hp"; Words[54] = "bmw";
    Words[55] = "mercedes"; Words[56] = "tesla"; Words[57] = "lexus"; Words[58] = "huawei"; Words[59] = "nestle";
}

Category::~Category()
{
}

string Category::getWord(int i)
{
	if (i < 0 || i>59)
	{
		return "Invalid Index";
	}
    else
    {
        return Words[i];
    }
}