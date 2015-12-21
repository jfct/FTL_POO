#pragma once

#include "consola.h"
#include "jogo.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

static int tamanhocelula = 8;

int exemplo();
void desenha();
void titulo();
void menu();
void jogo();
void colocaComando(){Consola c; c.gotoxy(20, 33); cout << ">"; };