#pragma once
#include"Biblioteci.h"
#include"Scantei.h"

class ScanteiManager
{
private:
	Scantei *scantei[100];
	int viata[100],count;

public:
	ScanteiManager();
	void adaugare(int x,int y);
	void miscare();
	void draw(sf::RenderWindow *fereastra);
	void stergereMorti();
	
};

