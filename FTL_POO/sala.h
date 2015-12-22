#pragma once
#include "main.h"

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
const int ALJOAMENTOCAPITAO = 911;
const int OFICINA = 912;

// Sala Normal
class sala{

protected:
	int id;
	int numero;
	int saude;
	int integridade;
	int oxigenio;
	vector<int> salasAdjacentes;

public:
	sala();
	~sala();

	int getId(){ return id; };
	int getNumero(){ return numero; }
	int getSaude(){ return saude; };
	int getIntegridade(){ return integridade; };
	int getOxigenio(){ return oxigenio; };

	void setId(int s){ id = s; };
	void setNumero(int s){ numero = s; };
	void setSaude(int s){ saude = s; };
	void setIntegridade(int s){ integridade = s; };
	void setOxigenio(int s){ oxigenio = s; };

	virtual void fazEfeito();
	bool verificaDano();
};

// Sala ponte, necessário para movimentar a nave
class ponte : public sala{
public:
	ponte();
	~ponte();
};

// Sala suporte de vida, cria oxigénio para a nave
class supVida : public sala{
public:
	supVida();
	~supVida();

	virtual void fazEfeito();
};

// Sala propulsor, dita a velocidade acumulando todos
// os propulsores da nave
// Não pode ser reparada, sempre que leva dano a propulsão diminui
class propulsor : public sala{
	int propulsao;

public:
	propulsor();
	~propulsor();
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
};

// Sala de maquinas, propulsores ñ funcionam se estiver
// danificada
class maquinas : public sala{
public:
	maquinas();
	~maquinas();
};

// Sala que aumenta a capacidade da tripulação em 1
class beliche : public sala{
	beliche();
	~beliche();

	virtual void fazEfeito(nave n);
};

// Sala que modifica os eventos quando este é operado
class raioLaser : public sala{
	raioLaser();
	~raioLaser();
};

// Sala que repara salas adjacentes em 5 pontos
// Funciona apenas sem dano
// Final de turno apenas
class autoReparador : public sala{
	autoReparador();
	~autoReparador();

	virtual void fazEfeito(nave n);
};

// Sala que danifica inimigos em salas adjacentes e 
// na própria, funciona se não estiver danificado
class segInterna : public sala{
	segInterna();
	~segInterna();

	virtual void fazEfeito();
};

// Sala que cura a tripulação por 1 ponto
// Funciona se ñ estiver danificado
// Final  de turno apenas
class enfermaria : public sala{
	enfermaria();
	~enfermaria();

	virtual void fazEfeito();
};

// Sala que dá a caracteristica Armado(1) a quem acaba
// o turno dentro. Final de turno apenas
class armas : public sala{
	armas();
	~armas();

	virtual void fazEfeito();
};

// Sala que modifica um membro da tripulação por um capitão
// 1 cópia apenas
class alojaCapitao : public sala{
	alojaCapitao();
	~alojaCapitao();

	virtual void fazEfeito();
};

// Sala que modifica um membro da tripulação por um robot
class oficina : public sala{
	oficina();
	~oficina();

	virtual void fazEfeito();
};