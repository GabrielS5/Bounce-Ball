#pragma once
#include"Biblioteci.h"
#include"Placa.h"
#include"Minge.h"
#include"Coada.h"
struct Joc{
	Placa placa;
	Coada<Minge*> mingi;
	float coeficientAruncareP, coeficientAruncareM;
	int coeficientFrameP, coeficientFrameM;
	int scor;
};