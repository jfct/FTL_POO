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
	unidade* getUnidade(int numero);

	std::vector<unidade*> getVU(){ return vectorUnidades; };

	void atribuiNumero();
	void addSala(int tipo);
	void addUnidade(int tipo, int sala);
	void addNTripulantes(int i){ nTripulantes = i; };

	int getNumeroTripulantes(){ return nTripulantes; };
	int getEscudo(){ return escudo; };
	int getTamanhoVU(){ return vectorUnidades.size(); };


	void setTamanho(){ vectorSalas.reserve(12); };
	void setTripulantes(int s) { nTripulantes = s; };
	void setEscudo(int s){ escudo = s; };
};