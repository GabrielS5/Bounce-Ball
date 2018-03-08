#pragma once
#include"Biblioteci.h"
#include"Pereche.h"
class Placa
{
private:
	float x, y, unghi;
	sf::RectangleShape bara;
public:
	Pereche baraPuncte[nrSectiuniBara];
	Placa();
	void modificarePozitie(int X, int Y);
	void modificareUnghi(int G);
	float getXdreapta();
	float getYdreapta();
	float getXstanga();
	float getYstanga();
	void updateBaraPuncte();
	void afisareBaraPuncte();
	Pereche getCotaBara();
	void draw(sf::RenderWindow *fereastra);
	float getX();
	float getY();
	int getUnghi();
	void setDimensiune(float d);

};

