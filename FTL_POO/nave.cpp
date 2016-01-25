#pragma once
#include "main.h"



nave::nave()
{
	setEscudo(100);
	setTripulantes(0);
}

nave::~nave(){}

void nave::addSala(int tipo){

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
	return NULL; 
}

unidade* nave::getUnidade(int numero){
	for (itu = vectorUnidades.begin(); itu != vectorUnidades.end(); ++itu){
		if ((*itu)->getId() == numero)
			return (*itu);
	}

	// MENU
	colocaOrdem();
	cout << "Não existe numero";
	return NULL;
}

void nave::removeTempUnidade(unidade* uni){
	int contador = 0;

	// Remover da sala
	sala* salaActual = getSala(uni->getSala());

	for (itu = salaActual->getVU().begin(); itu != salaActual->getVU().end(); ++itu){
		if ((*itu)->getId() == uni->getId())
			salaActual->getVU().erase(salaActual->getVU().begin() + contador);
		contador++;
	}
}

void nave::removeTempInimigo(unidade* uni){
	int contador = 0;

	// Remove o Inimigo da nave
	for (itu = vectorInimigos.begin(); itu != vectorInimigos.end(); ++itu){
		if ((*itu)->getId() == uni->getId())
			vectorInimigos.erase(vectorInimigos.begin() + contador);
		contador++;
	}

	contador = 0;
	// Vai remover da sala também
	sala* salaActual = getSala(uni->getSala());

	for (itu = salaActual->getVI().begin(); itu != salaActual->getVI().end(); ++itu){
		if ((*itu)->getId() == uni->getId())
			salaActual->getVI().erase(salaActual->getVI().begin() + contador);
		contador++;
	}
}

void nave::removeTempXenomorfo(unidade* uni){
	int contador = 0;

	// Remove o Xenomorfo da nave
	for (itu = vectorXenomorfos.begin(); itu != vectorXenomorfos.end(); ++itu){
		if ((*itu)->getId() == uni->getId())
			vectorXenomorfos.erase(vectorXenomorfos.begin() + contador);
		contador++;
	}

	contador = 0;
	// Vai remover da sala também
	sala* salaActual = getSala(uni->getSala());

	for (itu = salaActual->getVX().begin(); itu != salaActual->getVX().end(); ++itu){
		if ((*itu)->getId() == uni->getId())
			salaActual->getVX().erase(salaActual->getVX().begin() + contador);
		contador++;
	}
}

void nave::atribuiNumero(){
	int i = 0;

	for (it = vectorSalas.begin(); it != vectorSalas.end(); ++it){
		(*it)->setNumero(i);
		i++;
	}
}

void nave::addUnidade(int tipo, int sala){
	
	switch (tipo){
	case MEMBRO:
		getSala(sala)->addUnidade(new membro(sala));
		//vectorUnidades.push_back(new membro(sala));
		break;
	case CAPITAO:
		getSala(sala)->addUnidade(new capitao(sala));
		break;
	case ROBOT:
		getSala(sala)->addUnidade(new robot(sala));
		break;
	case GEIGERMORFO:
		getSala(sala)->addXenomorfo(new geigermorfo(sala));
		break;
	case CASULO:
		getSala(sala)->addXenomorfo(new casulo(sala, false));
		break;
	case BLOBE:
		getSala(sala)->addXenomorfo(new blob(sala));
		break;
	case MXYZYPYKWI:
		getSala(sala)->addXenomorfo(new mxyzypykwi(sala));
		break;
	case PIRATA:
		getSala(sala)->addInimigo(new pirata(sala));
		break;
	default:
		cout << "Não há essa classe";
		break;
	}
}

