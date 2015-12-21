#include "main.h"

void jogo(){
	Consola c;

	c.clrscr();

	//1 linha
	c.drawSquare(9+8, 12+1, 98, RGB(153, 153, 153), 1);
	c.gotoxy(3, 1);
	c.setBackgroundColor(c.AMARELO);
	cout << "Ctrl de Escudo" << endl;
	c.drawSquare(9 + 8 +102, 12 + 1, 98, RGB(153, 153, 153), 1);
	c.gotoxy(20, 1);
	cout << "123" << endl << endl << endl;
	c.drawSquare(9 + 8 + 102 + 102, 12 + 1, 98, RGB(153, 153, 153), 1);
	c.gotoxy((37 ), 2);
	cout << "123" << endl << endl;
	c.drawSquare(9 + 8 + 102 + 102 +102, 12 + 1, 98, RGB(153, 153, 153), 1);
	
	//2 linha
	c.drawSquare(9 + 8 +102, 12 + 1 + 102 , 98, RGB(153, 153, 153), 1);
	c.drawSquare(9 + 8 + 102 + 102, 12 + 1 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(9 + 8 + 102 + 102 + 102, 12 + 1 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(9 + 8 + 102 + 102 + 102 + 102, 12 + 1 + 102, 98, RGB(153, 153, 153), 1);
	//c.gotoxy(54, 2);
	//cout << "123" << endl << endl;
	
	//3 linha
	c.drawSquare(9 + 8, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);

	c.drawSquare(9 + 8 +102, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(9 + 8 + 102+102, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);
	c.drawSquare(9 + 8 + 102+102+102, 12 + 1 + 102 + 102, 98, RGB(153, 153, 153), 1);

	c.gotoxy(3, 9);
	cout << "123" << endl << endl;

	//c.drawSquare(6, 13, tamanhocelula*10, RGB(153, 153, 153), 1);
	//c.gotoxy(pos.X, pos.Y);
	//c.setBackgroundColor(c.CYAN);
	//cout << " " << endl << endl;
	//c.drawSquare(6*3, 13, tamanhocelula *8, RGB(153, 153, 153), 1);
	//c.gotoxy(pos.X + 14, pos.Y);
	//cout << " " << endl << endl 
	//c.gotoxy(tamanhocelula, tamanhocelula);
	//cout << "Ponte" << endl << endl;


	/*for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			c.drawSquare((tamanhocelula * j * 10) + j , (tamanhocelula * i *10) + i, tamanhocelula * 10, RGB(153, 153, 153), 1);
		}*/
}