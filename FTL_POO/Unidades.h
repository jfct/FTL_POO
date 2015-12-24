#pragma once
#include "main.h"
#include <vector>

// Unidade normal

const int MEMBRO = 800;
const int CAPITAO = 801;
const int ROBOT = 802;
const int PIRATA = 803;
const int GEIGERMORFO = 804;
const int CASULO = 805;
const int BLOBE = 806;
const int MXYZYPYKWI = 807;

class unidade{

	int id;
	int saude;
	int sala;
	// TO-DO
	// Caracteristicas

public:
	unidade();
	~unidade();

	int getId(){ return id; };
	int getSaude(){ return saude; };
	int getSala(){ return sala; };

	void setId(int s){ id = s; };
	void setSaude(int s){ saude = s; };
	void setSala(int s){ sala = s; };
};

class membro : public unidade{
public:
	membro();
	~membro();
};

// Xenomorfos

class geigermorfo : public unidade{
public:
	geigermorfo();
	~geigermorfo();
};

class casulo : public unidade{
public:
	casulo();
	~casulo();
};

class blob : public unidade{
public:
	blob();
	~blob();
};

class mxyzypykwi : public unidade{
public:
	mxyzypykwi();
	~mxyzypykwi();
};