#include "main.h"

void colocaOrdem(){
	Consola c;
	c.gotoxy(20, 33);
	cout << ">";
};

void menu(){
	Consola c;
	int opcao;

	c.gotoxy(55, 30);
	cout << "Novo Jogo" << endl;
	c.gotoxy(55, 31);
	cout << "Opcoes" << endl;
	c.gotoxy(55, 32);
	cout << "Sair" << endl;

	colocaOrdem();
	cin >> opcao;

	switch (opcao){
	case 1:
		jogo();
		break;
	default:
		break;
	}
}