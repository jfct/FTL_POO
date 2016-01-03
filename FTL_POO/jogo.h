#ifndef Jogo_H
#define Jogo_H
#pragma once
#include "main.h"



class Interface;

nave* inicioJogo();

void jogo();
void opcoes();


class game{
	int tick;
	int objectivo;

public:
	void setTick(int s){ tick = s; };
	void setObjectivo(int s){ objectivo = s; };

	int getObjectivo(){ return objectivo; };
	int getTick(){ return tick; };
};

void randomEvents(game* g, nave* n, Interface in, Consola c);
int numeroAleatorio1(int min, int max);

void inicializarNave(nave* n, Consola c);
void inicializarTripulacao(nave* n, Consola c);
void addSalaTipo(nave* n, int opcao);

int ordens(nave* n);
int verficaPropulsao(nave* n);
int getTipo(int opcao);

boolean fimTurno(game* g, nave* n);


#endif