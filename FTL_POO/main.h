#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>


#include "consola.h"
#include "Unidades.h"
#include "sala.h"
#include "nave.h"
#include "Interface.h"
#include "menu.h"
#include "titulo.h"
#include "jogo.h"
#include "Eventos.h"


// TO-DO  parse int, parse string etc..
// TO-DO funcao para dar eventos aleatoriamente

using namespace std;

static int tamanhocelula = 98;

const int DANOPOCOSMICO = 10;
const int SAUDE = 100;
const int INTEGRIDADE = 100;

int exemplo();

void main();