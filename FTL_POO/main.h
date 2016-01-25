#ifndef Main_H
#define Main_H
#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <ctime>

#include "consola.h"
#include "nave.h"
#include "Unidades.h"
#include "sala.h"
#include "Interface.h"
#include "menu.h"
#include "titulo.h"
#include "jogo.h"
#include "Eventos.h"
#include "Caracteristicas.h"

using namespace std;

static int tamanhocelula = 98;

const int DANOPOCOSMICO = 10;
const int SAUDE = 100;
const int INTEGRIDADE = 100;

const int INDECISO = 500;
const int OPERADOR = 501;

// Estados de sala
const int FOGO = 500;
const int BRECHA = 501;
const int CURTOCIRCUITO = 502;

int exemplo();
void colocaMensagem(string mensagem, int linha);
void main();

#endif