#pragma once
#include"Biblioteci.h"
#include"Placa.h"
#include"Coada.h"
#include"TextureManager.h"
#include"ScanteiManager.h"
class Minge
{
private:
	float x, y, vitX, vitY;
	sf::CircleShape Bila;
	TextureManager *mngTexturi;
	ScanteiManager *mngScantei;
	Pereche verificari[nrVerificari];
public:
	Coada<Pereche> *coada;
	Minge();
	void inverseazaViteza();

	bool friend intersectie(Minge m, Placa g);
	void miscare();
	void aruncare(Pereche p,float putere);
	void crearePozitiiVerificari(Pereche cota);
	void colturiRealeFigura(sf::Vector2f colturi[4], sf::RectangleShape patrat);
	Pereche calculUnghi(Placa p);
	void modificaPozitie(float x,float y);
	void draw(sf::RenderWindow *fereastra);
	float getX();
	float getY();
	int getRaza();
};

