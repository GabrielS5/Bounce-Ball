#pragma once
#include"Biblioteci.h"
#include"Powers.h"
#include "PowerFrame.h"
#include "PowerDimensiune.h"
#include "PowerAruncare.h"
#include "PowerAdaugare.h"
#include "PowerRandomTraj.h"
#include"Joc.h"
class PowersManager
{
public:
	Coada <Powers*>*puteri;
	PowersManager();
	Coada <sf::CircleShape*> *Cerc;
	void draw(sf::RenderWindow *fereastra);
	bool intersectie(Minge minge);
	void miscare(Joc &joc);
	void adaugaPower(Joc &joc,int i);
	int existaPutere;
};

