#pragma once
#include "main.h"
#include <algorithm>

extern int dificuldade;

extern int linhaRelatorio = 24;

bool isNumber(string buffer)
{
	for (string::reverse_iterator i = buffer.rbegin(); i != buffer.rend(); ++i)
	{
		if (!isdigit(*i))
		{
			return false;
		}
	}
	return true;
}

string convertToUpper(string data)
{
	transform(data.begin(), data.end(), data.begin(), ::toupper);
	return data;
}

vector<string> separaPalavras(string frase)
{
	string buf;
	stringstream ss(frase);
	vector<string> palavras;
	while (ss >> buf)
	{
		buf = convertToUpper(buf);
		palavras.push_back(buf);
	}
	return palavras;
}

void addSalaTipo(nave* n, int opcao){
	switch (opcao){
	case 1:
		n->addSala(BELICHE);
		break;
	case 2:
		n->addSala(PROPULSOR);
		break;
	case 3:
		n->addSala(RAIOLASER);
		break;
	case 4:
		n->addSala(AUTOREPARADOR);
		break;
	case 5:
		n->addSala(SEGURANCAINTERNA);
		break;
	case 6:
		n->addSala(ENFERMARIA);
		break;
	case 7:
		n->addSala(SALADEARMAS);
		break;
	case 8:
		n->addSala(ALOJAMENTOCAPITAO);
		break;
	case 9:
		n->addSala(OFICINA);
		break;
	default:
		cout << "Não existe essa sala";
		break;
	}
}

void addAdjacente(nave* n, int sala){

	switch (sala)
	{
	case 0:
		n->getSala(0)->addAdjacente(1);
		break;
	case 1:
		n->getSala(1)->addAdjacente(0);
		n->getSala(1)->addAdjacente(2);
		n->getSala(1)->addAdjacente(4);
		break;
	case 2:
		n->getSala(2)->addAdjacente(1);
		n->getSala(2)->addAdjacente(3);
		n->getSala(2)->addAdjacente(5);
		break;
	case 3:
		n->getSala(3)->addAdjacente(2);
		n->getSala(3)->addAdjacente(6);
		break;
	case 4:
		n->getSala(4)->addAdjacente(1);
		n->getSala(4)->addAdjacente(9);
		n->getSala(4)->addAdjacente(5);
		break;
	case 5:
		n->getSala(5)->addAdjacente(2);
		n->getSala(5)->addAdjacente(4);
		n->getSala(5)->addAdjacente(6);
		n->getSala(5)->addAdjacente(10);
		break;
	case 6:
		n->getSala(6)->addAdjacente(3);
		n->getSala(6)->addAdjacente(5);
		n->getSala(6)->addAdjacente(7);
		n->getSala(6)->addAdjacente(11);
		break;
	case 7:
		n->getSala(7)->addAdjacente(6);
		break;
	case 8:
		n->getSala(8)->addAdjacente(9);
		break;
	case 9:
		n->getSala(9)->addAdjacente(4);
		n->getSala(9)->addAdjacente(8);
		n->getSala(9)->addAdjacente(10);
		break;
	case 10:
		n->getSala(10)->addAdjacente(5);
		n->getSala(10)->addAdjacente(9);
		n->getSala(10)->addAdjacente(11);
		break;
	case 11:
		n->getSala(11)->addAdjacente(6);
		n->getSala(11)->addAdjacente(10);
		break;
	default:
		break;
	}
}

void inicializarNave(nave* n, Consola c){
	//Consola c;
	Interface in;
	vector<int>vectopcao;
	string opcao;

	int flag = 0;
	// Flag para saber sala que foi criada

	n->setEscudo(100);
	n->addSala(PROPULSOR);

	c.setBackgroundColor(c.BRANCO);
	c.setTextColor(c.PRETO);
	in.displaysalas();

	for (int i = 1; i < 4; i++)
	{
		in.limpaEcra();
		in.displaysalas();
		in.desenhaMenuOpcao(i + 1);
		if (flag == 1)
			in.desenhaSalaNumero(vectopcao);
		do{
			c.gotoxy(15, 30);
			c.setBackgroundColor(c.BRANCO);
			cout << "Indique Sala " << ":";
			colocaOrdem();
			cout << "               ";
			colocaOrdem();
			cin.clear();
			fflush(stdin);
			getline(cin, opcao);

		} while (atoi(opcao.c_str()) < 1 || atoi(opcao.c_str()) > 9);
		vectopcao.push_back(atoi(opcao.c_str()));
		addSalaTipo(n, atoi(opcao.c_str()));

		flag = 1;
	}

	n->addSala(SALADASMAQUINAS);
	n->addSala(SUPORTEDEVIDA);
	n->addSala(CONSTROLODEESCUDO);
	n->addSala(PONTE);
	n->addSala(PROPULSOR);

	for (int i = 8; i < 11; i++)
	{
		in.limpaEcra();
		in.displaysalas();
		in.desenhaMenuOpcao(i + 1);
		if (flag == 1)
			in.desenhaSalaNumero(vectopcao);
		do{
			c.gotoxy(15, 30);
			c.setBackgroundColor(c.BRANCO);
			cout << "Indique Sala " << ":";
			colocaOrdem();
			cout << "               ";
			colocaOrdem();
			cin.clear();
			fflush(stdin);
			getline(cin, opcao);
		} while (atoi(opcao.c_str()) < 1 || atoi(opcao.c_str()) > 9);
		vectopcao.push_back(atoi(opcao.c_str()));
		addSalaTipo(n, atoi(opcao.c_str()));

		flag = 1;
	}
	n->atribuiNumero();
	for (int i = 0; i <= 11; i++)
		addAdjacente(n, i);
}

void inicializarTripulacao(nave* n, Consola c){
	string nSalas;
	int totalTripulantes = 3;
	int i = 0;
	int unique = 0;

	Interface in;
	vector<sala*> vs;
	vector<sala*>::const_iterator it;

	vs = n->getVS();


	for (it = vs.begin(); it != vs.end(); ++it){
		if ((*it)->getId() == BELICHE)
			totalTripulantes++;
		if ((*it)->getId() == ALOJAMENTOCAPITAO && unique == 0){
			c.gotoxy(15, 30);
			c.setBackgroundColor(c.PRETO);
			c.setTextColor(c.BRANCO);
			cout << "Em que sala pretende inserir o Capitao?";
			colocaOrdem();
			// Verifica Salas
			do{
				colocaOrdem();
				cout << "               ";
				colocaOrdem();
				cin.clear();
				fflush(stdin);
				getline(cin, nSalas);

				while (isdigit(nSalas[0]) == 0)
				{
					cin.clear();
					fflush(stdin);
					getline(cin, nSalas);
				}

			} while (nSalas[0] > 11 && nSalas[0] < 0);

			n->addUnidade(CAPITAO, atoi(nSalas.c_str()));
			vs[atoi(nSalas.c_str())]->setnTripulantes(vs[atoi(nSalas.c_str())]->getnTripulantes() + 1);
			unique = 1;
			i++;

			in.desenhaNave(n);
			c.setBackgroundColor(c.CINZENTO);
			c.setTextColor(c.PRETO);
			in.desenhaSala(n);
			in.desenhaTripulacao(n);
		}

		if ((*it)->getId() == OFICINA){
			c.gotoxy(15, 30);
			c.setBackgroundColor(c.PRETO);
			c.setTextColor(c.BRANCO);
			cout << "Em que sala pretende inserir o Robot?";
			colocaOrdem();
			// Verifica Salas
			do{
				colocaOrdem();
				cout << "               ";
				colocaOrdem();
				cin.clear();
				fflush(stdin);
				getline(cin, nSalas);

				while (isdigit(nSalas[0]) == 0)
				{
					cin.clear();
					fflush(stdin);
					getline(cin, nSalas);
				}

			} while (nSalas[0] > 11 && nSalas[0] < 0);

			n->addUnidade(ROBOT, atoi(nSalas.c_str()));
			vs[atoi(nSalas.c_str())]->setnTripulantes(vs[atoi(nSalas.c_str())]->getnTripulantes() + 1);
			i++;

			in.desenhaNave(n);
			c.setBackgroundColor(c.CINZENTO);
			c.setTextColor(c.PRETO);
			in.desenhaSala(n);
			in.desenhaTripulacao(n);
		}
	}

	for (; i < totalTripulantes; i++){

		c.gotoxy(15, 30);
		c.setBackgroundColor(c.PRETO);
		c.setTextColor(c.BRANCO);
		cout << "Em que sala pretende inserir o Membro?";
		colocaOrdem();
		// Verifica Salas
		string nSalas;
		do{
			colocaOrdem();
			cout << "               ";
			colocaOrdem();
			cin.clear();
			fflush(stdin);
			getline(cin, nSalas);

			while (isdigit(nSalas[0]) == 0)
			{
				cin.clear();
				fflush(stdin);
				getline(cin, nSalas);
			}

		} while (nSalas[0] > 11 && nSalas[0] < 0);

		n->addUnidade(MEMBRO, atoi(nSalas.c_str()));
		vs[atoi(nSalas.c_str())]->setnTripulantes(vs[atoi(nSalas.c_str())]->getnTripulantes() + 1);

		in.desenhaNave(n);
		c.setBackgroundColor(c.CINZENTO);
		c.setTextColor(c.PRETO);
		in.desenhaSala(n);
		in.desenhaTripulacao(n);
	}
	n->addNTripulantes(totalTripulantes);
}

nave* inicioJogo(){
	Interface in;
	Consola c;
	nave* n = new nave();
	string nome;
	int opcaoEscolhida;

	titulo();
	c.gotoxy(15, 30);
	cout << "Indique o nome da sua nave!";
	colocaOrdem();
	cin.clear();
	fflush(stdin);
	getline(cin, nome);
	n->setNome(nome);

	c.clrscr();

	c.gotoxy(20, 15);
	cout << "Selecione o nivel de dificuldade:" << endl;
	c.gotoxy(20, 16);
	cout << "1) Facil" << endl;
	c.gotoxy(20, 17);
	cout << "2) Dificil" << endl;
	c.gotoxy(20, 18);
	cout << "3) Muito Dificil" << endl;
	c.gotoxy(20, 19);
	cout << "4) Só o Joel passou este modo";

	do{
		colocaOrdem();
		cin >> opcaoEscolhida;
	} while (opcaoEscolhida < 1 && opcaoEscolhida > 4);

	switch (opcaoEscolhida){
	case 1:
		n->setDificuldade(1);
		break;
	case 2:
		n->setDificuldade(2);
		break;
	case 3:
		n->setDificuldade(6);
		break;
	case 4:
		n->setDificuldade(20);
		break;
	}

	inicializarNave(n, c);
	// Diminui de volta o textsize para o normal
	c.setTextSize(13, 13);
	// Começa os desenhos de interface
	in.desenhaNave(n);
	// Confere ao texto as caracteristicas para assimilar ao fundo
	c.setBackgroundColor(c.CINZENTO);
	c.setTextColor(c.PRETO);
	// Passa ao desenho da sala

	in.desenhaSala(n);
	inicializarTripulacao(n, c);

	c.setBackgroundColor(c.CINZENTO);
	in.desenhaTripulacao(n);
	return n;
}

// Funcao para mover unidades
// Parametros: nave, vector de salas, sala em que se encontra, sala destino, posicao da unidade
void moveUnidade(nave* n, vector<sala*> vs, sala* salaActual, int destino, int posicao){

	// Diminuir nTripulantes da sala Actual
	salaActual->setnTripulantes(salaActual->getnTripulantes() - 1);
	// Aumentar nTripulantes
	vs[destino]->setnTripulantes(vs[destino]->getnTripulantes() + 1);
	// Faz cópia
	unidade* copia = salaActual->getVU().at(posicao);
	// Insere sala correcta na copia
	copia->setSala(destino);
	// Remove a antiga
	n->getSala(salaActual->getNumero())->removeUnidade(salaActual->getVU().at(posicao), salaActual->getVU().at(posicao)->getNumero());
	// Adiciona uma copia a sala onde pretende ir
	n->getSala(destino)->addUnidade(copia);
}

// Funcao para mover Xenomorfos
// Parametros: nave, vector de salas, sala em que se encontra, sala destino, posicao da unidade
void moveXenomorfo(nave* n, vector<sala*> vs, sala* salaActual, int destino, int posicao){

	// Faz cópia
	unidade* copia = salaActual->getVX().at(posicao);
	// Insere sala correcta na copia
	copia->setSala(destino);
	// Remove a antiga
	n->getSala(salaActual->getNumero())->removeXenomorfo(salaActual->getVX().at(posicao), salaActual->getVX().at(posicao)->getNumero());
	// Adiciona uma copia a sala onde pretende ir
	n->getSala(destino)->addXenomorfo(copia);
}

// Funcao para mover Xenomorfos
// Parametros: nave, vector de salas, sala em que se encontra, sala destino, posicao da unidade
void moveInimigo(nave* n, vector<sala*> vs, sala* salaActual, int destino, int posicao){

	// Faz cópia
	unidade* copia = salaActual->getVI().at(posicao);
	// Insere sala correcta na copia
	copia->setSala(destino);
	// Remove a antiga
	n->getSala(salaActual->getNumero())->removeInimigo(salaActual->getVI().at(posicao), salaActual->getVI().at(posicao)->getNumero());
	// Adiciona uma copia a sala onde pretende ir
	n->getSala(destino)->addInimigo(copia);
}

int ordens(nave* n){
	string ordem;
	//int nSala;
	vector<string> p;
	vector<unidade*> vu;
	vector<sala*> vs;

	Consola c;

	getline(cin, ordem);

	while (ordem == "")
	{
		cin.clear();
		fflush(stdin);
		ws(cin);
		getline(cin, ordem);
	}

	//cout << ordem;

	//Separa palavras dentro da string
	p = separaPalavras(ordem);

	/*char *a = new char[ordem.size() + 1];
	a[ordem.size()] = 0;
	memcpy(a, ordem.c_str(), ordem.size());*/

	/*nSala = (int)a[1];*/

	vu = n->getVU();
	vs = n->getVS();

	string s = p[0];
	// Passa para Uppercase
	transform(s.begin(), s.end(), s.begin(), toupper);

	// Compara ordem
	if (s.compare("MOVER") == 0 && p.size() == 3){
		for (size_t i = 0; i < vs.size(); i++)
		{
			sala* salaActual = vs[i];
			for (size_t i = 0; i < salaActual->getVU().size(); i++)
				if (p[1].compare(salaActual->getVU().at(i)->getNomeUnidade()) == 0)
				{
					//int probabilidade1 = numeroAleatorio1(0, salaActual->getVU().at(i)->getIndeciso());
					int probabilidade = numeroAleatorio1(0, 100);
					if (probabilidade < salaActual->getVU().at(i)->getIndeciso())
					{
						salaActual->getVU().at(i)->setMover(false);
					}

					if (salaActual->getVU().at(i)->getTipo() == ROBOT)
						if (salaActual->getEstado() == CURTOCIRCUITO || salaActual->getEstado2() == CURTOCIRCUITO)
						{
							salaActual->getVU().at(i)->setMover(false);
						}

					if (salaActual->getVU().at(i)->getMover())
					{
						// Modifica a sala da unidade
						if (isdigit(p[2][0]))
							if (atoi(p[2].c_str()) >= 0 && atoi(p[2].c_str()) < 12)
							{
								moveUnidade(n, vs, salaActual, atoi(p[2].c_str()), i);
								return 0;
							}
					}
					else
					{
						c.gotoxy(15, 30);
						cout << "\t" << "Unidade não se pode mover" << endl;
					}
				}
		}
	}
	else
		if (s.compare("AVANCAR") == 0){
			return 1;
		}
		else
		{
			cout << "\t" << "Ordem Incorreta" << endl;
			system("PAUSE");
		}
	return 0;
}

// Devolve 1 se pertencer
// Devolva 0 se nao pertencer
int pertence(sala* s, int destino){
	for (size_t i = 0; i < s->getAdjacente().size(); i++)
		if (s->getAdjacente().at(i) == destino)
			return 1;

	return 0;
}

void jogo(){
	Interface in;
	string ordem;
	game* g = new game();
	Consola c;
	nave* n;

	vector<unidade*>::const_iterator itu;
	
	int fim = 0;
	int inicio = 0;
	int avancar = 0;

	// Inicializa os Ticks a 0
	g->setTick(1);

	// Limpa e começa o jogo
	//in.limpaEcra();
	n = inicioJogo();

	// Inicializa o "Objectivo"
	g->setObjectivo(4000 + 1000 * (n->getDificuldade()));

	do{
		// Inicio do turno

		if (inicio == 0){
			g->setNave(n);
			inicioTurno(n);
			inicio = 1;
		}
		else
		{
			linhaRelatorio = 24;
			// Guarda a nave dentro da classe game
			g->setNave(n);

			// Faz reset a todas as variaveis
			for (int i = 0; i < 12; i++)
			{
				vector<unidade*> vu = n->getSala(i)->getVU();
				for (itu = vu.begin(); itu != vu.end(); ++itu)
				{
					(*itu)->setMover(true);
					(*itu)->setFinish(0);
				}
				vector<unidade*> vi = n->getSala(i)->getVI();
				for (itu = vu.begin(); itu != vu.end(); ++itu)
				{
					(*itu)->setMover(true);
					(*itu)->setJaMoveu(false);
					(*itu)->setFinish(0);
				}
				vector<unidade*> vx = n->getSala(i)->getVX();
				for (itu = vx.begin(); itu != vx.end(); ++itu)
				{
					(*itu)->setJaMoveu(false);
					(*itu)->setFinish(0);
				}
			}

			// Reset das cores
			// Coloca o texto ao natural
			colocaOrdem();
			c.setBackgroundColor(c.PRETO);
			c.setTextColor(c.BRANCO);

			cout << "Inicio turno" << endl;
			inicioTurno(n);

			system("PAUSE");

			// Faz reset a todas as variaveis
			for (int i = 0; i < 12; i++)
			{
				vector<unidade*> vu = n->getSala(i)->getVU();
				for (itu = vu.begin(); itu != vu.end(); ++itu)
				{
					(*itu)->setMover(true);
					(*itu)->setFinish(0);
				}
				vector<unidade*> vi = n->getSala(i)->getVI();
				for (itu = vi.begin(); itu != vi.end(); ++itu)
				{
					(*itu)->setMover(true);
					(*itu)->setFinish(0);
				}
				vector<unidade*> vx = n->getSala(i)->getVX();
				for (itu = vx.begin(); itu != vx.end(); ++itu)
				{
					(*itu)->setJaMoveu(false);
					(*itu)->setFinish(0);
				}
			}
		}
		while (avancar == 0){
			// Começa os desenhos de interface
			in.desenhaNave(n);
			// Confere ao texto as caracteristicas para igualar ao fundo
			c.setBackgroundColor(c.CINZENTO);
			c.setTextColor(c.PRETO);
			// Passa ao desenho da sala
			in.desenhaSala(n);
			c.setBackgroundColor(c.CINZENTO);
			in.desenhaTripulacao(n);
			in.desenhaInimigos(n);
			in.desenhaXenomorfos(n);

			// Mostrar menu lateral
			in.desenhaInformacao(n, g);

			// Coloca o texto ao natural
			c.setBackgroundColor(c.PRETO);
			c.setTextColor(c.BRANCO);

			c.gotoxy(15, 30);
			cout << "Digite o seu comando:";
			// Inserir Ordens
			colocaOrdem();
			avancar = ordens(n);
			if (avancar == 1)
			{
				g->setTick(g->getTick() + 1);

				// Reset das cores
				colocaOrdem();
				cout << "Fim turno" << endl;
				fim = fimTurno(g, n);
				if (fim  == 1)
				{
					c.setBackgroundColor(c.PRETO);
					c.clrscr();
					c.setBackgroundColor(c.VERDE);
					c.setTextColor(c.PRETO);
					c.gotoxy(20, 20);
					cout << "VOCE CHEGOU AO DESTINO!!!!!!!!";
					system("PAUSE");
					exit(0);
				}
				if (fim == 2){
					c.setBackgroundColor(c.BRANCO);
					c.clrscr();
					c.setBackgroundColor(c.VERMELHO);
					c.setTextColor(c.PRETO);
					c.gotoxy(20, 20);
					cout << "VOCE PERDEU O JOGO, A NAVE NAO CHEGOU AO DESTINO!!!!!";
					system("PAUSE");
					exit(0);
				}
				system("PAUSE");
			}

			c.setTextSize(13, 13);
			// Começa os desenhos de interface
			in.desenhaNave(n);
			// Confere ao texto as caracteristicas para igualar ao fundo
			c.setBackgroundColor(c.CINZENTO);
			c.setTextColor(c.PRETO);
			// Mostrar menu lateral
			in.desenhaInformacao(n, g);
			// Passa ao desenho da sala
			in.desenhaSala(n);
			c.setBackgroundColor(c.CINZENTO);
			in.desenhaTripulacao(n);
			in.desenhaInimigos(n);
			in.desenhaXenomorfos(n);
		}
		// Variavel avancar de novo a 0
		avancar = 0;

		//Caso seja turno correcto, efectuar um evento RANDOM
		int tick = g->getTick() % 5;
		if (tick == 0 || g->getTick() == 2)
			randomEvents(g, n, in, c);

	} while (!fim);

	c.setBackgroundColor(c.PRETO);
	c.clrscr();
	c.setBackgroundColor(c.VERDE);
	c.setTextColor(c.PRETO);
	c.gotoxy(20, 20);
	cout << "VOCE CHEGOU AO DESTINO!!!!!!!!";
}

int verficaPropulsao(nave* n){
	vector<sala*> vs;
	std::vector<sala*>::const_iterator it;

	int total = 0;

	vs = n->getVS();
	for (it = vs.begin(); it != vs.end(); ++it){
		if ((*it)->getId() == PROPULSOR)
			total += (*it)->getSaude();
	}
	return total;
}

void randomEvents(game* g, nave* n, Interface in, Consola c){

	switch (numeroAleatorio1(0, 3)){
	case 0:
		AtaquePiratas(n, c);
		break;
	case 1:
		PoCosmico(n, c);
		break;
	case 2:
		AtaqueXenomorfos(n, c);
		break;
	case 3:
		ChuvaMeteoritos(n, c);
		break;
	}
	c.setBackgroundColor(c.PRETO);
	c.clrscr();

	c.setTextSize(13, 13);
	// Começa os desenhos de interface
	in.desenhaNave(n);
	// Confere ao texto as caracteristicas para igualar ao fundo
	c.setBackgroundColor(c.CINZENTO);
	c.setTextColor(c.PRETO);
	// Passa ao desenho da sala
	in.desenhaSala(n);
	c.setBackgroundColor(c.CINZENTO);
	in.desenhaTripulacao(n);
}

int numeroAleatorio1(int min, int max)
{
	if ((max - min + 1) <= 0)
		return 0;
	return min + rand() % (max - min + 1);
};

void inicioTurno(nave* n){
	vector<unidade*>::const_iterator itu;
	vector<caracteristicas*>::const_iterator itc;

	// Efectua as funções de fim de turno
	for (int i = 0; i < 12; i++)
	{
		// Percorre Unidades e as suas caracteristicas
		vector<unidade*> vu = n->getSala(i)->getVU();
		for (itu = vu.begin(); itu != vu.end(); ++itu)
		{
			if ((*itu)->getFinish() == 0)
			{
				(*itu)->setFinish(1);
				vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
				for (itc = vc.begin(); itc != vc.end(); ++itc)
				{
					(*itc)->inicioTurno((*itu), n);
				}
			}
		}
		// Percorre Inimigos e as suas caracteristicas
		vector<unidade*> vi = n->getSala(i)->getVI();
		for (itu = vi.begin(); itu != vi.end(); ++itu)
		{
			if ((*itu)->getFinish() == 0)
			{
				(*itu)->setFinish(1);
				vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
				for (itc = vc.begin(); itc != vc.end(); ++itc)
				{
					(*itc)->inicioTurno((*itu), n);
				}
			}
		}
		// Percorre Xenomorfos e as suas caracteristicas
		vector<unidade*> vx = n->getSala(i)->getVX();
		for (itu = vx.begin(); itu != vx.end(); ++itu)
		{
			if ((*itu)->getFinish() == 0)
			{
				(*itu)->setFinish(1);
				vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
				for (itc = vc.begin(); itc != vc.end(); ++itc)
				{
					(*itc)->inicioTurno((*itu), n);
				}
			}
		}
	}

	// Remove unidades, caso estas estejam sem vida
	for (int i = 0; i < 12; i++)
	{
		vector<unidade*> vu = n->getSala(i)->getVU();
		for (itu = vu.begin(); itu != vu.end(); ++itu)
		{
			if ((*itu)->getSaude() <= 0)
				n->getSala(i)->removeUnidade((*itu), (*itu)->getNumero());
		}
		vector<unidade*> vi = n->getSala(i)->getVI();
		for (itu = vi.begin(); itu != vi.end(); ++itu)
		{
			if ((*itu)->getSaude() <= 0)
				n->getSala(i)->removeInimigo((*itu), (*itu)->getNumero());
		}
		vector<unidade*> vx = n->getSala(i)->getVX();
		for (itu = vx.begin(); itu != vx.end(); ++itu)
		{
			if ((*itu)->getSaude() <= 0)
				n->getSala(i)->removeInimigo((*itu), (*itu)->getNumero());
		}
	}
}

int fimTurno(game* g, nave* n){
	vector<unidade*> vu;
	vector<unidade*>::const_iterator itu;
	vector<caracteristicas*>::const_iterator itc;

	//vs = n->getVS();
	//vu = n->getVU();

	int propulsaoTotal = 0;


	// 1 EFEITOS AMBIENTAIS

	for (int s = 0; s < 12; s++)
	{
		int estado = n->getSala(s)->getEstado();
		int estado2 = n->getSala(s)->getEstado2();

		// CASO HAJA BRECHA
		if (estado == BRECHA || estado2 == BRECHA)
		{
			if (n->getSala(s)->getSaude() == 100)
			{
				if (estado == BRECHA)
					n->getSala(s)->setEstado(0);
				else
					n->getSala(s)->setEstado2(0);
			}
			else{
				n->getSala(s)->setOxigenio(0);
			}
		}

		// CASO HAJA FOGO
		if (estado == FOGO || estado2 == FOGO)
		{
			if (n->getSala(s)->getSaude() == 100)
			{
				if (estado == FOGO)
					n->getSala(s)->setEstado(0);
				else
					n->getSala(s)->setEstado2(0);
			}
			else{
				if (n->getSala(s)->getOxigenio() <= 0)
				{
					if (estado == FOGO)
						n->getSala(s)->setEstado(0);
					else
						n->getSala(s)->setEstado2(0);
				}
				else
				{
					// Efectuar o dano do fogo
					// Percorrer Unidades para dar dano do fogo
					vu = n->getSala(s)->getVU();
					if (vu.size() != 0){
						for (itu = vu.begin(); itu != vu.end(); ++itu)
						{
							(*itu)->setSaude((*itu)->getSaude() - 2);
							cout << (*itu)->getNomeUnidade() +" levou 2 dano devido ao fogo na sala" << endl;
						}
					}
					// Percorrer Inimigos para dar dano do fogo
					vu = n->getSala(s)->getVI();
					if (vu.size() != 0){
						for (itu = vu.begin(); itu != vu.end(); ++itu)
						{
							(*itu)->setSaude((*itu)->getSaude() - 2);
							cout << (*itu)->getNomeUnidade() +" levou 2 dano devido ao fogo na sala" << endl;
						}
					}
					// Percorrer Xenomorfos para dar dano do fogo
					vu = n->getSala(s)->getVU();
					if (vu.size() != 0){
						for (itu = vu.begin(); itu != vu.end(); ++itu)
						{
							(*itu)->setSaude((*itu)->getSaude() - 2);
							cout << (*itu)->getNomeUnidade() +" levou 2 dano devido ao fogo na sala" << endl;
						}
					}
					// Probabilidade de 50% de dar 10 dano a sala devido ao fogo
					int probabilidade = numeroAleatorio1(0, 100);
					if (probabilidade < 50)
					{
						n->getSala(s)->setSaude(n->getSala(s)->getSaude() - 10);
						cout << "Fogo deu 10 de dano a sala " + to_string(s) << endl;
					}

					// Probabilidade de saltar para outra sala
					vector<int> salas = n->getSala(s)->getAdjacente();
					for (size_t i = 0; i < salas.size(); i++)
					{
						int probabilidade = numeroAleatorio1(0, 100);
						if (probabilidade < 5)
						{
							if (estado == 0 && estado != FOGO && estado != BRECHA)
							{
								n->getSala(salas.at(i))->setEstado(FOGO);
								cout << "Fogo saltou para a sala " + to_string(i) << endl;
							}
							else
								if (estado2 == 0 && estado != FOGO && estado != BRECHA)
								{
									n->getSala(salas.at(i))->setEstado2(FOGO);
									cout << "Fogo saltou para a sala " + to_string(i) << endl;
								}
						}
					}
				}
			}
		}

		// CASO HAJA CURTO CIRCUITO
		vector<unidade*>::const_iterator iti;
		vector<unidade*>::const_iterator itx;
		if (estado == CURTOCIRCUITO || estado2 == CURTOCIRCUITO)
		{
			if (n->getSala(s)->getSaude() == 100)
			{
				if (estado == CURTOCIRCUITO)
					n->getSala(s)->setEstado(0);
				else
					n->getSala(s)->setEstado2(0);
			}
			else{
				int probabilidade = numeroAleatorio1(0, 100);
				if (probabilidade < 25)
				{
					int totalUnidades = n->getSala(s)->getVI().size() + n->getSala(s)->getVX().size() + n->getSala(s)->getVU().size();

					if (n->getSala(s)->getVU().size() != 0)
						for (size_t i = 0; i < n->getSala(s)->getVU().size(); i++)
						{
							n->getSala(s)->getVU().at(i)->setSaude(n->getSala(s)->getVU().at(i)->getSaude() - totalUnidades);
							cout << n->getSala(s)->getVU().at(i)->getNomeUnidade() + " levou " + to_string(totalUnidades) + " de dano devido ao CC" << endl;
						}
					if (n->getSala(s)->getVI().size() != 0)
						for (size_t i = 0; i < n->getSala(s)->getVI().size(); i++)
						{
							n->getSala(s)->getVI().at(i)->setSaude(n->getSala(s)->getVI().at(i)->getSaude() - totalUnidades);
							cout << n->getSala(s)->getVI().at(i)->getNomeUnidade() + " levou " + to_string(totalUnidades) + " de dano devido ao CC" << endl;
						}
					if (n->getSala(s)->getVX().size() != 0)
						for (size_t i = 0; i < n->getSala(s)->getVU().size(); i++)
						{
							n->getSala(s)->getVX().at(i)->setSaude(n->getSala(s)->getVX().at(i)->getSaude() - totalUnidades);
							cout << n->getSala(s)->getVX().at(i)->getNomeUnidade() + " levou " + to_string(totalUnidades) + " de dano devido ao CC" << endl;
						}
				}
			}
		}
	}

	// Verifica condições de final de jogo
	if (verificaFinal(n) == 1)
		return 2;

	// 2 EFEITO SALAS
	for (int s = 0; s < 12; s++)
	{
		n->getSala(s)->fazEfeito(n, n->getSala(s));
	}

	// Verifica condições de final de jogo
	if (verificaFinal(n) == 1)
		return 2;

	// 3 Accoes de Unidades
	// Efectua as funções de fim de turno
	for (int i = 0; i < 12; i++)
	{
		// Percorre Xenomorfos e as suas caracteristicas
		vector<unidade*> vx = n->getSala(i)->getVX();
		for (itu = vx.begin(); itu != vx.end(); ++itu)
		{
			if ((*itu)->getFinish() == 0)
			{
				(*itu)->setFinish(1);
				vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
				for (itc = vc.begin(); itc != vc.end(); ++itc)
				{
					(*itc)->fimTurno((*itu), n);
				}
			}
		}
		// Percorre Inimigos e as suas caracteristicas
		vector<unidade*> vi = n->getSala(i)->getVI();
		for (itu = vi.begin(); itu != vi.end(); ++itu)
		{
			if ((*itu)->getFinish() == 0)
			{
				(*itu)->setFinish(1);
				vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
				for (itc = vc.begin(); itc != vc.end(); ++itc)
				{
					(*itc)->fimTurno((*itu), n);
				}
			}
		}
		// Percorre Unidades e as suas caracteristicas
		vector<unidade*> vu = n->getSala(i)->getVU();
		for (itu = vu.begin(); itu != vu.end(); ++itu)
		{
			if ((*itu)->getFinish() == 0)
			{
				(*itu)->setFinish(1);
				vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
				for (itc = vc.begin(); itc != vc.end(); ++itc)
				{
					(*itc)->fimTurno((*itu), n);
				}
			}
		}
	}

	// Remove unidades, caso estas estejam sem vida
	for (int i = 0; i < 12; i++)
	{
		vector<unidade*> vu = n->getSala(i)->getVU();
		for (itu = vu.begin(); itu != vu.end(); ++itu)
		{
			if ((*itu)->getSaude() <= 0)
				n->getSala(i)->removeUnidade((*itu), (*itu)->getNumero());
		}
		vector<unidade*> vi = n->getSala(i)->getVI();
		for (itu = vi.begin(); itu != vi.end(); ++itu)
		{
			if ((*itu)->getSaude() <= 0)
				n->getSala(i)->removeInimigo((*itu), (*itu)->getNumero());
		}
		vector<unidade*> vx = n->getSala(i)->getVX();
		for (itu = vx.begin(); itu != vx.end(); ++itu)
		{
			if ((*itu)->getSaude() <= 0)
			{
				// Se for casulo voltar a criar unidade
				if ((*itu)->getTipo() == CASULO)
				{
					// Verifica se a unidade dentro do casulo e pirata ou unidade
					// e volta a adiciona la a sala
					if ((*itu)->getUniAux()->getTipo() == PIRATA)
						n->getSala((*itu)->getSala())->addInimigo((*itu)->getUniAux());
					else
						n->getSala((*itu)->getSala())->addUnidade((*itu)->getUniAux());

					// Remover casulo
					n->getSala(i)->removeXenomorfo((*itu), (*itu)->getNumero());
				}
				else{
					n->getSala(i)->removeXenomorfo((*itu), (*itu)->getNumero());
				}
			}
		}
	}

	// Verifica condições de final de jogo
	if (verificaFinal(n) == 1)
		return 2;

	// Efectua calculos dos propulsores
	int operar = 0;
	propulsaoTotal = verficaPropulsao(n);

	// Verifica que há um operador na Ponte
	vu = n->getSala(7)->getVU();
	for (itu = vu.begin(); itu != vu.end(); ++itu)
	{
		// Verificar se está em combate ou não
		if (!(*itu)->getCombater())
		{
			vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
			// Verificar se tem a caracteristica de operador
			for (itc = vc.begin(); itc != vc.end(); ++itc)
			{
				if ((*itc)->getTipo() == OPERADOR)
					operar = 1;
			}
		}
	}
	// Verifica se não há uma Blob na Ponte
	vector<unidade*> vx = n->getSala(7)->getVX();
	for (itu = vx.begin(); itu != vx.end(); ++itu)
	{
		// Verificar se está em combate ou não
		if (!(*itu)->getCombater())
		{
			vector<caracteristicas*> vc = (*itu)->getCaracteristicas();
			// Verificar se tem a caracteristica de operador
			for (itc = vc.begin(); itc != vc.end(); ++itc)
			{
				if ((*itc)->getTipo() == OPERADOR)
					operar = 1;
			}
		}
	}

	// Se houver operador verificar se sala de maquinas esta reparada
	if (operar == 1){
		maquinas* salaMaquinas = (maquinas*)n->getSala(4);
		salaMaquinas->fazEfeito(n, n->getSala(4), g, propulsaoTotal);
	}

	if (g->getObjectivo() <= 0)
		return 1;
	return 0;
}

int verificaFinal(nave* n){
	size_t total = 0;
	int flagSalas = 0;

	// Verificacao de numero de tripulantes
	for (int i = 0; i < 12; i++){
		total += n->getSala(i)->getVU().size();
		// Verificacao das salas
		if (n->getSala(i)->getSaude() <= 0)
			return 1;
	}

	if (total == 0)
		return 1;
	return 0;
}