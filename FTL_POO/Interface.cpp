#pragma once
#include "Interface.h"
#include <string>



Interface::Interface(){};

// Mostra opcoes de sala
void Interface::displaysalas(){
	int aux = 29;
	c.gotoxy(46, aux++);
	cout << "1)Beliche";
	c.gotoxy(46, aux++);
	cout << "2)Propulsor Adicional";
	c.gotoxy(46, aux++);
	cout << "3)Raio Laser";

	aux++;
	aux++;

	c.gotoxy(46, aux++);
	cout << "4)Auto-Reparador";
	c.gotoxy(46, aux++);
	cout << "5)Segurança Interna";
	c.gotoxy(46, aux++);
	cout << "6)Enfermaria";

	aux++;
	aux++;

	c.gotoxy(46, aux++);
	cout << "7)Sala de Armas";
	c.gotoxy(46, aux++);
	cout << "8)Alojamento de Capitao";
	c.gotoxy(46, aux++);
	cout << "9)Oficina de Robot";
}

void Interface::limpaEcra(){
	c.clrscr();
};

void Interface::desenhaMenuOpcao(int i){
	int tamanho = tamanhocelula + 4;

	//1 linha
	c.drawSquare(tamanho, 13, tamanhocelula, RGB(128, 128, 128), 1);

	if (i == 2){
		c.drawSquare(tamanho * 2, 13, tamanhocelula, RGB(255, 255, 102), 1);
	}
	else
		c.drawSquare(tamanho * 2, 13, tamanhocelula, RGB(128, 128, 128), 1);

	if (i == 3)
		c.drawSquare(tamanho * 3, 13, tamanhocelula, RGB(255, 255, 102), 1);
	else
		c.drawSquare(tamanho * 3, 13, tamanhocelula, RGB(128, 128, 128), 1);

	if (i == 4)
		c.drawSquare(tamanho * 4, 13, tamanhocelula, RGB(255, 255, 102), 1);
	else
		c.drawSquare(tamanho * 4, 13, tamanhocelula, RGB(128, 128, 128), 1);

	//2 linha
	c.drawSquare(tamanho * 2, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 3, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 4, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 5, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);


	//3 linha
	c.drawSquare(tamanho, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);

	if (i == 9)
		c.drawSquare(tamanho * 2, 13 + tamanho * 2, tamanhocelula, RGB(255, 255, 102), 1);
	else
		c.drawSquare(tamanho * 2, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);

	if (i == 10)
		c.drawSquare(tamanho * 3, 13 + tamanho * 2, tamanhocelula, RGB(255, 255, 102), 1);
	else
		c.drawSquare(tamanho * 3, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);

	if (i == 11)
		c.drawSquare(tamanho * 4, 13 + tamanho * 2, tamanhocelula, RGB(255, 255, 102), 1);
	else
		c.drawSquare(tamanho * 4, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);
}

void Interface::desenhaNave(nave* n){
	int tamanho = tamanhocelula + 4;

	c.setBackgroundColor(c.PRETO);
	limpaEcra();

	//1 linha
	//sala 0
	c.drawSquare(tamanho, 13, tamanhocelula, cores(n, 0), 1);


	//sala 1
	c.drawSquare(tamanho * 2, 13, tamanhocelula, cores(n, 1), 1);
	//sala 2
	c.drawSquare(tamanho * 3, 13, tamanhocelula, cores(n, 2), 1);
	//sala 3
	c.drawSquare(tamanho * 4, 13, tamanhocelula, cores(n, 3), 1);

	//2 linha
	//sala 4
	c.drawSquare(tamanho * 2, 12 + 1 + tamanhocelula + 4, tamanhocelula, cores(n, 4), 1);
	//sala 5
	c.drawSquare(tamanho * 3, 12 + 1 + tamanhocelula + 4, tamanhocelula, cores(n, 5), 1);
	//sala 6
	c.drawSquare(tamanho * 4, 12 + 1 + tamanhocelula + 4, tamanhocelula, cores(n, 6), 1);
	//sala 7
	c.drawSquare(tamanho * 5, 12 + 1 + tamanhocelula + 4, tamanhocelula, cores(n, 7), 1);

	//3 linha
	//sala 8
	c.drawSquare(tamanho, 13 + tamanho * 2, tamanhocelula, cores(n, 8), 1);
	//sala 9
	c.drawSquare(tamanho * 2, 13 + tamanho * 2, tamanhocelula, cores(n, 9), 1);
	//sala 10
	c.drawSquare(tamanho * 3, 13 + tamanho * 2, tamanhocelula, cores(n, 10), 1);
	//sala 11
	c.drawSquare(tamanho * 4, 13 + tamanho * 2, tamanhocelula, cores(n, 11), 1);
};

int Interface::cores(nave* n, int pos){
	// Fogo - 255, 139, 81
	// CC - 81,116,255
	// Brecha - 255,233,81

	if (n->getSala(pos)->getEstado() == 0)
		return RGB(128, 128, 128);
	if (n->getSala(pos)->getEstado() == FOGO)
		return RGB(255, 139, 81);
	if (n->getSala(pos)->getEstado() == BRECHA)
		return RGB(255, 233, 81);
	if (n->getSala(pos)->getEstado() == CURTOCIRCUITO)
		return RGB(81, 116, 255);
}

void Interface::desenhaInformacao(nave* n, game* g){

	int contador = 0;

	// Buscar informação do vector unidades
	vector<unidade*> vu;
	vector<unidade*>::const_iterator itu;

	vector<sala*> vs = n->getVS();
	vector<sala*>::const_iterator it;

	c.setBackgroundColor(c.PRETO);
	c.setTextColor(c.BRANCO);


	c.gotoxy(106, 4);
	cout << "Informacao";

	// Mostrar Tick atual
	c.gotoxy(130, 4);
	c.setBackgroundColor(c.PRETO);
	c.setTextColor(c.VERMELHO_CLARO);
	cout << "Turno: " << g->getTick();

	// Cor original
	c.setBackgroundColor(c.PRETO);
	c.setTextColor(c.BRANCO);

	// Desenho da box de informação
	c.gotoxy(104, 5);
	cout << (char)218;
	for (int i = 0; i < 35; i++)
		cout << (char)196;
	cout << (char)191 << '\n';

	c.gotoxy(104, 22);
	cout << (char)192;
	for (int i = 0; i < 35; i++)
		cout << (char)196;
	cout << (char)217 << '\n';

	c.gotoxy(116, 7);
	cout << "Nave " << n->getNome() << endl;
	c.gotoxy(106, 8);
	c.setBackgroundColor(c.AZUL);
	cout << "Escudo: ";
	cout << n->getEscudo();
	c.setBackgroundColor(c.PRETO);
	c.gotoxy(106, 10);
	c.setTextColor(c.AMARELO);
	cout << "Anos de Luz Restantes: " << g->getObjectivo();
	c.setTextColor(c.BRANCO);
	c.gotoxy(106, 11);
	cout << "Tripulacao:";
	c.gotoxy(106, 23);
	cout << "Inimigos/Xenomorfos";

	int linha = 13;
	int linha2 = 25;
	int linha3 = 25;
		for (it = vs.begin(); it != vs.end(); ++it){
			// Informacao de VU
			if (n->getSala(contador)->getVU().size() > 0)
			{
				vu = n->getSala(contador)->getVU();
				for (itu = vu.begin(); itu != vu.end(); ++itu)
				{
					c.gotoxy(108, linha);
					cout << getNomeUnidade((*itu)->getTipo()) << " (" << (*itu)->getNumero() << ")    ";
					if ((*itu)->getSaude() < ((*itu)->getSaudeMax() / 2))
						c.setBackgroundColor(c.VERMELHO);
					else
					{
						cout << "\t";
						c.setBackgroundColor(c.VERDE);
						cout << "Saude:" << (*itu)->getSaude() << "\n";
					}
					c.setBackgroundColor(c.PRETO);
					linha++;
				}
			}
			// Informacao de VI
			if (n->getSala(contador)->getVI().size() > 0)
			{
				vu = n->getSala(contador)->getVI();
				for (itu = vu.begin(); itu != vu.end(); ++itu)
				{
					c.gotoxy(90, linha2);
					cout << getNomeUnidade((*itu)->getTipo()) << " (" << (*itu)->getNumero() << ")    ";
					if ((*itu)->getSaude() < ((*itu)->getSaudeMax() / 2))
						c.setBackgroundColor(c.VERMELHO);
					else
					{
						cout << "\t";
						c.setBackgroundColor(c.VERDE);
						cout << "Saude:" << (*itu)->getSaude() << "\n";
					}
					c.setBackgroundColor(c.PRETO);
					linha2++;
				}
			}
			// Informacoes de VX
			if (n->getSala(contador)->getVX().size() > 0)
			{
				vu = n->getSala(contador)->getVX();
				for (itu = vu.begin(); itu != vu.end(); ++itu)
				{
					c.gotoxy(128, linha3);
					cout << getNomeUnidade((*itu)->getTipo()) << " (" << (*itu)->getNumero() << ")    ";
					if ((*itu)->getSaude() < ((*itu)->getSaudeMax() / 2))
						c.setBackgroundColor(c.VERMELHO);
					else
					{
						cout << "\t";
						c.setBackgroundColor(c.VERDE);
						cout << "Saude:" << (*itu)->getSaude() << "\n";
					}
					c.setBackgroundColor(c.PRETO);
					linha3++;
				}
			}
			contador++;
		}
};

void Interface::desenhaSalaNumero(vector<int> vectopcao){

	int numero = 1;
	int flag = 0;
	c.setBackgroundColor(c.CINZENTO);

	for (size_t i = 0; i < vectopcao.size(); i++){
		if (numero < 4){
			c.gotoxy(18 + 17 * (numero), 1);
			cout << getNome(getTipo(vectopcao.at(i)));
		}
		else{
			c.gotoxy(18 + 17 * (numero - 7), 17);
			cout << getNome(getTipo(vectopcao.at(i)));
		}
		numero++;
		if (numero > 3 && flag == 0){
			numero = 8;
			flag = 1;
		}
	}
}

void Interface::desenhaSala(nave* n){
	sala* s;

	c.setBackgroundColor(c.CINZENTO);
	c.setTextColor(c.PRETO);
	for (int i = 0; i < 12; i++){
		s = n->getSala(i);

		if (s == NULL)
			cout << "Erro";
		else{
			if (i < 4){
				c.gotoxy(18 + 17 * (i), 1);
				cout << getNome(s->getId());
				c.gotoxy(18 + 17 * (i), 3);
				if (s->getSaude() <= 30){
					c.setBackgroundColor(c.VERMELHO);
					cout << "Saude: " << s->getSaude();
					c.setBackgroundColor(c.CINZENTO);
				}
				else
					if (s->getSaude() < 100 && s->getSaude() > 30){
						c.setBackgroundColor(c.AMARELO);
						cout << "Saude: " << s->getSaude();
						c.setBackgroundColor(c.CINZENTO);
					}
					else
						cout << "Saude: " << s->getSaude();

				c.gotoxy(18 + 17 * (i), 4);
				cout << "Oxigenio:" << s->getOxigenio();
			}
			else
				if (i >= 4 && i < 8){
					c.gotoxy(18 + 17 + 17 + 17 * (i - 5), 9);
					cout << getNome(s->getId());
					c.gotoxy(18 + 17 + 17 + 17 * (i - 5), 11);
					if (s->getSaude() <= 30){
						c.setBackgroundColor(c.VERMELHO);
						cout << "Saude: " << s->getSaude();
						c.setBackgroundColor(c.CINZENTO);
					}
					else
						if (s->getSaude() < 100 && s->getSaude() > 30){
							c.setBackgroundColor(c.AMARELO);
							cout << "Saude: " << s->getSaude();
							c.setBackgroundColor(c.CINZENTO);
						}
						else
							cout << "Saude: " << s->getSaude();
					c.gotoxy(18 + 17 + 17 + 17 * (i - 5), 12);
					cout << "Oxigenio:" << s->getOxigenio();
				}
				else{
					c.gotoxy(18 + 17 * (i - 8), 17);
					cout << getNome(s->getId());
					c.gotoxy(18 + 17 * (i - 8), 19);
					if (s->getSaude() <= 30){
						c.setBackgroundColor(c.VERMELHO);
						cout << "Saude: " << s->getSaude();
						c.setBackgroundColor(c.CINZENTO);
					}
					else
						if (s->getSaude() < 100 && s->getSaude() > 30){
							c.setBackgroundColor(c.AMARELO);
							cout << "Saude: " << s->getSaude();
							c.setBackgroundColor(c.CINZENTO);
						}
						else
							cout << "Saude: " << s->getSaude();
					c.gotoxy(18 + 17 * (i - 8), 20);
					cout << "Oxigenio:" << s->getOxigenio();
				}
		}
	}
}

void Interface::desenhaTripulacao(nave* n){
	vector<unidade*> v;
	vector<unidade*>::const_iterator itu;

	vector<sala*> vs;
	vector<sala*>::const_iterator it;


	//vs = n->getVS();
	//v = n->getVU();

	for (size_t i = 0; i < n->getVS().size(); i++)
	{
		// Apanha vector unidade na Sala
		v = n->getSala(i)->getVU();


		if (n->getSala(i)->getnTripulantes() > 0)
		{
			int aux = 0;
		for (itu = v.begin(); itu != v.end(); ++itu){
				if ((*itu) == NULL){
					cout << "Erro";
					return;
				}
				else{
					// Comparar numero da sala da unidade com a sala actual
					if ((*itu)->getSala() == i){
						// 1 Linha
						if ((*itu)->getSala() < 4){
							c.gotoxy(18 + 17 * ((*itu)->getSala()) + (aux * 1), 5);
							if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
								c.setBackgroundColor(c.VERDE);
							else
								c.setBackgroundColor(c.VERMELHO);
							cout << (*itu)->getNomeUnidade();
						}
						// 2 Linha
						else
							if ((*itu)->getSala() >= 4 && (*itu)->getSala() < 8){
								c.gotoxy(18 + 17 + 17 + 17 * ((*itu)->getSala() - 5) + (aux * 1), 13);
								if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
									c.setBackgroundColor(c.VERDE);
								else
									c.setBackgroundColor(c.VERMELHO);
								cout << (*itu)->getNomeUnidade();
							}
						// 3 Linha
							else{
								c.gotoxy(18 + 17 * ((*itu)->getSala() - 8) + (aux * 1), 21);
								if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
									c.setBackgroundColor(c.VERDE);
								else
									c.setBackgroundColor(c.VERMELHO);
								cout << (*itu)->getNomeUnidade();
							}
							aux += 3;
					}
				}
			}
		}

	}
}

void Interface::desenhaInimigos(nave* n){
	vector<unidade*> v;
	vector<unidade*>::const_iterator itu;

	vector<sala*> vs;
	vector<sala*>::const_iterator it;


	//vs = n->getVS();
	//v = n->getVU();

	for (size_t i = 0; i < n->getVS().size(); i++)
	{
		// Apanha vector unidade na Sala
		v = n->getSala(i)->getVI();


		if (n->getSala(i)->getVI().size() > 0)
		{
			int aux = 0;
			for (itu = v.begin(); itu != v.end(); ++itu){
				if ((*itu) == NULL){
					cout << "Erro";
					return;
				}
				else{
					// Comparar numero da sala da unidade com a sala actual
					if ((*itu)->getSala() == i){
						// 1 Linha
						if ((*itu)->getSala() < 4){
							c.gotoxy(18 + 17 * ((*itu)->getSala()) + (aux * 1), 6);
							if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
								c.setBackgroundColor(c.VERDE);
							else
								c.setBackgroundColor(c.VERMELHO);
							cout << (*itu)->getNomeUnidade();
						}
						// 2 Linha
						else
							if ((*itu)->getSala() >= 4 && (*itu)->getSala() < 8){
								c.gotoxy(18 + 17 + 17 + 17 * ((*itu)->getSala() - 5) + (aux * 1), 14);
								if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
									c.setBackgroundColor(c.VERDE);
								else
									c.setBackgroundColor(c.VERMELHO);
								cout << (*itu)->getNomeUnidade();
							}
						// 3 Linha
							else{
								c.gotoxy(18 + 17 * ((*itu)->getSala() - 8) + (aux * 1), 22);
								if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
									c.setBackgroundColor(c.VERDE);
								else
									c.setBackgroundColor(c.VERMELHO);
								cout << (*itu)->getNomeUnidade();
							}
							aux += 3;
					}
				}
			}
		}

	}
}

void Interface::desenhaXenomorfos(nave* n){
	vector<unidade*> v;
	vector<unidade*>::const_iterator itu;

	vector<sala*> vs;
	vector<sala*>::const_iterator it;

	for (size_t i = 0; i < n->getVS().size(); i++)
	{
		// Apanha vector Xenomorfo na Sala
		v = n->getSala(i)->getVX();


		if (n->getSala(i)->getVX().size() > 0)
		{
			int aux = 0;
			for (itu = v.begin(); itu != v.end(); ++itu){
				if ((*itu) == NULL){
					cout << "Erro";
					return;
				}
				else{
					// Comparar numero da sala da unidade com a sala actual
					if ((*itu)->getSala() == i && (*itu)->getVisivel()==1){
						// 1 Linha
						if ((*itu)->getSala() < 4){
							c.gotoxy(18 + 17 * ((*itu)->getSala()) + (aux * 1), 7);
							if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
								c.setBackgroundColor(c.VERDE);
							else
								c.setBackgroundColor(c.VERMELHO);
							cout << (*itu)->getNomeUnidade();
						}
						// 2 Linha
						else
							if ((*itu)->getSala() >= 4 && (*itu)->getSala() < 8){
								c.gotoxy(18 + 17 + 17 + 17 * ((*itu)->getSala() - 5) + (aux * 1), 15);
								if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
									c.setBackgroundColor(c.VERDE);
								else
									c.setBackgroundColor(c.VERMELHO);
								cout << (*itu)->getNomeUnidade();
							}
						// 3 Linha
							else{
								c.gotoxy(18 + 17 * ((*itu)->getSala() - 8) + (aux * 1), 23);
								if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
									c.setBackgroundColor(c.VERDE);
								else
									c.setBackgroundColor(c.VERMELHO);
								cout << (*itu)->getNomeUnidade();
							}
							aux += 3;
					}
				}
			}
		}

	}
}

string Interface::getNome(int id){
	switch (id){
	case PONTE:
		return "Ponte";
		break;
	case SUPORTEDEVIDA:
		return "Sup. Vida";
		break;
	case CONSTROLODEESCUDO:
		return "Ctrl Escudo";
		break;
	case SALADASMAQUINAS:
		return "Sala Maquina";
		break;
	case PROPULSOR:
		return "Propulsor";
		break;
	case BELICHE:
		return "Beliche";
		break;
	case RAIOLASER:
		return "Raio Laser";
		break;
	case AUTOREPARADOR:
		return "AutoReparador";
		break;
	case SEGURANCAINTERNA:
		return "Seg Interna";
		break;
	case ENFERMARIA:
		return "Enfermaria";
		break;
	case SALADEARMAS:
		return "Sala Armas";
		break;
	case ALOJAMENTOCAPITAO:
		return "Quarto Capitao";
		break;
	case OFICINA:
		return "Oficina";
		break;
	default:
		return "Erro";
		break;
	}
	return "Erro";
}

string Interface::getNomeUnidade(int id){
	switch (id){
	case MEMBRO:
		return "Membro";
		break;
	case CAPITAO:
		return "Capitao";
		break;
	case ROBOT:
		return "Robot";
		break;
	case PIRATA:
		return "Pirata";
		break;
	case GEIGERMORFO:
		return "Geigermorfo";
		break;
	case CASULO:
		return "Casulo";
		break;
	case BLOBE:
		return "Blobe";
		break;
	case MXYZYPYKWI:
		return "Mxyzypykwi";
		break;
	default:
		break;
	}
	return "ERRO";
}

int Interface::getTipo(int opcao){
	switch (opcao){
	case 1:
		return BELICHE;
		break;
	case 2:
		return PROPULSOR;
		break;
	case 3:
		return RAIOLASER;
		break;
	case 4:
		return AUTOREPARADOR;
		break;
	case 5:
		return SEGURANCAINTERNA;
		break;
	case 6:
		return ENFERMARIA;
		break;
	case 7:
		return SALADEARMAS;
		break;
	case 8:
		return ALOJAMENTOCAPITAO;
		break;
	case 9:
		return OFICINA;
		break;
	default:
		cout << "Não existe essa sala";
		break;
	}
	return 0;
}