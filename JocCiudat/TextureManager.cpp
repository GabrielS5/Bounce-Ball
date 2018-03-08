#include "TextureManager.h"
using namespace std;

TextureManager::TextureManager(int CountMax, sf::CircleShape *Cerc,int Viteza)
{
	aplicabilitate = 1;
	viteza = Viteza;
	countMax = CountMax;
	count = 0;
	cerc = Cerc;
	incarcareTexturi();
}

void TextureManager::incarcareTexturi()
{
	texturi[0].loadFromFile("Texturi\\0.jpg");
	texturi[1].loadFromFile("Texturi\\1.jpg");
	texturi[2].loadFromFile("Texturi\\2.jpg");
	texturi[3].loadFromFile("Texturi\\3.jpg");
	texturi[4].loadFromFile("Texturi\\4.jpg");
	texturi[5].loadFromFile("Texturi\\5.jpg");
	texturi[6].loadFromFile("Texturi\\6.jpg");
	texturi[7].loadFromFile("Texturi\\7.jpg");
}

void TextureManager::aplicaTextura(float X)
{
if (aplicabilitate >= viteza)
	{
		if (X >= 0)
		{
			count++;
			if (count == countMax)
				count = 0;
		}
		else
		{
			count--;
			if (count == -1)
				count = countMax - 1;
		}
		cerc->setTexture(&texturi[count]);
		aplicabilitate = 1;
		
	}
	else
	{
		aplicabilitate++;
	}
	}

void TextureManager::setViteza(int Viteza)
{
	if (Viteza > 8)
		viteza = 2;
	else
	viteza = 10-Viteza;
}