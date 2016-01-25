#ifndef Sala_H
#define Sala_H
#pragma once

#include "main.h"
#include <vector>

class game;
class nave;

const int PONTE = 900;
const int SUPORTEDEVIDA = 901;
const int CONSTROLODEESCUDO = 902;
const int SALADASMAQUINAS = 903;
const int PROPULSOR = 904;
const int BELICHE = 905;
const int RAIOLASER = 906;
const int AUTOREPARADOR = 907;
const int SEGURANCAINTERNA = 908;
const int ENFERMARIA = 909;
const int SALADEARMAS = 910;
const int ALOJAMENTOCAPITAO = 911;
const int OFICINA = 912;

// Sala Normal
class sala{

	int id;
	int numero;
	int saude;
	int integridade;
	int oxigenio;
	int propulsao;
	int nTripulantes;

	// Diferentes estados que uma sala poderá ter
	// Fogo = FOGO
	// Brecha = BRECHA
	// Curto Circuito = CURTOCIRCUITO
	int estado=0;
	int estado2=0;

	std::vector<unidade*> vectorUnidades;
	std::vector<unidade*> vectorInimigos;
	std::vector<unidade*> vectorXenomorfos;

	std::vector<int> salasAdjacentes;
	
public:
	sala();
	~sala();

	bool verificaDano();

	int getnTripulantes(){ return nTripulantes; };
	int getId(){ return id; };
	int getNumero(){ return numero; }
	int getSaude(){ return saude; };
	int getIntegridade(){ return integridade; };
	int getOxigenio(){ return oxigenio; };

	// Diferentes estados que uma sala poderá ter
	// Fogo = FOGO
	// Brecha = BRECHA
	// Curto Circuito = CURTOCIRCUITO
	int getEstado(){ return estado; };
	int getEstado2(){ return estado2; };
	// Diferentes estados que uma sala poderá ter
	// Fogo = FOGO
	// Brecha = BRECHA
	// Curto Circuito = CURTOCIRCUITO
	void setEstado(int s){ estado = s; };
	void setEstado2(int s){ estado2 = s; };

	void setnTripulantes(int s){ nTripulantes = s; };
	void setId(int s){ id = s; };
	void setNumero(int s){ numero = s; };
	void setSaude(int s){ saude = s; };
	void setIntegridade(int s){ integridade = s; };
	void setOxigenio(int s){ oxigenio = s; };

	// Sistema de propulsão
	virtual int getPropulsao(){ return 0; };
	virtual void setPropulsao(){};
	

	// Getters e Setters para identificar salas adjacentes
	void addAdjacente(int x){ salasAdjacentes.push_back(x); };
	void setAdjacente(std::vector<int> salasAdjacentes){ this->salasAdjacentes = salasAdjacentes; };
	std::vector<int> getAdjacente(){ return salasAdjacentes; };

	// Função para facilitar a adicao e remocao de unidades

	// Enviar unidade a ser adicionada
	void addUnidade(unidade* uni){ vectorUnidades.push_back(uni);};
	// Enviar unidade a ser adicionada
	void addInimigo(unidade* uni){ vectorInimigos.push_back(uni);};
	// Enviar unidade a ser adicionada
	void addXenomorfo(unidade* uni){ vectorXenomorfos.push_back(uni);};
	// Enviar Unidade a ser retirada 
	// Id de unidade
	void removeUnidade(unidade* uni, int id){
		std::vector<unidade*>::const_iterator itu;
		int contador = 0;

		for (itu = vectorUnidades.begin(); itu != vectorUnidades.end(); ++itu)
		{
			if ((*itu)->getNumero() == id)
			{
				vectorUnidades.erase(vectorUnidades.begin() + contador);
				//nTripulantes--;
				return;
			}
			contador++;
		}
	}
	// Enviar Unidade a ser retirada 
	// Id de unidade
	void removeInimigo(unidade* uni, int id){
		std::vector<unidade*>::const_iterator itu;
		int contador = 0;

		for (itu = vectorInimigos.begin(); itu != vectorInimigos.end(); ++itu)
		{
			if ((*itu)->getNumero() == id)
			{
				vectorInimigos.erase(vectorInimigos.begin() + contador);
				return;
			}
			contador++;
		}
	}
	// Enviar Unidade a ser retirada 
	// Id de unidade
	void removeXenomorfo(unidade* uni, int id){
		std::vector<unidade*>::const_iterator itu;
		int contador = 0;

		for (itu = vectorXenomorfos.begin(); itu != vectorXenomorfos.end(); ++itu)
		{
			if ((*itu)->getNumero() == id)
			{
				vectorXenomorfos.erase(vectorXenomorfos.begin() + contador);
				return;
			}
			contador++;
		}
	}

	void setVectorUnidades(std::vector<unidade*> vectorUnidades){ this->vectorUnidades = vectorUnidades; };
	void setVectorInimigos(std::vector<unidade*> vectorInimigos){ this->vectorInimigos = vectorInimigos; };
	void setVectorXenomorfos(std::vector<unidade*> vectorXenomorfos){ this->vectorXenomorfos = vectorXenomorfos; };

	std::vector<unidade*> getVU(){ return vectorUnidades; };
	std::vector<unidade*> getVI(){ return vectorInimigos; };
	std::vector<unidade*> getVX(){ return vectorXenomorfos; };

	//virtual int getTipo(){ return 0; };

	virtual void fazEfeito(nave* n, sala* s);
};

// Sala ponte, necessário para movimentar a nave
class ponte : public sala{
public:
	ponte();
	~ponte();

	virtual void fazEfeito();
};

// Sala suporte de vida, cria oxigénio para a nave
class supVida : public sala{
public:
	supVida();
	~supVida();

	virtual void fazEfeito(nave* n, sala* s);
};

// Sala propulsor, dita a velocidade acumulando todos
// os propulsores da nave
// Não pode ser reparada, sempre que leva dano a propulsão diminui
class propulsor : public sala{
	int propulsao;
	int tipo = PROPULSOR;
public:
	propulsor();
	~propulsor();

	void setPropulsao(int s){ propulsao = s; };
	int getPropulsao(){ return propulsao; };

	int getTipo(){ return tipo; };

	virtual void fazEfeito();
};

// Sala controlo de escudo, Gera escudo para a nave
// Final de turno apenas
class ctrlDeEscudo : public sala{
public:
	ctrlDeEscudo();
	~ctrlDeEscudo();

	void forneceEscudo();

	int getEscudo(nave n);
	void setEscudo(nave n, int esc);

	virtual void fazEfeito(nave* n, sala* s);
};

// Sala de maquinas, propulsores ñ funcionam se estiver
// danificada
class maquinas : public sala{
public:
	maquinas();
	~maquinas();

	virtual void fazEfeito(nave* n, sala* s, game* g, int propulsaoTotal);
};

// Sala que aumenta a capacidade da tripulação em 1
class beliche : public sala{
public:
	beliche();
	~beliche();

	virtual void fazEfeito();
};

// Sala que modifica os eventos quando este é operado
class raioLaser : public sala{
public:
	raioLaser();
	~raioLaser();

	virtual void fazEfeito();
};

// Sala que repara salas adjacentes em 5 pontos
// Funciona apenas sem dano
// Final de turno apenas
class autoReparador : public sala{
public:
	autoReparador();
	~autoReparador();

	virtual void fazEfeito(nave* n, sala* s);
};

// Sala que danifica inimigos em salas adjacentes e 
// na própria, funciona se não estiver danificado
class segInterna : public sala{
public:
	segInterna();
	~segInterna();

	virtual void fazEfeito(nave* n, sala* s);
};

// Sala que cura a tripulação por 1 ponto
// Funciona se ñ estiver danificado
// Final  de turno apenas
class enfermaria : public sala{
public:
	enfermaria();
	~enfermaria();

	virtual void fazEfeito(nave* n, sala* s);
};

// Sala que dá a caracteristica Armado(1) a quem acaba
// o turno dentro. Final de turno apenas
class armas : public sala{
public:
	armas();
	~armas();

	virtual void fazEfeito(nave* n, sala* s);
};

// Sala que modifica um membro da tripulação por um capitão
// 1 cópia apenas
class alojaCapitao : public sala{
public:
	alojaCapitao();
	~alojaCapitao();

	virtual void fazEfeito();
};

// Sala que modifica um membro da tripulação por um robot
class oficina : public sala{
public:
	oficina();
	~oficina();

	virtual void fazEfeito();
};
#endif