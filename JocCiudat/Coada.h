#pragma once
#include"Biblioteci.h"
template <class T>
class Coada
{
private:
	T elemente[200];
	int count;
	int countMax;
public:
	Coada(int nr)
	{
		count = 0;
		countMax=nr;
	}
	void adauga(T element)
	{
		if (count < countMax)
			count++;
		T aux1 = elemente[0], aux2;
		elemente[0] = element;
		for (int i = 1; i < countMax; i++)
		{
			aux2 = elemente[i];
			elemente[i] = aux1;
			aux1 = aux2;
		}
	}

	T getVechi()
	{
		return elemente[count-1];
	}
	T getNou()
	{
		return elemente[0];
	}
	T get(int pozitie)
	{
		return elemente[pozitie];
	}
	int getCount()
	{
		return count;
	}
	void sterge(int poz)
	{
	
		for (int i = count - 1; i > poz; i--)
		{
			memcpy(&elemente[i - 1], &elemente[i], sizeof(elemente[0]));
		}
		count--;
	}
};

