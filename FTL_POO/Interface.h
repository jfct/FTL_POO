#pragma once
#include "main.h"
#include <vector> 

class Interface{
	
	Consola c;

public:

	Interface();
	void limpaEcra();
	void displaysalas();

	void desenhaNave();
	void desenhaInformacao();
	void desenhaMenuOpcao(int i);
	void desenhaTripulacao(nave* n);
	void desenhaSala(nave* n);
	void desenhaSalaNumero(std::vector<int> vector);

	int getTipo(int opcao);
	std::string getNome(int id);
};

