#pragma once
#include "main.h"




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
	int opcao, flag = 0;


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
			cin >> opcao;
		} while (opcao < 1 && opcao > 9);
		vectopcao.push_back(opcao);
		addSalaTipo(n, opcao);
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
			cin >> opcao;
		} while (opcao < 1 && opcao > 9);
		vectopcao.push_back(opcao);
		addSalaTipo(n, opcao);
		flag = 1;
	}
	n->atribuiNumero();
}

void inicializarTripulacao(nave* n, Consola c){
	int nSala;
	Interface in;

	for (int i = 0; i < 3; i++){
		c.gotoxy(15, 30);
		c.setBackgroundColor(c.BRANCO);
		c.setTextColor(c.PRETO);
		cout << "Em que sala pretende inserir o Membro?";
		colocaOrdem();
		do{
			cin >> nSala;
		} while (nSala > 11 && nSala < 0);

		n->addUnidade(MEMBRO, nSala);
		n->addNTripulantes(n->getNumeroTripulantes()+1);
		
		in.desenhaNave();
		c.setBackgroundColor(c.CINZENTO);
		c.setTextColor(c.PRETO);
		in.desenhaSala(n);
		in.desenhaTripulacao(n);
	}
}

nave* inicioJogo(){
	Interface in;
	Consola c;
	nave* n = new nave();

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

void ordens(nave* n){
	string ordem;
	int nSala;
	vector<string> p;
	vector<unidade*> vu;

	cin.clear();
	fflush(stdin);
	getline(cin, ordem);

	cout << ordem;
	p = separaPalavras(ordem);

	/*char *a = new char[ordem.size() + 1];
	a[ordem.size()] = 0;
	memcpy(a, ordem.c_str(), ordem.size());*/

	/*nSala = (int)a[1];*/

	vu = n->getVU();

	for (int i = 0; i < vu.size(); i++)
		if (p[0].compare(vu[i]->getNomeUnidade()) == 0)
		{
			vu[i]->setSala(atoi(p[1].c_str()));
			return;
		}
		else
		{
			cout << "Ordem Incorreta";
		}
}

void jogo(){
	Interface in;
	string ordem;
	game* g = new game();
	Consola c;
	nave* n;

	// Inicializa os Ticks a 0
	g->setTick(0);

	// Limpa e começa o jogo
	in.limpaEcra();
	n = inicioJogo();

	while (1){
		// Mostrar Tick atual
		c.gotoxy(105, 8);
		c.setBackgroundColor(c.BRANCO);
		c.setTextColor(c.PRETO);
		cout << "Tick: " << g->getTick();

		// Coloca o texto ao natural
		c.setBackgroundColor(c.CINZENTO);
		c.setTextColor(c.PRETO);
		colocaOrdem();
		ordens(n);
		g->setTick(g->getTick() + 1);

		if ((g->getTick()) == 2)
		{
			PoCosmico(n, c);
			c.setBackgroundColor(c.BRANCO);
			c.clrscr();
		}

		c.setTextSize(13, 13);
		// Começa os desenhos de interface
		in.desenhaNave();
		// Confere ao texto as caracteristicas para assimilar ao fundo
		c.setBackgroundColor(c.CINZENTO);
		c.setTextColor(c.PRETO);
		// Passa ao desenho da sala
		in.desenhaSala(n);
		c.setBackgroundColor(c.CINZENTO);
		in.desenhaTripulacao(n);


	}

}