#pragma once
#include"Biblioteci.h"
class TextureManager
{
private:
	int countMax,count,viteza,aplicabilitate;
	sf::Texture texturi[20];
	sf::CircleShape *cerc;
public:
	TextureManager(int CountMax,sf::CircleShape *Cerc,int Viteza);
	void incarcareTexturi();
	void aplicaTextura(float X);
	void setViteza(int Viteza);
	
};

