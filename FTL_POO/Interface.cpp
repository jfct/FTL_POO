#include "main.h"

Interface::Interface(){};


void Interface::limpaEcra(){
	c.clrscr();
};

void Interface::desenhaNave(){
	int tamanho = tamanhocelula + 4;

	c.setBackgroundColor(c.BRANCO);
	limpaEcra();

	//1 linha
	c.drawSquare(tamanho, 13, tamanhocelula, RGB(0, 128, 0), 1);

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
	/*for (int i = 1; i <= 3; i++)
	for (int j = 1; j <= 3; j++)
	{
	c.drawSquare((tamanhocelula * j * 10) + j , (tamanhocelula * i *10) + i, tamanhocelula * 10, RGB(153, 153, 153), 1);
	}*/
};

void Interface::desenhaInformacao(){

	c.setBackgroundColor(c.VERDE);
	c.setTextColor(c.BRANCO);
	// 1 linha
	c.gotoxy(18, 1);
	cout << "Ctrl de Escudo" << endl;
	c.gotoxy(18, 3);
	c.setBackgroundColor(c.CINZENTO);
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