#pragma once
#include "main.h"
#include <vector>
#include <string>

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

	std::string nome;

	int saude;
	int sala;
	int tipo;
	// TO-DO
	// Caracteristicas

public:
	unidade();
	~unidade();

	static int id;

	int getId(){ return id; };
	int getSaude(){ return saude; };
	int getSala(){ return sala; };
	int getTipo(){ return tipo; };
	
	void setTipo(int s){ tipo = s; }
	void setId(int s){ id = s; };
	void setSaude(int s){ saude = s; };
	void setSala(int s){ sala = s; };

	std::string getNomeUnidade(){ return nome; };
	void setNomeUnidade(std::string n){ nome = n; };
};

class membro : public unidade{

public:
	membro(int i);
	~membro();
};

class capitao : public unidade{

public:
	capitao(int i);
	~capitao();
};

class robot : public unidade{

public:
	robot(int i);
	~robot();
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