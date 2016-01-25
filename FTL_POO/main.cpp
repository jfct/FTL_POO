#pragma once
#include "main.h"

void main(){
	Consola c;
	srand(time(NULL));
	
	c.setScreenSize(50, 200);

	c.setBackgroundColor(c.PRETO);

	menu();
	//exemplo();
}