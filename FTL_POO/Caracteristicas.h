#ifndef Caracteristicas_H
#define Caracteristicas_H
#pragma once

#include "main.h"

// Caracteristicas
const int TOXICO = 900;
const int TRIPULACAO = 901;
const int FLAMEJANTE = 902;
const int ARMADO = 903;

class caracteristicas{

public:
	virtual int getTipo();
	virtual int getValor();
	
	virtual void inicioTurno(unidade* vu, nave* n);
	virtual void fimTurno(unidade* vu , nave* n);
};

class respira : public caracteristicas{
public:
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class flamejante : public caracteristicas{
public:
	int getTipo(){ return 0; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class toxico : public caracteristicas{
	int x;
	int tipo = TOXICO;
public:
	toxico(int x){ this->x = x; };
	
	int getTipo(){ return TOXICO; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class indeciso : public caracteristicas{
public:
	int getTipo(){ return 0; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class misterioso : public caracteristicas{
	int activo = 0;
public:
	int getTipo(){ return 0; };

	int getActivo(){ return activo; };
	void setActivo(int activo){ this->activo = activo; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class regenerador : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	regenerador(int x){ this->x = x; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class exoesqueleto : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	exoesqueleto(int x){ this->x = x; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class robotico : public caracteristicas{
public:
	int getTipo(){ return 0; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class reparador : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	reparador(int x){ this->x = x; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class combatente : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	combatente(int x){ this->x = x; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class xenomorfo : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	xenomorfo(int x){ this->x = x; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class casuloCaracteristicas : public caracteristicas{
	// Turnos depois de ter sido apanhada
	int x=0;
	// Verificação para saber se já apanhou alguem ou não
	bool activo;
	// Caso tenha apanhado alguém guarda nesta variavél auxiliar
	unidade* uniAux;
public:
	int getTipo(){ return 0; };
	
	unidade* getUnidade(){ return uniAux; };
	void setUnidade(unidade* uni){ uniAux = uni; };

	casuloCaracteristicas(int x){ this->x = x; };
	casuloCaracteristicas(int x, bool y){ this->x = x; this->activo = y; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class mutatis : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	mutatis(int x){ this->x = x; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class hipnotizador : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	hipnotizador(int x){ this->x = x; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class operador : public caracteristicas{
	int tipo = 501;
public:
	int getTipo(){ return tipo; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class tripulacao : public caracteristicas{
	int tipo = TRIPULACAO;
public:
	int getTipo(){ return TRIPULACAO; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class inimigo : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	inimigo(int x){ this->x = x; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class inimigoSala : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	inimigoSala(int x){ this->x = x; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class move_ : public caracteristicas{
	int x;
public:
	int getTipo(){ return 0; };
	move_(int x){ this->x = x; };
	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

class armado : public caracteristicas{
	int x;
	bool flag = true;
public:
	int getTipo(){ return ARMADO; };
	armado(int x){ this->x = x; };

	void inicioTurno(unidade* uni, nave* n);
	void fimTurno(unidade* uni, nave* n);
};

#endif