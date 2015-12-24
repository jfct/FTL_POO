#pragma once
#include "main.h"


int numeroAleatorio(int min, int max)
{
	return min + rand() % (max - min + 1);
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
	n->setTripulantes(3);
	n->addSala(PROPULSOR);
	
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

	for (int i = 0; i < 3; i++){
		c.gotoxy(15, 30);
		cout << "Em que sala pretende inserir o Membro?";
		colocaOrdem();
		do{
			cin >> nSala;
		} while (nSala > 11 && nSala < 0);

		n->addUnidade(MEMBRO, nSala);
		n->addNTripulantes(n->getNumeroTripulantes()+1);
	}
}

void inicioJogo(){
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
}

void ordens(){
	string ordem;
	vector<string> p;

	cin.ignore();
	getline(cin, ordem);

	cout << ordem;
	p = separaPalavras(ordem);
	system("PAUSE");
}

void jogo(){
	Interface in;
	string ordem;
	game* g = new game();
	Consola c;
	
	// Inicializa os Ticks a 0
	g->setTick(0);

	// Limpa e começa o jogo
	in.limpaEcra();
	inicioJogo();

	// Coloca o texto ao natural
	c.setBackgroundColor(c.CINZENTO);
	c.setTextColor(c.PRETO);
	colocaOrdem();
	ordens();
}