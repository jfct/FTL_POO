#pragma once
#include "Interface.h"
#include <string>



Interface::Interface(){};

void Interface::displaysalas(){

		c.gotoxy(46, 25);
		cout << "1)Beliche";
		c.gotoxy(46, 26);
		cout << "2)Propulsor Adicional";
		c.gotoxy(46, 27);
		cout << "3)Raio Laser";

		c.gotoxy(46, 29);
		cout << "4)Auto-Reparador";
		c.gotoxy(46, 30);
		cout << "5)Segurança Interna";
		c.gotoxy(46, 31);
		cout << "6)Enfermaria";

		c.gotoxy(46, 33);
		cout << "7)Sala de Armas";
		c.gotoxy(46, 34);
		cout << "8)Alojamento de Capitao";
		c.gotoxy(46, 35);
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

void Interface::desenhaNave(){
	int tamanho = tamanhocelula + 4;

	c.setBackgroundColor(c.BRANCO);
	limpaEcra();

	//1 linha
	c.drawSquare(tamanho, 13, tamanhocelula, RGB(128, 128, 128), 1);

	c.drawSquare(tamanho * 2, 13, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 3, 13, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 4, 13, tamanhocelula, RGB(128, 128, 128), 1);

	//2 linha
	c.drawSquare(tamanho * 2, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 3, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 4, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 5, 12 + 1 + tamanhocelula + 4, tamanhocelula, RGB(128, 128, 128), 1);
	//c.gotoxy(54, 2);
	//cout << "123" << endl << endl;

	//3 linha
	c.drawSquare(tamanho, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 2, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 3, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);
	c.drawSquare(tamanho * 4, 13 + tamanho * 2, tamanhocelula, RGB(128, 128, 128), 1);
};

void Interface::desenhaInformacao(){

	c.setBackgroundColor(c.CINZENTO);
	c.setTextColor(c.PRETO);

	
	// 1 linha
	c.gotoxy(18, 1);
	cout << "Propulsor" << endl;
	c.gotoxy(18, 3);
	cout << "Saude: 100";

	c.gotoxy(18+17, 1);
	cout << "123";
	c.gotoxy(18+17+17, 1);
	cout << "Propulsor";
	c.gotoxy(18 + 17 + 17 + 17, 1);
	cout << "Auto Reparador";
	// 2 linha
	c.gotoxy(18 + 17, 9);
	cout << "Sala Maquinas";
	c.gotoxy(18 + 17 + 17, 9);
	cout << "Sup de Vida";
	c.gotoxy(18 + 17 + 17 + 17, 9);
	cout << "Ctrl Escudo";
	c.gotoxy(18 + 17 + 17 + 17 + 17, 9);
	cout << "Ponte";
	// 3 linha
	c.gotoxy(18, 17);
	cout << "Ctrl de Escudo";
	c.gotoxy(18 + 17, 17);
	cout << "123";
	c.gotoxy(18 + 17 + 17, 17);
	cout << "Propulsor";
	c.gotoxy(18 + 17 + 17 + 17, 17);
	cout << "Propulsor";
};

void Interface::desenhaSalaNumero(vector<int> vectopcao){
	
	int numero = 1;
	int flag = 0;
	c.setBackgroundColor(c.CINZENTO);

	for (int i = 0; i < vectopcao.size() ; i++){
		if (numero < 4){
			c.gotoxy(18 + 17 * (numero), 1);
			cout << getNome(getTipo(vectopcao.at(i)));
		}
		else{
			c.gotoxy(18 + 17 * (numero-7), 17);
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

	for (int i = 0; i < 12; i++){
		s = n->getSala(i);

		if (s == NULL)
			cout << "Erro";
		else{
			if (i < 4){
				c.gotoxy(18 + 17 * (i), 1);
				cout << getNome(s->getId());
				c.gotoxy(18 + 17 * (i), 3);
				cout << "Saude" << s->getIntegridade();
				c.gotoxy(18 + 17 * (i), 4);
				cout << "Oxigenio:" << s->getOxigenio();
			}
			else
				if (i >= 4 && i < 8){
					c.gotoxy(18 + 17 + 17 + 17 * (i - 5), 9);
					cout << getNome(s->getId());
					c.gotoxy(18 + 17 + 17 + 17 * (i - 5), 11);
					cout << "Saude" << s->getIntegridade();
					c.gotoxy(18 + 17 + 17 + 17 * (i - 5), 12);
					cout << "Oxigenio:" << s->getOxigenio();
				}
				else{
					c.gotoxy(18 + 17 * (i - 8), 17);
					cout << getNome(s->getId());
					c.gotoxy(18 + 17 * (i - 8), 19);
					cout << "Saude" << s->getIntegridade();
					c.gotoxy(18 + 17 * (i - 8), 20);
					cout << "Oxigenio:" << s->getOxigenio();
				}
		}
	}
}

void Interface::desenhaTripulacao(nave* n){
	vector<unidade*> v;
	vector<unidade*>::const_iterator itu;

	v = n->getVU();

	for (itu = v.begin(); itu != v.end(); ++itu){
		if ((*itu) == NULL)
			cout << "Erro";
		else{
			if ((*itu)->getSala() < 4){
				c.gotoxy(18 + 17 * ((*itu)->getSala()), 5);
				if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
					c.setBackgroundColor(c.VERDE);
				else
					c.setBackgroundColor(c.VERMELHO);
				cout << (*itu)->getNomeUnidade();
				//c.gotoxy(18 + 17 * ((*itu)->getSala()), 7);
				//cout << "HP: " <<(*itu)->getSaude();
			}
			else
				if ((*itu)->getSala() >= 4 && (*itu)->getSala() < 8){
					c.gotoxy(18 + 17 + 17 + 17 * ((*itu)->getSala() - 5), 15);
					if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
						c.setBackgroundColor(c.VERDE);
					else
						c.setBackgroundColor(c.VERMELHO);
					cout << (*itu)->getNomeUnidade();
					//c.gotoxy(18 + 17 + 17 + 17 * ((*itu)->getSala() - 5), 15);
					//cout << "HP: " << (*itu)->getSaude();
				}
				else{
					c.gotoxy(18 + 17 * ((*itu)->getSala() - 8), 23);
					if ((*itu)->getSaude() > ((*itu)->getSaude() / 2))
						c.setBackgroundColor(c.VERDE);
					else
						c.setBackgroundColor(c.VERMELHO);
					cout << (*itu)->getNomeUnidade();
					//c.gotoxy(18 + 17 * ((*itu)->getSala() - 8), 25);
					//cout << "HP: " << (*itu)->getSaude();
				}
		}
	}
}

string Interface::getNome(int id){
	switch(id){
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