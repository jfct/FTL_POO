#include "main.h"

class nave{

	int escudo;
	int nTripulantes;
	vector<sala *> vectorSala;

public:

	nave();
	~nave();

	sala getSala(int numero);

	int getTripulantes(){ return nTripulantes; };
	int getEscudo(){ return escudo; };
	
	void setTripulantes(int s) { nTripulantes = s; };
	void setEscudo(int s){ escudo = s; };
};