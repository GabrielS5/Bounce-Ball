#pragma once
#include "Powers.h"
#include"Joc.h"
class PowerDimensiune :
	public Powers
{
private:
	int moarte, optiune;
public:
	PowerDimensiune(int Optiune, Joc &joc);
	void miscare();
	bool mort(Joc &joc);

};

