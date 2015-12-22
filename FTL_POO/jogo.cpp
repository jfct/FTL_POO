#pragma once
#include "main.h"

void inicioJogo(){
	Consola c;
	nave nave;	

	nave.setEscudo(100);
	nave.setTripulantes(3);


}


void jogo(){
	Interface in;
	string ordem;

	in.limpaEcra();
	inicioJogo();
	in.desenhaNave();
	in.desenhaInformacao();
	
	colocaOrdem();

	cin >> ordem;
	
	//inicioJogo();

}