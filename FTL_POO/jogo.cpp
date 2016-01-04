#pragma once
#include "main.h"
#include <algorithm>

extern int dificuldade;


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

void inicializarNave(nave* n, Consola c){
	//Consola c;
	Interface in;
	vector<int>vectopcao;
	string opcao;
	int flag = 0;


	n->setEscudo(100);
	n->addSala(PROPULSOR);
	
	c.setBackgroundColor(c.BRANCO);
	c.setTextColor(c.PRETO);
	in.displaysalas();

	for (int i = 1; i < 4; i++)
	{
		in.limpaEcra();
		in.displaysalas();
		in.desenhaMenuOpcao(i+1);
		if (flag == 1)
			in.desenhaSalaNumero(vectopcao);
		do{
			c.gotoxy(15, 30);
			c.setBackgroundColor(c.BRANCO);
			cout << "Indique Sala " << ":";
			colocaOrdem();
			cout << "                                       ";
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
			cout << "                                       ";
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
}

void inicializarTripulacao(nave* n, Consola c){
	int nSala;
	int totalTripulantes=3;
	int i=0;
	int unique=0;

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
				cin >> nSala;
			} while (nSala > 11 && nSala < 0);
			
			n->addUnidade(CAPITAO, nSala);
			vs[nSala]->setnTripulantes(vs[nSala]->getnTripulantes() + 1);
			unique = 1;
			i++;

			in.desenhaNave();
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
				cin >> nSala;
			} while (nSala > 11 && nSala < 0);
			
			n->addUnidade(ROBOT, nSala);
			vs[nSala]->setnTripulantes(vs[nSala]->getnTripulantes() + 1);
			i++;

			in.desenhaNave();
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
		do{
			cin >> nSala;
		} while (nSala > 11 && nSala < 0);

		n->addUnidade(MEMBRO, nSala);
		vs[nSala]->setnTripulantes(vs[nSala]->getnTripulantes() + 1);

		in.desenhaNave();
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
	cout << "4) Nunca ninguem passou este modo";
	
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

	inicializarNave(n,c);
	// Diminui de volta o textsize para o normal
	c.setTextSize(13, 13);
	// Começa os desenhos de interface
	in.desenhaNave();
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

int ordens(nave* n){
	string ordem;
	int nSala;
	vector<string> p;
	vector<unidade*> vu;
	vector<sala*> vs;

	cin.clear();
	fflush(stdin);
	getline(cin, ordem);

	//cout << ordem;
	p = separaPalavras(ordem);

	/*char *a = new char[ordem.size() + 1];
	a[ordem.size()] = 0;
	memcpy(a, ordem.c_str(), ordem.size());*/

	/*nSala = (int)a[1];*/

	vu = n->getVU();
	vs = n->getVS();

	string s = p[0];
	transform(s.begin(), s.end(), s.begin(), toupper);

	if (s.compare("MOVER") == 0){
		for (int i = 0; i < vu.size(); i++)
			if (p[1].compare(vu[i]->getNomeUnidade()) == 0)
			{
				vu[i]->setSala(atoi(p[2].c_str()));
				vs[i]->setnTripulantes(vs[i]->getnTripulantes() + 1);
				return 0;
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

void jogo(){
	Interface in;
	string ordem;
	game* g = new game();
	Consola c;
	nave* n;

	int avancar = 0;

	// Inicializa os Ticks a 0
	g->setTick(0);
	
	// Limpa e começa o jogo
	in.limpaEcra();
	n = inicioJogo();
	// Inicializa o "Objectivo"
	g->setObjectivo(4000 + 1000 * (n->getDificuldade()));

	while (!fimTurno(g, n)){
		while (avancar == 0){

			// Mostrar menu lateral
			in.desenhaInformacao(n, g);
			// Mostrar Tick atual
			c.gotoxy(140, 7);
			c.setBackgroundColor(c.PRETO);
			c.setTextColor(c.VERMELHO_CLARO);
			cout << "Turno: " << g->getTick();


			// Coloca o texto ao natural
			c.setBackgroundColor(c.PRETO);
			c.setTextColor(c.BRANCO);

			c.gotoxy(15, 30);
			cout << "Digite o seu comando:";
			// Inserir Ordens
			colocaOrdem();
			avancar = ordens(n);
			if (avancar == 1){
				g->setTick(g->getTick() + 1);
			}

			c.setTextSize(13, 13);
			// Começa os desenhos de interface
			in.desenhaNave();
			// Confere ao texto as caracteristicas para igualar ao fundo
			c.setBackgroundColor(c.CINZENTO);
			c.setTextColor(c.PRETO);
			// Passa ao desenho da sala
			in.desenhaSala(n);
			c.setBackgroundColor(c.CINZENTO);
			in.desenhaTripulacao(n);
		}
		avancar = 0;
		randomEvents(g, n , in, c);
	}

	c.gotoxy(80, 50);
	cout << "VOCE CHEGOU AO DESTINO!!!!!!!!";

}

int verficaPropulsao(nave* n){
	vector<sala*> vs;
	std::vector<sala*>::const_iterator it;

	int total = 0;

	vs = n->getVS();
	for (it = vs.begin(); it != vs.end(); ++it){
		if ((*it)->getId() == PROPULSOR)
			total += (*it)->getPropulsao();
	}
	return total;
}

void randomEvents(game* g, nave* n, Interface in, Consola c){

	if (numeroAleatorio1(0, 100) > 90){
		PoCosmico(n, c);
		c.setBackgroundColor(c.PRETO);
		c.clrscr();

		c.setTextSize(13, 13);
		// Começa os desenhos de interface
		in.desenhaNave();
		// Confere ao texto as caracteristicas para igualar ao fundo
		c.setBackgroundColor(c.CINZENTO);
		c.setTextColor(c.PRETO);
		// Passa ao desenho da sala
		in.desenhaSala(n);
		c.setBackgroundColor(c.CINZENTO);
		in.desenhaTripulacao(n);
	}
}

int numeroAleatorio1(int min, int max)
{
	return min + rand() % (max - min + 1);
};

boolean fimTurno(game* g, nave* n){
	vector<unidade*> vu;
	vector<unidade*>::const_iterator itu;

	vector<sala*> vs;
	vector<unidade*>::const_iterator it;

	vs = n->getVS();
	vu = n->getVU();

	int propulsaoTotal = 0, flag = 0;

	for (itu = vu.begin(); itu != vu.end(); ++itu){
		if ((*itu)->getSala() == 7)
			if ((*itu)->getOperador() == 1)
				flag = 1;
		if (vs.at((*itu)->getSala())->getSaude() < 100)
			if ((*itu)->getReparador() > 0)
				vs.at((*itu)->getSala())->setSaude(vs.at((*itu)->getSala())->getSaude() + (*itu)->getReparador());
	}

	if (flag == 1)
	{
		propulsaoTotal = verficaPropulsao(n);
		g->setObjectivo(g->getObjectivo() - propulsaoTotal);
	}

	if (g->getObjectivo() <= 0)
		return true;
	return false;
}