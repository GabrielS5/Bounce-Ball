#pragma once
#include "Powers.h"
#include"Joc.h"
class PowerFrame :
	public Powers
{
private:
	int moarte,optiune;
public:
	PowerFrame(int Optiune, Joc &joc);
	void miscare();
	bool mort(Joc &joc);
	
	
};

