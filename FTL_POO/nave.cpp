#pragma once
#include "main.h"

nave::nave()
{
	setEscudo(100);
}

nave::~nave(){}

void nave::addSala(sala s, int tipo){

	switch (tipo){
	case PONTE:
		vectorSalas.push_back(new ponte());
		break;
	case SUPORTEDEVIDA:
		vectorSalas.push_back(new supVida());
		break;
	case CONSTROLODEESCUDO:
		vectorSalas.push_back(new ctrlDeEscudo());
		break;
	case SALADASMAQUINAS:
		vectorSalas.push_back(new maquinas());
		break;
	case PROPULSOR:
		vectorSalas.push_back(new propulsor());
		break;
	case BELICHE:
		vectorSalas.push_back(new beliche());
		break;
	case RAIOLASER:
		vectorSalas.push_back(new raioLaser());
		break;
	case AUTOREPARADOR:
		vectorSalas.push_back(new autoReparador());
		break;
	case SEGURANCAINTERNA:
		vectorSalas.push_back(new segInterna());
		break;
	case ENFERMARIA:
		vectorSalas.push_back(new enfermaria());
		break;
	case SALADEARMAS:
		vectorSalas.push_back(new armas());
		break;
	case ALOJAMENTOCAPITAO:
		vectorSalas.push_back(new alojaCapitao());
		break;
	case OFICINA:
		vectorSalas.push_back(new oficina());
		break;
	}
}

sala* nave::getSala(int numero){
	for (it = vectorSalas.begin(); it != vectorSalas.end(); ++it){
		if ((*it)->getNumero() == numero)
			return (*it);
	}

	// MENU
	colocaOrdem();
	cout << "Não existe numero";
}