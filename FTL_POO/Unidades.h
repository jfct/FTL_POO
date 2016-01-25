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

class caracteristicas;

class unidade{

	unidade* uniAux;

	// Nome da Unidade
	std::string nome;

	// Informação básica e comum a todas as unidades
	int saudeMax;
	int saude;
	// Sala que se encontrar
	int sala;
	// Tipo de unidade
	int tipo;
	// Id
	int numero;

	// Variavel para saber se esta visivel ou nao
	int visivel = 1;

	// Valores para o seu exoesqueleto e arma
	int valorExoesqueleto;
	int armado;

	// Valor de indecisao de uma unidade;
	int valorIndeciso;

	// Booleanos para verificar permissões
	bool mover = true;
	bool combater= true;
	bool inGame = true;
	// Guarda sala para onde vai se movimentar
	bool jaMoveu = false;

	// Inteiro que verifica se a unidade ja fez as suas caracteristicas este turno
	int finish;
	// Vector que contem caracteristiscas de cada unidade
	std::vector<caracteristicas*> vectorCaracteristicas;

public:
	unidade();
	~unidade();

	static int id, idInimigo, idXenomorfo;

	void setVisivel(int visivel){ this->visivel = visivel; };
	int getVisivel(){ return visivel; };

	void setFinish(int finish){ this->finish = finish; };
	int getFinish(){ return finish; };

	void setUniAux(unidade* uni){ this->uniAux = uni; };
	unidade* getUniAux(){ return uniAux; };

	void setCaracteristicas(std::vector<caracteristicas*> VC){ vectorCaracteristicas = VC; };
	std::vector<caracteristicas*> getCaracteristicas(){ return vectorCaracteristicas; };

	bool getMover(){ return mover; };
	bool getCombater(){ return combater; };
	bool getInGame(){ return inGame; };
	bool getJaMoveu(){ return jaMoveu; };

	void setMover(bool mover){ this->mover = mover; };
	void setCombater(bool combater){ this->combater = combater; };
	void setInGame(bool inGame){ this->inGame = inGame; };

	int getIndeciso(){ return valorIndeciso; };
	int getArmado(){ return armado; };
	int getExoesqueleto() { return this->valorExoesqueleto; }
	int getId(){return id;};
	int getSaudeMax(){ return saudeMax; };
	int getSaude(){ return saude; };
	int getSala(){ return sala; };
	int getTipo(){ return tipo; };
	int getNumero(){ return numero; };

	void setIndeciso(int s){ if(this->valorIndeciso < 100) this->valorIndeciso += s; };
	void setArmado(int s){ armado = s; };
	void setJaMoveu(bool s){ jaMoveu = s; };
	void setTipo(int s){ tipo = s; }
	void setId(int s){ id = s; };
	void setSaudeMax(int s){ saudeMax = s; };
	void setSaude(int s){ saude = s; };
	void setSala(int s){ sala = s; };
	void setExoesqueleto(int exoesqueleto) { this->valorExoesqueleto = exoesqueleto; }
	void setNumero(int s){ numero = s; };

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
	geigermorfo(int i);
	~geigermorfo();
};

class casulo : public unidade{
	//unidade* uniAux;
	int contagem;
public:


	casulo(int i, unidade* uni);
	~casulo();
};

class blob : public unidade{
public:
	blob(int i);
	~blob();
};

class mxyzypykwi : public unidade{
public:
	mxyzypykwi(int i);
	~mxyzypykwi();
};

//	INIMIGOS

class pirata : public unidade{

public:
	pirata(int i);
	~pirata();
};

#endif 