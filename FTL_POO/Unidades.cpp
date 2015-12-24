#pragma once

#include "main.h"

int unidade::id = 0;

unidade::unidade(){}
unidade::~unidade(){}

membro::membro(int i){
	string nome;
	std::ostringstream s;

	setSala(i);
	setTipo(MEMBRO);
	setId(id);
	s.clear();
	s << "M" << id;
	nome = (s.str());
	setNomeUnidade(nome);
	id++;
	setSaude(5);
}
membro::~membro(){}

capitao::capitao(int i){
	string nome;
	std::ostringstream s;

	setSala(i);
	setTipo(CAPITAO);
	setId(id);
	s << "C" << id;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	id++;
	setSaude(6);
}
capitao::~capitao(){}

robot::robot(int i){
	string nome;
	std::ostringstream s;

	setSala(i);
	setTipo(ROBOT);
	setId(id);
	s << "R" << id;
	nome = (s.str());
	setNomeUnidade(nome);
	s.clear();
	id++;
	setSaude(8);
}
robot::~robot(){}

geigermorfo::geigermorfo(){}
geigermorfo::~geigermorfo(){}

casulo::casulo(){}
casulo::~casulo(){}

blob::blob(){}
blob::~blob(){}

mxyzypykwi::mxyzypykwi(){}
mxyzypykwi::~mxyzypykwi(){}

