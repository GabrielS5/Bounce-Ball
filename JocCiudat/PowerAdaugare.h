#pragma once
#include "Powers.h"
#include"Joc.h"
class PowerAdaugare :
	public Powers
{
private:
	int moarte, optiune;
public:
	PowerAdaugare(int Optiune, Joc &joc);
	void miscare();
	bool mort(Joc &joc);

};

