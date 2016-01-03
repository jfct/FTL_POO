#ifndef Unidades_H
#define Unidades_H

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

	int respira=0;
	int flamejante = 0;
	int toxico = 0;
	int indeciso = 0;
	int misterioso = 0;
	int regenerador = 0;
	int exoesqueleto = 0;
	int robotico = 0;
	int reparador = 0;
	int combatente = 0;
	int xenomorfo = 0;
	int casulo = 0;
	int mutatis = 0;
	int hipnotizador = 0;
	int operador = 0;
	int tripulacao = 0;
	int inimigo = 0;
	int inimigoSala = 0;
	int move = 0;
	int armado = 0;

public:
	unidade();
	~unidade();

	static int id;

	int getRespira() { return this->respira; }
	int getFlamejante() { return this->flamejante; }
	int getToxico() { return this->toxico; }
	int getIndeciso() { return this->indeciso; }
	int getMisterioso() { return this->misterioso; }
	int getRegenerador() { return this->regenerador; }
	int getExoesqueleto() { return this->exoesqueleto; }
	int getRobotico() { return this->robotico; }
	int getReparador() { return this->reparador; }
	int getCombatente() { return this->combatente; }
	int getXenomorfo() { return this->xenomorfo; }
	int getCasulo() { return this->casulo; }
	int getMutatis() { return this->mutatis; }
	int getHipnotizador() { return this->hipnotizador; }
	int getOperador() { return this->operador; }
	int getTripulacao() { return this->tripulacao; }
	int getInimigo() { return this->inimigo; }
	int getInimigoSala() { return this->inimigoSala; }
	int getMove() { return this->move; }
	int getArmado() { return this->armado; }
	int getId(){ return id; };
	int getSaude(){ return saude; };
	int getSala(){ return sala; };
	int getTipo(){ return tipo; };

	
	void setMove(int move) { this->move = move; }
	void setArmado(int armado) { this->armado = armado; }
	void setTipo(int s){ tipo = s; }
	void setId(int s){ id = s; };
	void setSaude(int s){ saude = s; };
	void setSala(int s){ sala = s; };
	void setRespira(int respira) { this->respira = respira; }
	void setFlamejante(int flamejante) { this->flamejante = flamejante; }
	void setToxico(int toxico) { this->toxico = toxico; }
	void setIndeciso(int indeciso) { this->indeciso = indeciso; }
	void setMisterioso(int misterioso) { this->misterioso = misterioso; }
	void setRegenerador(int regenerador) { this->regenerador = regenerador; }
	void setExoesqueleto(int exoesqueleto) { this->exoesqueleto = exoesqueleto; }
	void setRobotico(int robotico) { this->robotico = robotico; }
	void setReparador(int reparador) { this->reparador = reparador; }
	void setCombatente(int combatente) { this->combatente = combatente; }
	void setXenomorfo(int xenomorfo) { this->xenomorfo = xenomorfo; }
	void setCasulo(int casulo) { this->casulo = casulo; }
	void setOperador(int operador) { this->operador = operador; }
	void setMutatis(int mutatis) { this->mutatis = mutatis; }
	void setHipnotizador(int hipnotizador) { this->hipnotizador = hipnotizador; }
	void setTripulacao(int tripulacao) { this->tripulacao = tripulacao; }
	void setInimigo(int inimigo) { this->inimigo = inimigo; }
	void setInimigoSala(int inimigoSala) { this->inimigoSala = inimigoSala; }

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

//	INIMIGOS

class pirata : public unidade{

public:
	pirata();
	~pirata();
};

#endif 