#ifndef Interface_H
#define Interface_H
#pragma once
#include "main.h"
#include <vector> 

class game;

class Interface{
	
	Consola c;

public:

	Interface();
	void limpaEcra();
	void displaysalas();

	int cores(nave* n, int pos);

	void desenhaNave(nave* n);
	void desenhaInformacao(nave* n, game* g);
	void desenhaMenuOpcao(int i);
	void desenhaTripulacao(nave* n);
	void desenhaInimigos(nave* n);
	void desenhaXenomorfos(nave* n);
	void desenhaSala(nave* n);
	void desenhaSalaNumero(std::vector<int> vector);

	int getTipo(int opcao);
	std::string getNome(int id);
	std::string getNomeUnidade(int id);
};
#endif

