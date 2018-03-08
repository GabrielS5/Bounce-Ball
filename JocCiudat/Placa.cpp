#include "Placa.h"
using namespace std;

Placa::Placa()
{
	unghi = 0;
	bara.setOrigin(LatimeBara / 2, 1);
	bara.setSize(sf::Vector2f(LatimeBara, 2));
	bara.setFillColor(sf::Color::White);
	bara.setPosition(200, 200);
	x = y = 200;
}


void Placa::modificarePozitie(int X, int Y)
{
	bara.setPosition(X, Y);
	x = X;
	y = Y;

}

void Placa::modificareUnghi(int G)
{
	if (unghi + G <= 90 && unghi + G >= -90)
	{bara.rotate(G);
	unghi = unghi + G;
}

}

float Placa::getXdreapta()
{
	sf::Transform transform = bara.getTransform();
	sf::FloatRect rect = bara.getLocalBounds();
	sf::Vector2f g;
	g = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top));
	return g.x;
	
}

float Placa::getYdreapta()
{
	sf::Transform transform = bara.getTransform();
	sf::FloatRect rect = bara.getLocalBounds();
	sf::Vector2f g;
	g = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top));
	return g.y;
}

float Placa::getXstanga()
{
	sf::Transform transform = bara.getTransform();
	sf::FloatRect rect = bara.getLocalBounds();
	sf::Vector2f g;
	g = transform.transformPoint(sf::Vector2f(rect.left, rect.top));

	return g.x;

}

float Placa::getYstanga()
{
	sf::Transform transform = bara.getTransform();
	sf::FloatRect rect = bara.getLocalBounds();
	sf::Vector2f g;
	g = transform.transformPoint(sf::Vector2f(rect.left, rect.top));
	return g.y;
}

void Placa::updateBaraPuncte()
{
	float X = (getXdreapta() - getXstanga()) / (nrSectiuniBara-1);
	float Y = (getYdreapta() - getYstanga()) / (nrSectiuniBara - 1);
	for (int i = 0; i < nrSectiuniBara; i++)
	{
		baraPuncte[i].x = getXstanga() + (X*i);
		baraPuncte[i].y = getYstanga() + (Y*i);

	}

}

void Placa::afisareBaraPuncte()
{
	for (int i = 0; i < 20; i++)
	{
		cout<<baraPuncte[i].x<<" "<<baraPuncte[i].y<<endl;

	}
	cout << endl;

}

Pereche Placa::getCotaBara()
{
	Pereche g;
	g.x = (getXdreapta() - getXstanga()) / (nrSectiuniBara - 1);
	g.y = (getYdreapta() - getYstanga()) / (nrSectiuniBara - 1);
	return g;
}

void Placa::draw(sf::RenderWindow *fereastra)
{
	fereastra->draw(bara);
}


float Placa::getX()
{
	return x;
}
float Placa::getY()
{
	return y;
}

int Placa::getUnghi()
{
	return unghi;
}

void Placa::setDimensiune(float d)
{
	
	bara.setSize({ d, 2 });
	bara.setOrigin({ d / 2, 1 });
}