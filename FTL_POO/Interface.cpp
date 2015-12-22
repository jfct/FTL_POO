#include "main.h"

Interface::Interface(){};


void Interface::limpaEcra(){
	c.clrscr();
};

void Interface::desenhaNave(){
	//1 linha
	c.drawSquare(98, 98, 98, RGB(153, 153, 153), 1);
	c.gotoxy(3, 1);
	c.setBackgroundColor(c.AMARELO);
	cout << "Ctrl de Escudo" << endl;
	c.drawSquare(102, 12 + 1, 98, RGB(153, 153, 153), 1);
	c.gotoxy(20, 1);
	cout << "123" << endl << endl << endl;
	c.drawSquare(102 + 102, 12 + 1, 98, RGB(153, 153, 153), 1);
	c.gotoxy((37), 2);
	cout << "123" << endl << endl;
	c.drawSquare(102 + 102 + 102, 12 + 1, 98, RGB(153, 153, 153), 1);

	//2 linha
	c.drawSquare(102, 12 + 1 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(102 + 102, 12 + 1 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(102 + 102 + 102, 12 + 1 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(102 + 102 + 102 + 102, 12 + 1 + 102, 98, RGB(153, 153, 153), 1);
	//c.gotoxy(54, 2);
	//cout << "123" << endl << endl;

	//3 linha
	c.drawSquare(0, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);

	c.drawSquare(102, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(102 + 102, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(102 + 102 + 102, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);

	/*for (int i = 1; i <= 3; i++)
	for (int j = 1; j <= 3; j++)
	{
	c.drawSquare((tamanhocelula * j * 10) + j , (tamanhocelula * i *10) + i, tamanhocelula * 10, RGB(153, 153, 153), 1);
	}*/
};

void Interface::desenhaInformacao(){

};