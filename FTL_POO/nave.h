#pragma once
#include "main.h"
#include <vector>

class nave{

	int escudo;
	int nTripulantes;

	std::vector<unidade*> vectorUnidades;
	std::vector<unidade*>::const_iterator itu;
	
	std::vector<sala*> vectorSalas;
	std::vector<sala*>::const_iterator it;

public:

	nave();
	~nave();

	sala* getSala(int numero);

	void atribuiNumero();
	void addSala(int tipo);
	void addTripulante(int tipo);

	int getNumeroTripulantes(){ return nTripulantes; };
	int getEscudo(){ return escudo; };
	
	void setTamanho(){ vectorSalas.reserve(12); };
	void setTripulantes(int s) { nTripulantes = s; };
	void setEscudo(int s){ escudo = s; };
};