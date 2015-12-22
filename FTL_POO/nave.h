#pragma once
#include "main.h"
#include <vector>

class nave{

	int escudo;
	int nTripulantes;
	std::vector<sala*> vectorSalas;
	std::vector<sala*>::const_iterator it;

public:

	nave();
	~nave();

	sala* getSala(int numero);

	void addSala(sala s, int tipo);

	
	int getTripulantes(){ return nTripulantes; };
	int getEscudo(){ return escudo; };
	
	void setTripulantes(int s) { nTripulantes = s; };
	void setEscudo(int s){ escudo = s; };
};