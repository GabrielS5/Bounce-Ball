#pragma once
#include "Powers.h"
class PowerRandomTraj :
	public Powers
{
public:
	PowerRandomTraj(int i, Joc &joc);
	void miscare();
	bool mort(Joc &joc);
	
};

