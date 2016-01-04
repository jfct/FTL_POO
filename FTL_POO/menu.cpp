#include "main.h"

void colocaOrdem(){
	Consola c;

	//c.setBackgroundColor(c.BRANCO);
	//c.setTextColor(c.PRETO);
	//c.gotoxy(15, 30);
	//cout << "Digite ordem";
	c.gotoxy(15, 33);
	cout << ">";
};

void menu(){
	Consola c;
	string opcao;

	do{
		titulo();
		c.gotoxy(55, 30);
		cout << "1) Novo Jogo" << endl;
		c.gotoxy(55, 32);
		cout << "2) Sair" << endl;

		colocaOrdem();
		cin.clear();
		fflush(stdin);
		getline(cin, opcao);

		c.clrscr();
	} while (atoi(opcao.c_str()) != 1 && atoi(opcao.c_str()) != 2);

	switch (atoi(opcao.c_str())){
	case 1:
		jogo();
		break;
	case 2:
		
		break;
	default:
		break;
	}
}