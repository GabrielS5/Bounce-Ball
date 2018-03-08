#pragma once
#include"Biblioteci.h"
#include"Joc.h"
class Powers
{
private:
		int moarte;
public:
	virtual void miscare()=0;
	virtual bool mort(Joc &joc) = 0;
};

