#pragma once
#include "Eventos.h"
#include <random>

int numeroAleatorio(int min, int max)
{
	return min + rand() % (max - min + 1);
};


// EVENTOS AMBIENTAIS

void PoCosmico(nave* n, Consola c){

	int aux = 15;
	int nSalas = numeroAleatorio(3, 5);
	sala* s;

	//c.setTextSize(20, 20);
	c.setBackgroundColor(c.VERMELHO);
	c.clrscr();
	c.setTextColor(c.PRETO);

	c.gotoxy(25, 4);
	cout << "PERIGO!!";
	c.gotoxy(12, 7);
	cout << "PERIGO!!";

	c.gotoxy(60, 10);
	cout << "PERIGO!!";
	c.gotoxy(75, 13);
	cout << "PERIGO!!";

	c.setTextColor(c.BRANCO);
	c.gotoxy(30, 9);
	cout << "PO COSMICO!!";
	c.gotoxy(15, 10);
	cout << "A sua nave vai levar dano";

	for (int i = 0; i < nSalas; i++)
	{
		int sala = numeroAleatorio(0, 11);
		s = n->getSala(sala);
		s->setSaude(s->getSaude() - DANOPOCOSMICO);
		if (s->getSaude() < 0)
			s->setSaude(0);
		c.gotoxy(10, aux++);
		cout << "A sala " << sala << " levou " << DANOPOCOSMICO << " de dano";
	}
	c.gotoxy(10, 30);
	system("PAUSE");
	c.setTextSize(13, 13);
}

void ChuvaMeteoritos(nave* n, Consola c){
	vector<unidade*> vx;
	vector<unidade*> vu;
	vector<caracteristicas*> vc;
	vector<unidade*>::const_iterator itu;
	vector<caracteristicas*>::const_iterator itc;

	vector<int> salasLaser;

	int aux = 15;
	int auxSala;
	int laser = 0;
	int operar = 0;
	int atingido;
	int probabilidade;

	//c.setTextSize(20, 20);
	c.setBackgroundColor(c.VERMELHO);
	c.clrscr();
	c.setTextColor(c.PRETO);

	c.gotoxy(25, 4);
	cout << "PERIGO!!";
	c.gotoxy(12, 7);
	cout << "PERIGO!!";

	c.gotoxy(60, 10);
	cout << "PERIGO!!";
	c.gotoxy(75, 13);
	cout << "PERIGO!!";

	c.setTextColor(c.BRANCO);
	c.gotoxy(30, 9);
	cout << "CHUVA DE METEORITOS!!";
	c.gotoxy(15, 10);
	cout << "A sua nave vai levar dano";



	// Verifica que há um operador na Ponte
	vu = n->getSala(7)->getVU();
	for (itu = vu.begin(); itu != vu.end(); ++itu)
	{
		if (!(*itu)->getCombater())
		{
			vc = (*itu)->getCaracteristicas();
			for (itc = vc.begin(); itc != vc.end(); ++itc)
			{
				if ((*itc)->getTipo() == OPERADOR)
					operar = 1;
			}
		}
	}
	// Confirmar se há blob a operar também
	vx = n->getSala(7)->getVX();
	for (itu = vx.begin(); itu != vx.end(); ++itu)
	{
		if (!(*itu)->getCombater())
		{
			vc = (*itu)->getCaracteristicas();
			for (itc = vc.begin(); itc != vc.end(); ++itc)
			{
				if ((*itc)->getTipo() == OPERADOR)
					operar = 1;
			}
		}
	}

	// Numero de vezes que a nave vai ser atingida
	if (operar == 1)
	{
		atingido = numeroAleatorio(4, 8);
	}
	else
		atingido = numeroAleatorio(6, 12);

	// Voltar a inicializar a 0 para nova confirmacao
	operar = 0;


	// Verifica se há sala Raio Laser e alguem a Operar
	for (int i = 0; i < 12; i++)
	{
		if (n->getSala(i)->getId() == RAIOLASER)
		{
			if (n->getSala(i)->getSaude()==100)
				laser = 1;

			vu = n->getSala(i)->getVU();
			for (itu = vu.begin(); itu != vu.end(); ++itu)
			{
				// Verifica se não está a combater
				if (!(*itu)->getCombater())
				{
					vc = (*itu)->getCaracteristicas();
					// Verifica se tem a caracteristica operador
					for (itc = vc.begin(); itc != vc.end(); ++itc)
					{
						if ((*itc)->getTipo() == OPERADOR)
							operar = 1;
					}
				}
			}
			// Confirmar se há blob a operar
			vx = n->getSala(i)->getVX();
			for (itu = vx.begin(); itu != vx.end(); ++itu)
			{
				// Verifica se não está a combater
				if (!(*itu)->getCombater())
				{
					vc = (*itu)->getCaracteristicas();
					// Verifica se tem a caracteristica operador
					for (itc = vc.begin(); itc != vc.end(); ++itc)
					{
						if ((*itc)->getTipo() == OPERADOR)
							operar = 1;
					}
				}
			}
		}
	}

	// Caso haja laser, verificamos 
	if (laser == 1 && operar == 1)
	{
			// Ciclo for para calcular probabilidade de acertar/falhar meteorito
			for (int i = 0; i < atingido; i++)
			{
				probabilidade = numeroAleatorio(0, 100);
				// Probabilidade de 50 de destruir o meteorito
				if (probabilidade > 50)
				{
					// Caso tenha escudo
					if (n->getEscudo() > 0){
						n->setEscudo(n->getEscudo() - 10);
						if (n->getEscudo() < 0)
							n->setEscudo(0);
						c.gotoxy(10, aux++);
						cout << "Atingido - 10 Escudo";
					}
					// Caso n tenha escudo
					else{
						int random = numeroAleatorio(0, 11);
						n->getSala(random)->setSaude(n->getSala(random)->getSaude() - 10);
						if (n->getSala(random)->getSaude() < 0)
							n->getSala(random)->setSaude(0);

						// Efectua Brecha na sala
						if (n->getSala(random)->getEstado() == 0)
							n->getSala(random)->setEstado(BRECHA);
						else
							if (n->getSala(random)->getEstado2() == 0)
								n->getSala(random)->setEstado(BRECHA);

						c.gotoxy(10, aux++);
						cout << "Sala " << random << " foi atingida e tem uma brecha";
					}
				}
				else
				{
					c.gotoxy(10, aux++);
					cout << "DEFENDIDO!";
				}
			}
		c.gotoxy(10, 30);
		system("PAUSE");
	}
	// Caso não tenha uma sala Raio laser, ou alguem a opera-la
	else{
		
		for (int i = 0; i < atingido; i++)
		{
			// Caso tenha escudo
			if (n->getEscudo() > 0){
				n->setEscudo(n->getEscudo() - 10);
				if (n->getEscudo() < 0)
					n->setEscudo(0);
				c.gotoxy(10, aux++);
				cout << "Atingido - 10 Escudo";
			}
			// Caso ja nao tenha escudo
			else{
				int random = numeroAleatorio(0, 11);
				n->getSala(random)->setSaude(n->getSala(random)->getSaude() - 10);
				if (n->getSala(random)->getSaude() < 0)
					n->getSala(random)->setSaude(0);

				// Efectua Brecha na sala
				if (n->getSala(random)->getEstado() == 0)
					n->getSala(random)->setEstado(BRECHA);
				else
					if (n->getSala(random)->getEstado2() == 0)
						n->getSala(random)->setEstado(BRECHA);

				c.gotoxy(10, aux++);
				cout << "Sala " << random << " foi atingida e tem uma brecha";
			}
		}

		c.gotoxy(10, 30);
		system("PAUSE");
	}
}

// ATAQUE DE UNIDADES

void AtaquePiratas(nave* n, Consola c){

	int probabilidade = numeroAleatorio(30, 60);
	int salaRandom = numeroAleatorio(0, 11);
	int operar = 0;
	int laser = 0;

	int aux = 15;

	c.setBackgroundColor(c.AZUL_CLARO);
	c.clrscr();
	c.setTextColor(c.PRETO);

	c.gotoxy(25, 4);
	cout << "PERIGO!!";
	c.gotoxy(12, 7);
	cout << "PERIGO!!";

	c.gotoxy(60, 10);
	cout << "PERIGO!!";
	c.gotoxy(75, 13);
	cout << "PERIGO!!";

	c.setTextColor(c.BRANCO);
	c.gotoxy(30, 9);
	cout << "ATAQUE DE PIRATAS!!";
	


	// "Ataque" dos pirates ao escudo
	if (n->getEscudo() > 0){
		if (probabilidade <= n->getEscudo()){
			n->setEscudo(n->getEscudo() - probabilidade);
			c.gotoxy(15, aux++);
			cout << "A sua nave levou " << probabilidade << " de dano no escudo";
		}
		else
		{
			// Arranja o dano extra, a ser aplicado a uma sala random 
			int dano = probabilidade - n->getEscudo();

			n->setEscudo(0);

			c.gotoxy(15, aux++);
			cout << "A sua nave levou dano e ficou sem Escudo";

			// Aplica dano a sala random
			n->getSala(salaRandom)->setSaude(n->getSala(salaRandom)->getSaude() - dano);
			if (n->getSala(salaRandom)->getSaude() < 0)
				n->getSala(salaRandom)->setSaude(0);

			c.gotoxy(15, aux++);
			cout << "A sala " << salaRandom << " levou " << dano << " de dano";

			// Escolhe estado random a para aplicar a sala
			// Brecha, fogo ou curto circuito
			// brecha = 0
			// fogo = 1
			// curto circuit = 2
			int probabilidade = numeroAleatorio(0, 2);

			switch (probabilidade){
			// Brecha
			case 0:
				if (n->getSala(salaRandom)->getEstado2() != BRECHA && n->getSala(salaRandom)->getEstado() == 0)
				{
					// Cria brecha
					n->getSala(salaRandom)->setEstado(BRECHA);
					c.gotoxy(15, aux++);
					cout << "A sala " << salaRandom << " tem uma Brecha";
				}
				else
				{
					if (n->getSala(salaRandom)->getEstado() != BRECHA && n->getSala(salaRandom)->getEstado2() == 0)
						// Cria brecha
						n->getSala(salaRandom)->setEstado(BRECHA);
					c.gotoxy(15, aux++);
					cout << "A sala " << salaRandom << " tem uma Brecha";
				}
				break;

			// Fogo
			case 1:
			if (n->getSala(salaRandom)->getEstado2() != BRECHA && n->getSala(salaRandom)->getEstado() == 0 && n->getSala(salaRandom)->getEstado2() != FOGO)
			{
				// Cria fogo
				n->getSala(salaRandom)->setEstado(FOGO);
				c.gotoxy(15, aux++);
				cout << "A sala " << salaRandom << " tem um Fogo";
			}
			else
				if (n->getSala(salaRandom)->getEstado() != BRECHA && n->getSala(salaRandom)->getEstado2() == 0 && n->getSala(salaRandom)->getEstado() != FOGO)
				{
					// Cria fogo
					n->getSala(salaRandom)->setEstado2(FOGO);
					c.gotoxy(15, aux++);
					cout << "A sala " << salaRandom << " tem um Fogo";
				}
			break;
			
			// Curto Circuito
			case 2:
				if (n->getSala(salaRandom)->getEstado() == 0 && n->getSala(salaRandom)->getEstado2() != CURTOCIRCUITO)
				{
					// Cria CC
					n->getSala(salaRandom)->setEstado(CURTOCIRCUITO);
					c.gotoxy(15, aux++);
					cout << "A sala " << salaRandom << " tem um Curto Circuito";
				}
				else
					if (n->getSala(salaRandom)->getEstado2() == 0 && n->getSala(salaRandom)->getEstado() != CURTOCIRCUITO)
					{
						// Cria CC
						n->getSala(salaRandom)->setEstado2(CURTOCIRCUITO);
						c.gotoxy(15, aux++);
						cout << "A sala " << salaRandom << " tem um Curto Circuito";
					}
				break;
			}
		}
	}
	else
	{
		// Arranja o dano extra, a ser aplicado a uma sala random 
		int dano = probabilidade - n->getEscudo();

		n->setEscudo(0);

		c.gotoxy(15, aux++);
		cout << "A sua nave levou dano e ficou sem Escudo";

		// Aplica dano a sala random
		n->getSala(salaRandom)->setSaude(n->getSala(salaRandom)->getSaude() - dano);
		if (n->getSala(salaRandom)->getSaude() < 0)
			n->getSala(salaRandom)->setSaude(0);

		c.gotoxy(15, aux++);
		cout << "A sala " << salaRandom << " levou " << dano << " de dano";

		// Escolhe estado random a para aplicar a sala
		// Brecha, fogo ou curto circuito
		// brecha = 0
		// fogo = 1
		// curto circuit = 2
		int probabilidade = numeroAleatorio(0, 2);

		switch (probabilidade){
			// Brecha
		case 0:
			if (n->getSala(salaRandom)->getEstado2() != BRECHA && n->getSala(salaRandom)->getEstado() == 0)
			{
				// Cria brecha
				n->getSala(salaRandom)->setEstado(BRECHA);
				c.gotoxy(15, aux++);
				cout << "A sala " << salaRandom << " tem uma Brecha";
			}
			else
			{
				if (n->getSala(salaRandom)->getEstado() != BRECHA && n->getSala(salaRandom)->getEstado2() == 0)
					// Cria brecha
					n->getSala(salaRandom)->setEstado(BRECHA);
				c.gotoxy(15, aux++);
				cout << "A sala " << salaRandom << " tem uma Brecha";
			}
			break;

			// Fogo
		case 1:
			if (n->getSala(salaRandom)->getEstado2() != BRECHA && n->getSala(salaRandom)->getEstado() == 0 && n->getSala(salaRandom)->getEstado2() != FOGO)
			{
				// Cria fogo
				n->getSala(salaRandom)->setEstado(FOGO);
				c.gotoxy(15, aux++);
				cout << "A sala " << salaRandom << " tem um Fogo";
			}
			else
				if (n->getSala(salaRandom)->getEstado() != BRECHA && n->getSala(salaRandom)->getEstado2() == 0 && n->getSala(salaRandom)->getEstado() != FOGO)
				{
					// Cria fogo
					n->getSala(salaRandom)->setEstado2(FOGO);
					c.gotoxy(15, aux++);
					cout << "A sala " << salaRandom << " tem um Fogo";
				}
			break;

			// Curto Circuito
		case 2:
			if (n->getSala(salaRandom)->getEstado() == 0 && n->getSala(salaRandom)->getEstado2() != CURTOCIRCUITO)
			{
				// Cria CC
				n->getSala(salaRandom)->setEstado(CURTOCIRCUITO);
				c.gotoxy(15, aux++);
				cout << "A sala " << salaRandom << " tem um Curto Circuito";
			}
			else
				if (n->getSala(salaRandom)->getEstado2() == 0 && n->getSala(salaRandom)->getEstado() != CURTOCIRCUITO)
				{
					// Cria CC
					n->getSala(salaRandom)->setEstado2(CURTOCIRCUITO);
					c.gotoxy(15, aux++);
					cout << "A sala " << salaRandom << " tem um Curto Circuito";
				}
			break;
		}
	}

	// Definicação de vectores r iteradores
	vector<unidade*> vu;
	vector<unidade*> vx;
	vector<unidade*>::const_iterator itu;
	vector<caracteristicas*> vc;
	vector<caracteristicas*>::const_iterator itc;

	// Verifica se há sala Raio Laser e alguem a Operar
	for (int i = 0; i < 12; i++)
	{
		if (n->getSala(i)->getId() == RAIOLASER)
		{
			if (n->getSala(i)->getSaude() == 100)
				laser = 1;

			vu = n->getSala(i)->getVU();
			for (itu = vu.begin(); itu != vu.end(); ++itu)
			{
				// Verifica se esta em combate
				if (!(*itu)->getCombater())
				{
					vc = (*itu)->getCaracteristicas();
					for (itc = vc.begin(); itc != vc.end(); ++itc)
					{
						if ((*itc)->getTipo() == OPERADOR)
							operar = 1;
					}
				}
			}
			// Confirmar se há blob a operar
			vx = n->getSala(i)->getVX();
			for (itu = vx.begin(); itu != vx.end(); ++itu)
			{
				// Verifica se está em combate
				if (!(*itu)->getCombater())
				{
					vc = (*itu)->getCaracteristicas();
					for (itc = vc.begin(); itc != vc.end(); ++itc)
					{
						if ((*itc)->getTipo() == OPERADOR)
							operar = 1;
					}
				}
			}
		}
	}
	if (laser == 1 && operar == 1)
	{
		// Piratas sao afugentados
		c.gotoxy(15, aux++);
		cout << "Os piratas fugiram devido ao Raio Laser";
	}
	else{
		// Pirata invade pois não ha ninguem a defender
		int nPiratas = numeroAleatorio(3, 5);
		for (int i = 0; i < nPiratas; i++){
			int salaRandom = numeroAleatorio(0, 11);
			n->getSala(salaRandom)->addInimigo(new pirata(salaRandom));
		}
		c.gotoxy(15, aux++);
		cout << "A sua nave foi invadida por " << nPiratas << " Piratas";
	}
	system("PAUSE");
	c.setTextSize(13, 13);
}

void AtaqueXenomorfos(nave* n, Consola c){
	int salaRandom = numeroAleatorio(0, 11);
	int randomXenomorfo = numeroAleatorio(0, 2);

	int aux = 15;

	c.setBackgroundColor(c.ROXO);
	c.clrscr();
	c.setTextColor(c.PRETO);

	c.gotoxy(25, 4);
	cout << "PERIGO!!";
	c.gotoxy(12, 7);
	cout << "PERIGO!!";

	c.gotoxy(60, 10);
	cout << "PERIGO!!";
	c.gotoxy(75, 13);
	cout << "PERIGO!!";

	c.setTextColor(c.BRANCO);
	c.gotoxy(30, 9);
	cout << "ATAQUE DE XENOMORFOS!!";
	c.gotoxy(15, aux++);
	cout << "A sua nave foi embarcado por um";

	switch (randomXenomorfo){
	case 0:
		n->getSala(salaRandom)->addXenomorfo(new geigermorfo(salaRandom));
		cout << " Geigermorfo";
		break;
	case 1:
		n->getSala(salaRandom)->addXenomorfo(new blob(salaRandom));
		cout << " Blob";
		break;
	case 2:
		n->getSala(salaRandom)->addXenomorfo(new mxyzypykwi(salaRandom));
		cout << " Mxyzypykwi";
		break;
	}
	c.gotoxy(15, aux++);
	system("PAUSE");
	c.setTextSize(13, 13);
}
