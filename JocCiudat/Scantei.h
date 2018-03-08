#pragma once
#include"Biblioteci.h"
class Scantei
{
private:
	sf::CircleShape corp;
	float x, y, vitX, vitY;
public:
	Scantei(int X,int Y);
	void miscare();
	void draw(sf::RenderWindow *fereastra);

};

