#include "Biblioteci.h"
#include"Joc.h"
#include"PowersManager.h"
using namespace std;

int main(){
	srand(time(NULL));
	float fpsIncrement = 0;
	Joc joc = { Placa(), Coada<Minge*>(100) };
	joc.mingi.adauga(new Minge());
	PowersManager Power;
	sf::RenderWindow window(sf::VideoMode(LatimeWindow, InaltimeWindow), "Joc Ciudat");
	window.setFramerateLimit(60);
	while (window.isOpen()){
		if (fpsIncrement<=40)
		fpsIncrement = fpsIncrement + 0.01;
		window.setFramerateLimit(60 - joc.coeficientFrameM + joc.coeficientFrameP+fpsIncrement);
		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		joc.placa.modificarePozitie(sf::Mouse::getPosition(window).x, 400);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			joc.placa.modificareUnghi(saltUnghi);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			joc.placa.modificareUnghi(-saltUnghi);

		window.clear();
		Power.miscare(joc);
		for (int i = 0; i < joc.mingi.getCount(); i++)
		{
			joc.mingi.get(i)->miscare();
			
			if (intersectie(*joc.mingi.get(i), joc.placa))
			{
				Pereche Traiectorie = joc.mingi.get(i)->calculUnghi(joc.placa);
				joc.mingi.get(i)->aruncare(Traiectorie, putereAruncare - joc.coeficientAruncareP + joc.coeficientAruncareM);
			}
			
			joc.mingi.get(i)->draw(&window);
			
			if (joc.mingi.get(i)->getY() > InaltimeWindow)
				joc.mingi.sterge(i);
			
			if (Power.intersectie(*joc.mingi.get(i)))
				Power.adaugaPower(joc,i);

			if ((joc.mingi.get(i)->coada->get(1).x<LatimeWindow / 2 && joc.mingi.get(i)->coada->get(0).x>LatimeWindow / 2) || (joc.mingi.get(i)->coada->get(1).x>LatimeWindow / 2 && joc.mingi.get(i)->coada->get(0).x<LatimeWindow / 2))
			{
				joc.scor++;
							}
			/*if (joc.mingi.get(i)->getX() <= 0 || joc.mingi.get(i)->getX() >= LatimeWindow)
				joc.mingi.get(i)->inverseazaViteza();*/
		}

		joc.placa.draw(&window);
		Power.draw(&window);
		window.display();

		if (joc.mingi.getCount()==0)
		window.close();


	}
	cout << "Scorul tau este "<<joc.scor<<endl;
	int g;
	cin>>g;

}