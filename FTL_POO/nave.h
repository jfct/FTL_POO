#ifndef Nave_H
#define Nave_H

#pragma once
#include "Unidades.h"
#include "sala.h"
#include <vector>

class nave{

	std::string nome;
	int escudo;
	int nTripulantes;
	int dificuldade;

	
	std::vector<sala*> vectorSalas;
	std::vector<sala*>::const_iterator it;

	std::vector<unidade*> vectorUnidades;
	std::vector<unidade*> vectorInimigos;
	std::vector<unidade*> vectorXenomorfos;
	
	std::vector<unidade*>::const_iterator itu;

public:
	nave();
	~nave();

	sala* getSala(int numero);
	unidade* getUnidade(int numero);
	unidade* getInimigo(int numero);
	unidade* getXenomorfo(int numero);

	void removeTempUnidade(unidade* uni);
	void removeTempInimigo(unidade* uni);
	void removeTempXenomorfo(unidade* uni);

	/*void removeUnidade(int id);
	void removeInimigo(int id);
	void removeXenomorfo(int id);*/

	void setVS(std::vector<sala*> vs){ this->vectorSalas = vs; };

	std::vector<sala*> getVS(){ return vectorSalas; };
	std::vector<unidade*> getVU(){ return vectorUnidades; };
	std::vector<unidade*> getVI(){ return vectorInimigos; };
	std::vector<unidade*> getVX(){ return vectorXenomorfos;	};

	void atribuiNumero();
	void addSala(int tipo);
	void addUnidade(int tipo, int sala);
	void addNTripulantes(int i){ nTripulantes = i; };

	int getDificuldade(){ return dificuldade; };
	int getNumeroTripulantes(){ return nTripulantes; };
	int getEscudo(){ return escudo; };
	int getTamanhoVU(){ return vectorUnidades.size(); };
	std::string getNome(){ return nome; };

	void setDificuldade(int s){ dificuldade = s; };
	void setNome(std::string n){ nome = n; };
	void setTamanho(){ vectorSalas.reserve(12); };
	void setTripulantes(int s) { nTripulantes = s; };
	void setEscudo(int s){ escudo = s; };

	// Função para substituir uma sala por outra
	// Parametros: Posicao, sala nova
	void setSala(int i, sala* nova){
		this->vectorSalas.erase(this->vectorSalas.begin() + i);
		this->vectorSalas.insert(this->vectorSalas.begin() + i, nova);
		this->vectorSalas[i]->setNumero(i);
	}
};
#endif