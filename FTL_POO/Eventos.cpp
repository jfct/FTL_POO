#pragma once
#include "Eventos.h"
#include <random>

int numeroAleatorio(int min, int max)
{
	return min + rand() % (max - min + 1);
};

void PoCosmico(nave* n, Consola c){

	int nSalas = numeroAleatorio(3, 5);
	sala* s;

	c.setTextSize(20, 20);
	c.setBackgroundColor(c.VERMELHO);
	c.clrscr();
	c.setTextColor(c.PRETO);

	c.gotoxy(25, 4);
	cout << "PERIGO!!";
	c.gotoxy(12, 7);
	cout << "PERIGO!!";

	c.gotoxy(60, 10);
	cout << "PERIGO!!";
	c.gotoxy(75, 13);
	cout << "PERIGO!!";

	c.setTextColor(c.BRANCO);
	c.gotoxy(30, 9);
	cout << "PO COSMICO!!";
	c.gotoxy(15, 10);
	cout << "A sua nave vai levar dano";

	for (int i = 0; i < nSalas; i++)
	{
		int sala = numeroAleatorio(0, 11);
		s = n->getSala(sala);
		s->setSaude(s->getSaude() - DANOPOCOSMICO);
	}
	c.gotoxy(10, 30);
	system("PAUSE");
	c.setTextSize(13, 13);
}