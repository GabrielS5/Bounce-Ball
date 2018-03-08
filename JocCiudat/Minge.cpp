#include "Minge.h"
using namespace std;

bool egal(float a, float b)
{
	return a <= b + b / 500 && a >= b - b / 500;
}


float Distanta(float x, float y, float X, float Y)
{
	return sqrt((x - X)*(x - X) + (y - Y)*(y - Y));
}

float arieDreptunghi(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d)
{
	return Distanta(a.x, a.y, b.x, b.y)*Distanta(a.x, a.y, c.x, c.y);

}

float arieTriunghi(sf::Vector2f a, sf::Vector2f b, Pereche c)
{
	return abs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2);
}

Minge::Minge()
{
	coada = new Coada<Pereche>(marimeCoada);
	vitX = vitY = 0;
	y = 0;
	x = LatimeWindow / 2;
	Bila.setRadius(RazaCerc);
	Bila.setPointCount(100);
	Bila.setOrigin(RazaCerc / 2, RazaCerc / 2);
	Bila.setPosition(x, y);
	mngTexturi = new TextureManager(8, &Bila,0);
	mngTexturi->incarcareTexturi();
	mngScantei = new ScanteiManager();
}

bool intersectie(Minge m, Placa g)
{
	if (Distanta(m.getX(), m.getY(), g.getX(), g.getY()) <= LatimeBara + RazaCerc)
	{
		g.updateBaraPuncte();
		for (int i = 0; i < nrSectiuniBara; i++)
		{
			if (Distanta(m.x, m.y, g.baraPuncte[i].x, g.baraPuncte[i].y) < RazaCerc)
				return 1;
		}
	}
	return 0;
}

void Minge::miscare()
{
	if (vitY < 9)
		vitY += Gravitatie;
	x += vitX;
	y += vitY;
	Pereche p = { x, y };
	coada->adauga(p);
	Bila.setPosition(x, y);
	mngTexturi->setViteza(abs(vitX) + abs(vitY));
	mngTexturi->aplicaTextura(vitX);
	mngScantei->miscare();

}

void Minge::aruncare(Pereche p,float putere)
{
	mngScantei->adaugare(x, y);
	float adaugareX=(x-p.x)/40,adaugareY=(y-p.y)/40;

	while (Distanta(x, y, p.x, p.y) < DistantaAruncare - 10 || Distanta(x, y, p.x, p.y) > DistantaAruncare + 10)
	{
		if (Distanta(x, y, p.x, p.y) > DistantaAruncare + 10)
		{
			p.x = p.x + adaugareX;
			p.y = p.y + adaugareY;
        }
		else
		{
			p.x = p.x - adaugareX;
			p.y = p.y - adaugareY;
		}

	}
	vitX = -(x - p.x) / (putere);
	vitY = -(y - p.y) / (putere);
}

void Minge::crearePozitiiVerificari(Pereche cota)
{
	verificari[nrVerificari / 2] = { x, y };
	for (int i = 1; i <= nrVerificari / 2; i++)
	{
		verificari[nrVerificari / 2 - i] = { x - cota.x*i, y - cota.y*i };
		verificari[nrVerificari / 2 + i] = { x + cota.x*i, y + cota.y*i };

	}
}

void Minge::colturiRealeFigura(sf::Vector2f colturi[4],sf::RectangleShape patrat)
{
	sf::Transform transform = patrat.getTransform();
	sf::FloatRect rect = patrat.getLocalBounds();

	colturi[0] = transform.transformPoint(sf::Vector2f(rect.left, rect.top));
	colturi[1] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top));
	colturi[2] = transform.transformPoint(sf::Vector2f(rect.left + rect.width, rect.top + rect.height));
	colturi[3] = transform.transformPoint(sf::Vector2f(rect.left, rect.top + rect.height));

}

Pereche Minge::calculUnghi(Placa p)
{
	Pereche cota = p.getCotaBara();
	float arD, arT;
	crearePozitiiVerificari(cota);

	sf::RectangleShape patrat;
	patrat.setSize(sf::Vector2f(6, 300));
	patrat.setOrigin(3, 300);
	patrat.rotate(p.getUnghi());
	sf::Vector2f colturi[4];

	for (int i = 0; i < nrVerificari; i++)
	{
		patrat.setPosition(verificari[i].x, verificari[i].y);
		colturiRealeFigura(colturi, patrat);
		
		arD= arieDreptunghi(colturi[0], colturi[1], colturi[3], colturi[2]);
		arT = arieTriunghi(colturi[0], colturi[1], coada->getVechi()) + arieTriunghi(colturi[1], colturi[2], coada->getVechi()) + arieTriunghi(colturi[2], colturi[3], coada->getVechi()) + arieTriunghi(colturi[3], colturi[0], coada->getVechi());
		
		if (egal(arD, arT))
		{
			

			int j = 0;
			while (egal(arD, arT))
			{
				j++;
				patrat.setSize(sf::Vector2f(6, 300 - j));

				colturiRealeFigura(colturi, patrat);
				
				arD = arieDreptunghi(colturi[0], colturi[1], colturi[3], colturi[2]);
				arT = arieTriunghi(colturi[0], colturi[1], coada->getVechi()) + arieTriunghi(colturi[1], colturi[2], coada->getVechi()) + arieTriunghi(colturi[2], colturi[3], coada->getVechi()) + arieTriunghi(colturi[3], colturi[0], coada->getVechi());
			}
			int nr;
			if (i > nrVerificari / 2)
			{
				nr = nrVerificari / 2 - (i - nrVerificari / 2);
			}
			else
			{
				nr = nrVerificari / 2 + (nrVerificari / 2 - i);
			}
			
			sf::RectangleShape rasp;
			rasp.setOrigin(3, 300);
			rasp.setSize(sf::Vector2f(6, 300 - j));
			rasp.rotate(p.getUnghi());
			rasp.setPosition(verificari[nr].x, verificari[nr].y);

			colturiRealeFigura(colturi, rasp);
			Pereche raspuns = { (colturi[3].x+colturi[2].x)/2, (colturi[3].y+colturi[2].y)/2 };
			return raspuns;

		}
	}
	return{ LatimeWindow/2, InaltimeWindow };
}

void Minge::modificaPozitie(float X, float Y)
{
	x = X;
	y = Y;
}

void Minge::draw(sf::RenderWindow *fereastra)
{
	mngScantei->draw(fereastra);
	fereastra->draw(Bila);
}

float Minge::getX()
{
	return x;
}
float Minge::getY()
{
	return y;
}

int Minge::getRaza()
{
	return Bila.getRadius();
}

void Minge::inverseazaViteza()
{
	vitX = -vitX;
}