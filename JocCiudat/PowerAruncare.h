#pragma once
#include"Joc.h"
#include "Powers.h"
class PowerAruncare :
	public Powers
{
private:
	int moarte,optiune;
public:
	PowerAruncare(int Optiune, Joc &joc);
	void miscare();
	bool mort(Joc &joc);
};

