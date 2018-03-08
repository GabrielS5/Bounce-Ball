#include "ScanteiManager.h"


ScanteiManager::ScanteiManager()
{
	count = 0;


}

void ScanteiManager::adaugare(int x,int y)
{
	for (int i = 0; i < 100, i < nrScantei; i++)
	{
		viata[count] = viataScanteie;
		scantei[count] = new Scantei(x, y);
		count++;
	}

}

void ScanteiManager::stergereMorti()
{
	for (int i = count - 1; i >= 0; i--)
	{
		if (viata[i] == 0)
		{
			for (int j = i; j < count - 1; j++)
			{
				scantei[j] = scantei[j + 1];
			}
			count--;

		}

	}
}

void ScanteiManager::miscare()
{
	stergereMorti();
	for (int i = 0; i < count; i++)
	{
		scantei[i]->miscare();
		viata[i] -= 1;
	}
}

void ScanteiManager::draw(sf::RenderWindow *fereastra)
{
	for (int i = 0; i < count; i++)
		scantei[i]->draw(fereastra);
}
