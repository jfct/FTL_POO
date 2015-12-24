#pragma once
#include "main.h"

void jogo();
void inicializarNave(nave* n, Consola c);
void inicializarTripulacao(nave* n, Consola c);
void addSalaTipo(nave* n, int opcao);

int getTipo(int opcao);