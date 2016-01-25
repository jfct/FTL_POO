#ifndef Jogo_H
#define Jogo_H
#pragma once
#include "main.h"
#include <vector>
#include <string>


class Interface;
class sala;

nave* inicioJogo();

void jogo();
void opcoes();

class game{
	int tick;
	int objectivo;

	nave* n;

public:
	nave* getNave(){ return this->n; };
	void setNave(nave* n){ this->n = n; };

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
void addAdjacente(nave* n, int sala);
void moveUnidade(nave* n, std::vector<sala*> vs, sala* salaActual, int destino, int posicao);
void moveXenomorfo(nave* n, std::vector<sala*> vs, sala* salaActual, int destino, int posicao);
void moveInimigo(nave* n, std::vector<sala*> vs, sala* salaActual, int destino, int posicao);

// Devolve 1 se de facto houver final de jogo
int verificaFinal(nave* n);
int ordens(nave* n);
int verficaPropulsao(nave* n);
int getTipo(int opcao);
int pertence(sala*, int i);

void inicioTurno(nave* n);
// 0 = nao há fim
// 1 = Vitoria
// 2 = Derrota
int fimTurno(game* g, nave* n);

#endif