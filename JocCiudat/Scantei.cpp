#include "Scantei.h"
using namespace std;

Scantei::Scantei(int X,int Y)
{
	x = X;
	y = Y;
	if (rand()%2==0)
	vitX = ((float)rand() / (float)RAND_MAX) * 3;
	else
	vitX = -((float)rand() / (float)RAND_MAX) * 3;
	if (rand() % 2 == 0)
		vitY = ((float)rand() / (float)RAND_MAX) * 3;
	else
		vitY = -((float)rand() / (float)RAND_MAX) * 3;
	
	//cout << vitX << " " << vitY << endl;
	corp.setPosition(x, y);
	corp.setFillColor(sf::Color::Yellow);
	corp.setRadius((float)rand() / (float)RAND_MAX*1.2);
}

void Scantei::miscare()
{
	if (vitY < 9)
		vitY += GravitatieScantei;
	x += vitX;
	y += vitY;
	corp.setPosition(x, y);
}

void Scantei::draw(sf::RenderWindow *fereastra)
{
	
	fereastra->draw(corp);
}

