#pragma once

#include "main.h"

int unidade::id = 0;
int unidade::idInimigo = 0;
int unidade::idXenomorfo = 0;

unidade::unidade(){}
unidade::~unidade(){}

membro::membro(int i){
	string nome;
	std::ostringstream s;
	
	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(MEMBRO);
	setNumero(id);
	s.clear();
	s << "M" << id;
	nome = (s.str());
	setNomeUnidade(nome);
	id++;

	//TO-DO - Caracteristicas
	setSaude(5);
	setSaudeMax(5);
	
	vector<caracteristicas*> vc;

	vc.push_back(new respira());
	vc.push_back(new reparador(1));
	vc.push_back(new combatente(1));
	vc.push_back(new operador());
	vc.push_back(new tripulacao());

	setCaracteristicas(vc);
}
membro::~membro(){}

capitao::capitao(int i){
	string nome;
	std::ostringstream s;

	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(CAPITAO);
	setNumero(id);
	setId(id);
	s << "C" << id;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	id++;
	
	//TO-DO - Caracteristicas
	//setExoesqueleto(1);
	setSaude(6);
	setSaudeMax(6);

	vector<caracteristicas*> vc;

	vc.push_back(new respira());
	vc.push_back(new exoesqueleto(1));
	vc.push_back(new reparador(1));
	vc.push_back(new combatente(2));
	vc.push_back(new operador());
	vc.push_back(new tripulacao());

	setCaracteristicas(vc);
}
capitao::~capitao(){}

robot::robot(int i){
	string nome;
	std::ostringstream s;

	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(ROBOT);
	setNumero(id);
	setId(id);
	s << "R" << id;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	id++;

	//TO-DO - Caracteristicas
	//setExoesqueleto(2);
	setSaude(8);
	setSaudeMax(8);

	vector<caracteristicas*> vc;

	vc.push_back(new exoesqueleto(2));
	vc.push_back(new combatente(3));
	vc.push_back(new tripulacao());
	setCaracteristicas(vc);
}
robot::~robot(){}

geigermorfo::geigermorfo(int i){
	string nome;
	std::ostringstream s;

	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(GEIGERMORFO);
	setNumero(idXenomorfo);
	setId(idXenomorfo);
	s << "G" << idXenomorfo;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	idXenomorfo++;

	//TO-DO - Caracteristicas
	//setExoesqueleto(2);
	setSaude(4);
	setSaudeMax(4);

	vector<caracteristicas*> vc;

	vc.push_back(new xenomorfo(3));
	vc.push_back(new misterioso());
	vc.push_back(new move_(50));
	vc.push_back(new casuloCaracteristicas(20));
	vc.push_back(new exoesqueleto(3));

	setCaracteristicas(vc);
}
geigermorfo::~geigermorfo(){}

casulo::casulo(int i, unidade* uni){
	string nome;
	std::ostringstream s;

	setUniAux(uni);
	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(CASULO);
	setNumero(idXenomorfo);
	setId(idXenomorfo);
	s << "CA" << idXenomorfo;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	idXenomorfo++;

	//TO-DO - Caracteristicas
	//setExoesqueleto(2);
	setSaude(6);
	setSaudeMax(6);

	vector<caracteristicas*> vc;

	vc.push_back(new xenomorfo(0));
	vc.push_back(new exoesqueleto(1));
	vc.push_back(new casuloCaracteristicas(0, true));
	setCaracteristicas(vc);
}
casulo::~casulo(){}

blob::blob(int i){
	string nome;
	std::ostringstream s;

	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(BLOBE);
	setNumero(idXenomorfo);
	setId(idXenomorfo);
	s << "B" << idXenomorfo;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	idXenomorfo++;

	//TO-DO - Caracteristicas
	//setExoesqueleto(2);
	setSaude(8);
	setSaudeMax(8);

	vector<caracteristicas*> vc;

	vc.push_back(new xenomorfo(0));
	vc.push_back(new regenerador(2));
	vc.push_back(new flamejante());
	vc.push_back(new toxico(1));
	vc.push_back(new reparador(6));
	vc.push_back(new operador());
	vc.push_back(new move_(15));

	setCaracteristicas(vc);
}
blob::~blob(){}

mxyzypykwi::mxyzypykwi(int i){
	string nome;
	std::ostringstream s;

	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(MXYZYPYKWI);
	setNumero(idXenomorfo);
	setId(idXenomorfo);
	s << "MX" << idXenomorfo;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	idXenomorfo++;

	//TO-DO - Caracteristicas
	//setExoesqueleto(2);
	setSaude(8);
	setSaudeMax(8);

	vector<caracteristicas*> vc;

	vc.push_back(new xenomorfo(0));
	vc.push_back(new hipnotizador(15));
	vc.push_back(new move_(30));
	vc.push_back(new mutatis(90));
	vc.push_back(new respira());

	setCaracteristicas(vc);
}
mxyzypykwi::~mxyzypykwi(){}

pirata::pirata(int i){
	string nome;
	std::ostringstream s;

	setCombater(false);
	setMover(true);
	setSala(i);
	setTipo(PIRATA);
	setNumero(idInimigo);
	setId(idInimigo);
	s << "P" << idInimigo;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	idInimigo++;

	//TO-DO - Caracteristicas
	//setExoesqueleto(2);
	setSaude(4);
	setSaudeMax(4);

	vector<caracteristicas*> vc;

	vc.push_back(new respira());
	vc.push_back(new inimigo(1));
	vc.push_back(new inimigoSala(2));
	vc.push_back(new move_(15));

	setCaracteristicas(vc);
}
pirata::~pirata(){}

