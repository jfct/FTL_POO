#pragma once
#include "Caracteristicas.h"
#include "jogo.h"

class Jogo;

int caracteristicas::getTipo(){return 0;}
int caracteristicas::getValor(){return 0;}
void caracteristicas::inicioTurno(unidade* uni, nave* n){}
void caracteristicas::fimTurno(unidade* uni, nave* n){}

// Caracteristicas das unidades

//--------------------------------RESPIRA-------------------------------------------------------
void respira::inicioTurno(unidade* uni, nave* n){}
void respira::fimTurno(unidade* uni, nave* n){
	if (n->getSala(uni->getSala())->getOxigenio() > 0)
	{
		n->getSala(uni->getSala())->setOxigenio(n->getSala(uni->getSala())->getOxigenio() - 1);
	}
	else
	{
		uni->setSaude(uni->getSaude() - 1);
		cout << uni->getNomeUnidade() + " esta sem ar perdeu 1 ponto" << endl;
	}
}

//--------------------------------FLAMEJANTE-------------------------------------------------------
void flamejante::inicioTurno(unidade* uni, nave* n){
	if (n->getSala(uni->getSala())->getOxigenio() > 0)
	{
		n->getSala(uni->getSala())->setOxigenio(n->getSala(uni->getSala())->getOxigenio() - 5);
	}
	cout << uni->getNomeUnidade() + " acabou de tirar 5 pontos de oxigenio" << endl;
}
void flamejante::fimTurno(unidade* uni, nave* n){}

//--------------------------------TOXICO-------------------------------------------------------
void toxico::inicioTurno(unidade* uni, nave* n){
	vector<unidade*> vuNaSala;
	vector<unidade*>::const_iterator itu;
	vector<caracteristicas*> vc;
	vector<caracteristicas*>::const_iterator itc;
	
	int flag;

	// Testar contra unidades
	vuNaSala = n->getSala(uni->getSala())->getVU();
	for (itu = vuNaSala.begin(); itu != vuNaSala.end(); ++itu)
	{
		flag = 0;
		vc = (*itu)->getCaracteristicas();

		for (itc = vc.begin(); itc != vc.end(); ++itc)
		{
			if ((*itc)->getTipo() == TOXICO)
				flag = 1;
		}
		if (flag == 0)
		{
			(*itu)->setSaude((*itu)->getSaude() - x);
			cout << uni->getNomeUnidade() + " acabou de tirar " + to_string(x) + " pontos de vida a " + (*itu)->getNomeUnidade() << endl;
		}
	}
	// Testar contra Piratas
	vuNaSala = n->getSala(uni->getSala())->getVI();
	for (itu = vuNaSala.begin(); itu != vuNaSala.end(); ++itu)
	{
		flag = 0;
		vc = (*itu)->getCaracteristicas();

		for (itc = vc.begin(); itc != vc.end(); ++itc)
		{
			if ((*itc)->getTipo() == TOXICO)
				flag = 1;
		}
		if (flag == 0)
		{
			(*itu)->setSaude((*itu)->getSaude() - x);
			cout << uni->getNomeUnidade() + " acabou de tirar " + to_string(x) + " pontos de vida a " + (*itu)->getNomeUnidade() << endl;
		}
	}
	// Testar contra Xenomorfos
	// Testar contra Piratas
	vuNaSala = n->getSala(uni->getSala())->getVX();
	for (itu = vuNaSala.begin(); itu != vuNaSala.end(); ++itu)
	{
		flag = 0;
		vc = (*itu)->getCaracteristicas();

		for (itc = vc.begin(); itc != vc.end(); ++itc)
		{
			if ((*itc)->getTipo() == TOXICO)
				flag = 1;
		}
		if (flag == 0)
		{
			(*itu)->setSaude((*itu)->getSaude() - x);
			cout << uni->getNomeUnidade() + " acabou de tirar " + to_string(x) + " pontos de vida a " + (*itu)->getNomeUnidade() << endl;
		}
	}
}
void toxico::fimTurno(unidade* uni, nave* n){}

//--------------------------------INDECISO-------------------------------------------------------
void indeciso::inicioTurno(unidade* uni, nave* n){
	if (uni->getIndeciso() <= 50)
	{
		uni->setIndeciso(uni->getIndeciso() + 50);
	}
	else
	{
		uni->setIndeciso(uni->getIndeciso() + 10);
	}
}
void indeciso::fimTurno(unidade* uni, nave*n){}

//--------------------------------MISTERIOSO-------------------------------------------------------
void misterioso::inicioTurno(unidade* uni, nave* n){}
void misterioso::fimTurno(unidade* uni, nave* n){
	int probabilidade = numeroAleatorio1(0, 100);

		if (getActivo() == 1)
		{
			int salaRandom = numeroAleatorio1(0, 11);
			int posicao;
			int contador = 0;
			vector<unidade*>::const_iterator itu;
			vector<unidade*> vx = n->getSala(uni->getSala())->getVX();
			// Ciclo para descobrir a posição da unidade atual
			for (itu = vx.begin(); itu != vx.end(); ++itu)
			{
				if ((*itu)->getNomeUnidade() == uni->getNomeUnidade())
					posicao = contador;
				contador++;
			}

			moveXenomorfo(n, n->getVS(), n->getSala(uni->getSala()), salaRandom, posicao);
			setActivo(0);
			uni->setVisivel(1);
			cout << uni->getNomeUnidade() + " voltou a aparecer!" << endl;

		}
		else{

			if (probabilidade < 25)
			{
				setActivo(1);
				uni->setVisivel(0);
				cout << uni->getNomeUnidade() + " desapareceu misteriosamente!" << endl;

			}
		}
}

//--------------------------------REGENERADOR-------------------------------------------------------
void regenerador::inicioTurno(unidade* uni, nave* n){
	if (uni->getSaude() < uni->getSaudeMax())
	{
		uni->setSaude(uni->getSaude() + x);
		if (uni->getSaude() > uni->getSaudeMax())
			uni->setSaude(uni->getSaudeMax());
		cout << uni->getNomeUnidade() + " Regenerou "+to_string(x)+" de vida" << endl;
	}
}
void regenerador::fimTurno(unidade* uni, nave* n){}

//--------------------------------EXOESQUELETO-------------------------------------------------------
void exoesqueleto::inicioTurno(unidade* uni, nave* n){
	uni->setExoesqueleto(x);
}
void exoesqueleto::fimTurno(unidade* uni, nave* n){}

//--------------------------------ROBÓTICO-------------------------------------------------------
void robotico::inicioTurno(unidade* uni, nave* n){
	if (n->getSala(uni->getSala())->getEstado() == CURTOCIRCUITO)
	{
		uni->setCombater(false);
		uni->setMover(false);
		cout << uni->getNomeUnidade() + " esta impedido devido a um CC";

	}
	else{
		if (uni->getCombater() == false && uni->getMover() == false)
		{
			uni->setCombater(true);
			uni->setMover(true);
		}
	}
}
void robotico::fimTurno(unidade* uni, nave* n){
}

//--------------------------------REPARADOR-------------------------------------------------------
void reparador::inicioTurno(unidade* uni, nave* n){}
void reparador::fimTurno(unidade* uni, nave* n)
{
	sala* salaActual = n->getSala(uni->getSala());

	if (salaActual->getId() != PROPULSOR)
	{
		if (salaActual->getSaude() < 100)
		{
			salaActual->setSaude(salaActual->getSaude() + x);
			cout << uni->getNomeUnidade() + " reparou a sala " + to_string(salaActual->getNumero()) +" por " +to_string(x) << endl;
		}

		if (salaActual->getSaude() > 100)
		{
			salaActual->setSaude(100);
			cout <<uni->getNomeUnidade() + " reparou completamente a sala " + to_string(salaActual->getNumero()) << endl;
		}
	}
}

//--------------------------------COMBATENTE-------------------------------------------------------
void combatente::inicioTurno(unidade* uni, nave* n){}
void combatente::fimTurno(unidade* uni, nave* n){
	// CASO HAJA APENAS UM TIPO DE INIMIGO
	// NO CASO DO TRIPULANTE UM XENOMORFO OU UM INIMIGO

	vector<unidade*> vi = n->getSala(uni->getSala())->getVI();
	vector<unidade*> vx = n->getSala(uni->getSala())->getVX();

	if (vi.size() != 0 || vx.size() != 0)
	{
		if (vi.size() == 0 || vx.size() == 0)
		{
			if (vi.size() != 0)
			{
				// dano
				int random = numeroAleatorio1(0, vi.size() - 1);

				vi.at(random)->setSaude((vi.at(random)->getSaude() + vi.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
				cout << uni->getNomeUnidade() + " atacou " + vi.at(random)->getNomeUnidade() << endl;
				vi.at(random)->setExoesqueleto(vi.at(random)->getExoesqueleto() - x);

				if (vi.at(random)->getExoesqueleto() < 0)
					vi.at(random)->setExoesqueleto(0);
				if (vi.at(random)->getSaude() > vi.at(random)->getSaudeMax())
					vi.at(random)->setSaude(vi.at(random)->getSaudeMax());
				uni->setCombater(true);
				vi.at(random)->setCombater(true);
			}
			else{
				if (vx.size() != 0)
				{
					// dano
					int random = numeroAleatorio1(0, vx.size() - 1);

					vx.at(random)->setSaude((vx.at(random)->getSaude() + vx.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
					vx.at(random)->setExoesqueleto(vx.at(random)->getExoesqueleto() - x);
					cout << uni->getNomeUnidade() + " atacou " + vx.at(random)->getNomeUnidade() << endl;

					if (vx.at(random)->getExoesqueleto() < 0)
						vx.at(random)->setExoesqueleto(0);
					
					if (vx.at(random)->getSaude() > vx.at(random)->getSaudeMax())
						vx.at(random)->setSaude(vx.at(random)->getSaudeMax());
					uni->setCombater(true);
					vx.at(random)->setCombater(true);
				}
			}
		}
		// CASO AMBOS SEJAM POSITIVOS
		else
		{
			// 50% de atacar o tripulante ou o pirata
			int percentagem = numeroAleatorio1(0, 50);

			if (percentagem > 25)
			{
				// dano pirata
				int random = numeroAleatorio1(0, vi.size() - 1);

				vi.at(random)->setSaude((vi.at(random)->getSaude() + vi.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
				cout << uni->getNomeUnidade() + " atacou " + vi.at(random)->getNomeUnidade() << endl;
				vi.at(random)->setExoesqueleto(vi.at(random)->getExoesqueleto() - x);

				if (vi.at(random)->getExoesqueleto() < 0)
					vi.at(random)->setExoesqueleto(0);

				if (vi.at(random)->getSaude() > vi.at(random)->getSaudeMax())
					vi.at(random)->setSaude(vi.at(random)->getSaudeMax());
				uni->setCombater(true);
				vi.at(random)->setCombater(true);
			}
			else{
				// dano xenomorfo
				int random = numeroAleatorio1(0, vx.size() - 1);

				vx.at(random)->setSaude((vx.at(random)->getSaude() + vx.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
				cout << uni->getNomeUnidade() + " atacou " + vx.at(random)->getNomeUnidade() << endl;
				vx.at(random)->setExoesqueleto(vx.at(random)->getExoesqueleto() - x);

				if (vx.at(random)->getExoesqueleto() < 0)
					vx.at(random)->setExoesqueleto(0);
				if (vx.at(random)->getSaude() > vx.at(random)->getSaudeMax())
					vx.at(random)->setSaude(vx.at(random)->getSaudeMax());
				uni->setCombater(true);
				vx.at(random)->setCombater(true);
			}
		}
	}
	uni->setCombater(false);
}

//--------------------------------XENOMORFO-------------------------------------------------------
void xenomorfo::inicioTurno(unidade* uni, nave* n){}
void xenomorfo::fimTurno(unidade* uni, nave* n){
	// CASO HAJA APENAS UM TIPO DE INIMIGO
	// NO  CASO DO XENOMORFO UM TRIPULANTE OU UM INIMIGO

	vector<unidade*> vu = n->getSala(uni->getSala())->getVU();
	vector<unidade*> vi = n->getSala(uni->getSala())->getVI();

	if (vu.size() == 0 || vi.size() == 0)
	{
		if (vi.size() != 0)
		{
			// dano
			int random = numeroAleatorio1(0, vi.size() - 1);

			vi.at(random)->setSaude((vi.at(random)->getSaude() + vi.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
			cout << uni->getNomeUnidade() + " atacou " + vi.at(random)->getNomeUnidade() << endl;
			vi.at(random)->setExoesqueleto(vi.at(random)->getExoesqueleto() - x);

			if (vi.at(random)->getExoesqueleto() < 0)
				vi.at(random)->setExoesqueleto(0);
			if (vi.at(random)->getSaude() > vi.at(random)->getSaudeMax())
				vi.at(random)->setSaude(vi.at(random)->getSaudeMax());
			uni->setCombater(true);
			vi.at(random)->setCombater(true);
		}
		else{
			if (vu.size() != 0)
			{
				// dano
				int random = numeroAleatorio1(0, vu.size() - 1);

				vu.at(random)->setSaude((vu.at(random)->getSaude() + vu.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
				cout << uni->getNomeUnidade() + " atacou " + vu.at(random)->getNomeUnidade() << endl;
				vu.at(random)->setExoesqueleto(vu.at(random)->getExoesqueleto() - x);

				if (vu.at(random)->getExoesqueleto() < 0)
					vu.at(random)->setExoesqueleto(0);

				if (vu.at(random)->getSaude() > vu.at(random)->getSaudeMax())
					vu.at(random)->setSaude(vu.at(random)->getSaudeMax());
				uni->setCombater(true);
				vu.at(random)->setCombater(true);
			}
		}
	}
	// CASO AMBOS SEJAM POSITIVOS
	else
	{
		// 50% de atacar o tripulante ou o pirata
		int percentagem = numeroAleatorio1(0, 50);

		if (percentagem > 25)
		{
			// dano pirata
			int random = numeroAleatorio1(0, vi.size() - 1);

			vi.at(random)->setSaude((vi.at(random)->getSaude() + vi.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
			cout << uni->getNomeUnidade() + " atacou " + vi.at(random)->getNomeUnidade() << endl;
			vi.at(random)->setExoesqueleto(vi.at(random)->getExoesqueleto() - x);

			if (vi.at(random)->getExoesqueleto() < 0)
				vi.at(random)->setExoesqueleto(0);

			if (vi.at(random)->getSaude() > vi.at(random)->getSaudeMax())
				vi.at(random)->setSaude(vi.at(random)->getSaudeMax());
			uni->setCombater(true);
			vi.at(random)->setCombater(true);
		}
		else{
			// dano tripulante
			int random = numeroAleatorio1(0, vu.size() - 1);

			vu.at(random)->setSaude((vu.at(random)->getSaude() + vu.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
			cout << uni->getNomeUnidade() + " atacou " + vu.at(random)->getNomeUnidade() << endl;
			vu.at(random)->setExoesqueleto(vu.at(random)->getExoesqueleto() - x);

			if (vu.at(random)->getExoesqueleto() < 0)
				vu.at(random)->setExoesqueleto(0);
			if (vu.at(random)->getSaude() > vu.at(random)->getSaudeMax())
				vu.at(random)->setSaude(vu.at(random)->getSaudeMax());
			uni->setCombater(true);
			vu.at(random)->setCombater(true);
		}
	}
	uni->setCombater(false);
}

//--------------------------------CASULO-------------------------------------------------------
void casuloCaracteristicas::inicioTurno(unidade* uni, nave* n){
	if (activo)
	{
		x++;
		if (x == 8){
			// Adiciona um novo geigermorfo
			n->getSala(uni->getSala())->addXenomorfo(new geigermorfo(uni->getSala()));

			// Apaga o casulo actual
			n->getSala(uni->getSala())->removeXenomorfo(uni, uni->getNumero());
			cout << uni->getUniAux()->getNomeUnidade() + "Transformou-se num geigermorfo" << endl;
		}
	}
}
void casuloCaracteristicas::fimTurno(unidade* uni, nave* n){
	// CASO O CASULO JÁ ESTEJA A COBRIR UMA UNIDADE
	int probabilidade = numeroAleatorio1(1, 100);

	if (!activo && x > probabilidade)
	{
		vector<unidade*> vu = n->getSala(uni->getSala())->getVU();
		vector<unidade*> vi = n->getSala(uni->getSala())->getVI();

		if (vu.size() == 0 || vi.size() == 0)
		{
			if (vi.size() != 0)
			{
				// Encapsular Inimigo
				int random = numeroAleatorio1(0, vi.size() - 1);
				cout << vi.at(random)->getNomeUnidade() + " é agora um Casulo" << endl;

				// Remove unidade
				n->getSala(uni->getSala())->removeUnidade(vi.at(random), vi.at(random)->getNumero());
				// Adiciona o Casulo
				n->getSala(uni->getSala())->addXenomorfo(new casulo(vi.at(random)->getSala(), vi.at(random)));
				//n->removeTempInimigo(vi.at(random));

			}
			else{
				if (vu.size() != 0)
				{
					// Encapsular Unidade
					int random = numeroAleatorio1(0, vu.size() - 1);
					cout << vu.at(random)->getNomeUnidade() + " é agora um Casulo" << endl;

					// Remove unidade
					n->getSala(uni->getSala())->removeUnidade(vu.at(random), vu.at(random)->getNumero());

					// Adiciona o Casulo
					n->getSala(uni->getSala())->addXenomorfo(new casulo(vu.at(random)->getSala(), vu.at(random)));
					//n->removeTempUnidade(vu.at(random));
				}
			}
		}
		// CASO AMBOS SEJAM POSITIVOS
		else
		{
			// 50% de Encapsular o tripulante ou o pirata
			int percentagem = numeroAleatorio1(0, 50);

			if (percentagem > 25)
			{
				// Encapsula pirata
				int random = numeroAleatorio1(0, vi.size() - 1); 
				cout << vi.at(random)->getNomeUnidade() + " é agora um Casulo" << endl;

				// Remove unidade
				n->getSala(uni->getSala())->removeUnidade(vi.at(random), vi.at(random)->getNumero());
				// Adiciona o Casulo
				n->getSala(uni->getSala())->addXenomorfo(new casulo(vi.at(random)->getSala(), vi.at(random)));
				//n->removeTempInimigo(vi.at(random));
			}
			else{
				// Encapsula tripulante
				int random = numeroAleatorio1(0, vu.size() - 1);
				cout << vu.at(random)->getNomeUnidade() + " é agora um Casulo" << endl;

				// Remove unidade
				n->getSala(uni->getSala())->removeUnidade(vu.at(random), vu.at(random)->getNumero());
				// Adiciona o Casulo
				n->getSala(uni->getSala())->addXenomorfo(new casulo(vu.at(random)->getSala(), vu.at(random)));
				//n->removeTempUnidade(vu.at(random));
			}
		}
	}
}

//--------------------------------MUTATIS-------------------------------------------------------
void mutatis::inicioTurno(unidade* uni, nave* n){}
void mutatis::fimTurno(unidade* uni, nave* n){
	
	int probabilidade = numeroAleatorio1(0, 100);
	int salaA = uni->getSala();
	sala* salaAux;
	sala* salaActual = n->getSala(uni->getSala());

	if (probabilidade < x)
	{
		// Se a sala for uma das salas opcionais
		if (salaA == 1 || salaA == 2 || salaA == 3 || salaA == 11 || salaA == 10 || salaA == 9)
		{
			int salaAleatoria = numeroAleatorio1(0, 11);
			cout << "A sala " + to_string(uni->getSala()) + " foi mutada" << endl;
			switch (salaAleatoria){
			case 0:
				salaAux = new ponte();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 1:
				salaAux = new supVida();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 2:
				salaAux = new ctrlDeEscudo();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 3:
				salaAux = new maquinas();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 4:
				salaAux = new propulsor();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 5:
				salaAux = new beliche();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 6:
				salaAux = new raioLaser();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 7:
				salaAux = new autoReparador();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 8:
				salaAux = new segInterna();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 9:
				salaAux = new enfermaria();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 10:
				salaAux = new armas();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 11:
				salaAux = new alojaCapitao();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			case 12:
				salaAux = new oficina();
				salaAux->setVectorInimigos(salaActual->getVI());
				salaAux->setVectorUnidades(salaActual->getVU());
				salaAux->setVectorXenomorfos(salaActual->getVX());
				salaAux->setAdjacente(salaActual->getAdjacente());
				n->setSala(salaA, salaAux);
				break;
			default:
				break;
			}
		}
	}
}

//--------------------------------HIPNOTIZADOR-------------------------------------------------------
void hipnotizador::inicioTurno(unidade* uni, nave* n){}
void hipnotizador::fimTurno(unidade* uni, nave* n){
	
	vector<unidade*> vu = n->getSala(uni->getSala())->getVU();
	vector<unidade*>::const_iterator itu;
	int probabilidade = numeroAleatorio1(0, 100);


	// Verifica se ha unidades na sala
	if (vu.size() > 0)
	{
		// Se houver, tem probabilidade X de dar atributo indeciso
		if (probabilidade < x)
		{
			int unit = numeroAleatorio1(0, vu.size() - 1);
			cout << uni->getNomeUnidade() + " hipnotizou " + vu.at(unit)->getNomeUnidade() << endl;
			vector<caracteristicas*> vcAux = vu.at(unit)->getCaracteristicas();
			vcAux.push_back(new indeciso());
			vu.at(unit)->setCaracteristicas(vcAux);
		}
	}
}

//--------------------------------OPERADOR-------------------------------------------------------
void operador::inicioTurno(unidade* uni, nave* n){}
void operador::fimTurno(unidade* uni, nave* n){}

//--------------------------------TRIPULACAO-------------------------------------------------------
void tripulacao::inicioTurno(unidade* uni, nave* n){}
void tripulacao::fimTurno(unidade* uni, nave* n){}

//--------------------------------INIMIGO-------------------------------------------------------
void inimigo::inicioTurno(unidade* uni, nave* n){}
void inimigo::fimTurno(unidade* uni, nave* n){
	// CASO HAJA APENAS UM TIPO DE INIMIGO
	// NO CASO DO INIMIGO UM XENOMORFO OU UMA UNIDADE

	vector<unidade*> vu = n->getSala(uni->getSala())->getVU();
	vector<unidade*> vx = n->getSala(uni->getSala())->getVX();

	if (vu.size() != 0 || vx.size() != 0)
	{
		if (vu.size() == 0 || vx.size() == 0)
		{
			if (vu.size() != 0)
			{
				// dano
				int random = numeroAleatorio1(0, vu.size() - 1);

				vu.at(random)->setSaude((vu.at(random)->getSaude() + vu.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
				cout << uni->getNomeUnidade() + " atacou " + vu.at(random)->getNomeUnidade() << endl;
				vu.at(random)->setExoesqueleto(vu.at(random)->getExoesqueleto() - x);

				if (vu.at(random)->getExoesqueleto() < 0)
					vu.at(random)->setExoesqueleto(0);

				if (vu.at(random)->getSaude() > vu.at(random)->getSaudeMax())
					vu.at(random)->setSaude(vu.at(random)->getSaudeMax());
				uni->setCombater(true);
				vu.at(random)->setCombater(true);
			}
			else{
				if (vx.size() != 0)
				{
					// dano
					int random = numeroAleatorio1(0, vx.size() - 1);

					vx.at(random)->setSaude((vx.at(random)->getSaude() + vx.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
					cout << uni->getNomeUnidade() + " atacou " + vx.at(random)->getNomeUnidade() << endl;
					vx.at(random)->setExoesqueleto(vx.at(random)->getExoesqueleto() - x);

					if (vx.at(random)->getExoesqueleto() < 0)
						vx.at(random)->setExoesqueleto(0);

					if (vx.at(random)->getSaude() > vx.at(random)->getSaudeMax())
						vx.at(random)->setSaude(vx.at(random)->getSaudeMax());
					uni->setCombater(true);
					vx.at(random)->setCombater(true);
				}
			}
		}
		// CASO AMBOS SEJAM POSITIVOS
		else
		{
			// 50% de atacar o tripulante ou o pirata
			int percentagem = numeroAleatorio1(0, 50);

			if (percentagem > 25)
			{
				// dano unidade
				int random = numeroAleatorio1(0, vu.size() - 1);

				vu.at(random)->setSaude((vu.at(random)->getSaude() + vu.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
				cout << uni->getNomeUnidade() + " atacou " + vu.at(random)->getNomeUnidade() << endl;
				vu.at(random)->setExoesqueleto(vu.at(random)->getExoesqueleto() - x);

				if (vu.at(random)->getExoesqueleto() < 0)
					vu.at(random)->setExoesqueleto(0);

				if (vu.at(random)->getSaude() > vu.at(random)->getSaudeMax())
					vu.at(random)->setSaude(vu.at(random)->getSaudeMax());
				uni->setCombater(true);
				vu.at(random)->setCombater(true);
			}
			else{
				// dano xenomorfo
				int random = numeroAleatorio1(0, vx.size() - 1);

				vx.at(random)->setSaude((vx.at(random)->getSaude() + vx.at(random)->getExoesqueleto()) - (x + uni->getArmado()));
				cout << uni->getNomeUnidade() + " atacou " + vx.at(random)->getNomeUnidade() << endl;
				vx.at(random)->setExoesqueleto(vx.at(random)->getExoesqueleto() - x);

				if (vx.at(random)->getExoesqueleto() < 0)
					vx.at(random)->setExoesqueleto(0);

				if (vx.at(random)->getSaude() > vx.at(random)->getSaudeMax())
					vx.at(random)->setSaude(vx.at(random)->getSaudeMax());
				uni->setCombater(true);
				vx.at(random)->setCombater(true);
			}
		}
	}
	uni->setCombater(false);
}

//--------------------------------INIMIGOSALA-------------------------------------------------------
void inimigoSala::inicioTurno(unidade* uni, nave* n){}
void inimigoSala::fimTurno(unidade* uni, nave* n){

	vector<unidade*> vu = n->getSala(uni->getSala())->getVU();
	vector<unidade*> vx = n->getSala(uni->getSala())->getVX();

	if (vu.size() == 0 || vx.size() == 0){
		if (n->getSala(uni->getSala())->getSaude() > 0){
			n->getSala(uni->getSala())->setSaude(n->getSala(uni->getSala())->getSaude() - x);
			if (n->getSala(uni->getSala())->getSaude() < 0)
				n->getSala(uni->getSala())->setSaude(0);
			cout << uni->getNomeUnidade() + " deu " + to_string(x) + " de dano a sala " + to_string(uni->getSala()) << endl;
		}
	}
}

//--------------------------------MOVE-------------------------------------------------------
void move_::inicioTurno(unidade* uni, nave* n){
	int probabilidade = numeroAleatorio1(0, 100);
	if (uni->getMover() && probabilidade < x && !(uni->getJaMoveu()))
	{
		int contador = 0;
		int posicao = 0;

		vector<int> salas;

		// Sala Actual da unidade
		sala* salaActual = n->getSala(uni->getSala());

		// Cria vector de xenomorfos
		vector<unidade*> vx = salaActual->getVX();
		vector<unidade*>::const_iterator itu;

		// Vai buscar as salas adjacentes
		salas = n->getSala(uni->getSala())->getAdjacente();

		// Sala random entre as adjacentes para se mover
		int random = numeroAleatorio1(0, salas.size() - 1);

		// Ciclo para descobrir a posição da unidade atual
		for (itu = vx.begin(); itu != vx.end(); ++itu)
		{
			if ((*itu)->getNomeUnidade() == uni->getNomeUnidade())
				posicao = contador;
			contador++;
		}
		
		fflush(stdin);
		std::cout << uni->getNomeUnidade() + " moveu-se" << endl;
		if (uni->getTipo() == BLOBE || uni->getTipo() == MXYZYPYKWI || uni->getTipo() == GEIGERMORFO)
		{
			moveXenomorfo(n, n->getVS(), salaActual, salas.at(random), posicao);
		}
		else
		{
			moveInimigo(n, n->getVS(), salaActual, salas.at(random), posicao);
		}
		uni->setJaMoveu(true);
	}
}
void move_::fimTurno(unidade* uni, nave* n){}

//--------------------------------ARMADO-------------------------------------------------------
void armado::inicioTurno(unidade* uni, nave* n){
	if (flag)
	{
		uni->setArmado(x);
		cout << uni->getNomeUnidade() + "encontra-se agora armado" << endl;
	}
}
void armado::fimTurno(unidade* uni, nave* n){
}
