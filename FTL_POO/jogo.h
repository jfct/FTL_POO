#pragma once
#include "main.h"

class game{
	int tick;
public:
	void setTick(int s){ tick = s; };
	int getTick(){ return tick; };
};

nave* inicioJogo();
void jogo();
void inicializarNave(nave* n, Consola c);
void inicializarTripulacao(nave* n, Consola c);
void addSalaTipo(nave* n, int opcao);
void ordens(nave* n);

int getTipo(int opcao);