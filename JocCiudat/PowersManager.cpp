#include "PowersManager.h"
using namespace std;

float distanta(float x, float y, float X, float Y)
{
	return sqrt((x - X)*(x - X) + (y - Y)*(y - Y));
}

PowersManager::PowersManager()
{
	puteri = new Coada<Powers*>(10);
	Cerc = new Coada<sf::CircleShape*>(20);
	existaPutere = 0;
}

void PowersManager::draw(sf::RenderWindow *fereastra)
{
	for (int i = 0; i < Cerc->getCount();i++)
	fereastra->draw(*Cerc->get(i));
}

bool PowersManager::intersectie(Minge minge)
{
	for (int i = Cerc->getCount()-1; i >= 0; i--)
		if (distanta(minge.getX(), minge.getY(), Cerc->get(i)->getPosition().x, Cerc->get(i)->getPosition().y) < Cerc->get(i)->getRadius() + minge.getRaza())
		{
			Cerc->sterge(i);
			return 1;
		}
	return 0;

}

void PowersManager::miscare(Joc &joc)
{
	existaPutere++;
	if (existaPutere == 200)
	{
		Cerc->adauga(new sf::CircleShape);
		Cerc->getNou()->setOrigin(15, 15);
		Cerc->getNou()->setPosition({ (float)(100 + rand() % (LatimeWindow - 200)), (float)(50 + rand() % 200) });
		Cerc->getNou()->setFillColor(sf::Color::Green);
		Cerc->getNou()->setRadius(30);
		existaPutere = 0;
	}

	for (int i = 0; i < puteri->getCount(); i++)
	{
		puteri->get(i)->miscare();
	}
	for (int i = puteri->getCount()-1; i >= 0; i--)
	{
		if (puteri->get(i)->mort(joc))
			puteri->sterge(i);
	}
}

void PowersManager::adaugaPower(Joc &joc,int i)
{
	int g = rand() % 9;
	if (g == 0)
		puteri->adauga(new PowerAdaugare(0,joc));
	if (g == 1)
		puteri->adauga(new PowerAdaugare(0, joc));
	if (g == 2)
		puteri->adauga(new PowerDimensiune(0, joc));
	if (g == 3)
		puteri->adauga(new PowerDimensiune(1, joc));
	if (g == 4)
		puteri->adauga(new PowerAruncare(0, joc));
	if (g == 5)
		puteri->adauga(new PowerAruncare(1, joc));
	if (g == 6)
		puteri->adauga(new PowerFrame(0, joc));
	if (g == 7)
		puteri->adauga(new PowerFrame(1, joc));
	if (g == 8)
		puteri->adauga(new PowerRandomTraj(i, joc));
}