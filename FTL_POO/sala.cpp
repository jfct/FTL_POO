#pragma once
#include "main.h"


sala::sala(){}
sala::~sala(){}
void sala::fazEfeito(nave* n, sala* s){}
// Função para verificar dano da sala, retorna false se não 
// puder funcionar
bool sala::verificaDano(){
	if (getSaude() < 100)
		return false;
	else
		return true;
}

//------------------------Ponte------------------------
ponte::ponte(){
	setId(PONTE);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
ponte::~ponte(){}
void ponte::fazEfeito(){}

//------------------------Suporte de Vida------------------------
supVida::supVida(){
	setId(SUPORTEDEVIDA);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
supVida::~supVida(){}
void supVida::fazEfeito(nave* n, sala* s){
	if (s->getSaude() == 100)
	{
		// Na propria Sala
		if (s->getOxigenio() <= 95 && s->getEstado() != BRECHA && s->getEstado2() != BRECHA)
			s->setOxigenio(s->getOxigenio() + 5);
		else
			s->setOxigenio(100);

		for (int i = 0; i < 12; i++)
		{
			// Buscar sala 
			if (n->getSala(i)->getOxigenio() <= 98 && n->getSala(i)->getEstado() != BRECHA && n->getSala(i)->getEstado2() != BRECHA)
				n->getSala(i)->setOxigenio(n->getSala(i)->getOxigenio() + 2);
			else
			{
				n->getSala(i)->setOxigenio(100);
			}
		}
	}
}

//------------------------Propulsor------------------------
propulsor::propulsor(){
	setId(PROPULSOR);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
	setPropulsao(100);
}
propulsor::~propulsor(){}
void propulsor::fazEfeito(){}

//------------------------Controlo de Escudos------------------------
ctrlDeEscudo::ctrlDeEscudo(){
	setId(CONSTROLODEESCUDO);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
ctrlDeEscudo::~ctrlDeEscudo(){}
int ctrlDeEscudo::getEscudo(nave n){
	if (n.getSala(6)->getSaude() == 100)
		return n.getEscudo();
	else
		return 0;
}
//Função para atribuir o escudo a nava N
void ctrlDeEscudo::setEscudo(nave n, int esc){
	n.setEscudo(esc);
}
void ctrlDeEscudo::fazEfeito(nave* n, sala* s){
	if (s->getSaude() == 100 || n->getEscudo() == 100)
	{
		// Flag a verificar se há alguem a operar ou não
		int operar = 0;

		vector<unidade*> vu = s->getVU();
		vector<unidade*>::const_iterator it;
		vector<caracteristicas*>::const_iterator itc;
		vector<caracteristicas*> vc;

		// Percorre unidades e verifica se há um operador
		for (it = vu.begin(); it != vu.end(); ++it)
		{
			if (!(*it)->getCombater())
			{
				vc = (*it)->getCaracteristicas();
				for (itc = vc.begin(); itc != vc.end(); ++itc)
				{
					if ((*itc)->getTipo() == OPERADOR)
						operar = 1;
				}
			}
		}

		if (operar == 1)
		{
			n->setEscudo(n->getEscudo() + 5);
			if (n->getEscudo() > 100)
				n->getEscudo() == 100;
		}
	}
}

//------------------------Sala Maquinas------------------------
maquinas::maquinas(){
	setId(SALADASMAQUINAS);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
maquinas::~maquinas(){}
void maquinas::fazEfeito(nave* n, sala* s, game* g, int propulsaoTotal){
	if (s->getSaude() == 100)
	{
		g->setObjectivo(g->getObjectivo() - propulsaoTotal);
	}
}

//------------------------Beliches------------------------
beliche::beliche(){
	setId(BELICHE);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
beliche::~beliche(){}
void beliche::fazEfeito(){
	// TO-DO
}

//------------------------Raio Laser------------------------
raioLaser::raioLaser(){
	setId(RAIOLASER);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
raioLaser::~raioLaser(){}
void raioLaser::fazEfeito(){}

//------------------------Sala Auto Reparadora------------------------
autoReparador::autoReparador(){
	setId(AUTOREPARADOR);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
autoReparador::~autoReparador(){}
void autoReparador::fazEfeito(nave* n, sala* s){
	int tam = s->getAdjacente().size();
	vector<int> salas = s->getAdjacente();

	if (s->getSaude() == 100){
		for (int i = 0; i < tam; i++)
		{
			// Buscar sala adjacente
			sala* salaAdjacente = n->getSala(salas[i]);

			// Se a sala for diferente de um propulsor
			if (salaAdjacente->getId() != PROPULSOR)
			{
				// Se tiver menos ou igual 95 devolve 5, senao mete de volta a 100
				if (salaAdjacente->getSaude() <= 95)
				{
					salaAdjacente->setSaude(n->getSala(i)->getSaude() + 5);
					cout << "A sala " + to_string(s->getNumero()) + " reparou a sala " + to_string(i) << endl;
				}
				else
				{
					salaAdjacente->setSaude(100);
				}
			}
		}
	}
}

//------------------------Sala Segurança Interna------------------------
segInterna::segInterna(){
	setId(SEGURANCAINTERNA);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
segInterna::~segInterna(){}
void segInterna::fazEfeito(nave* n, sala* s){

	int tam = s->getAdjacente().size();
	vector<int> adjacente = s->getAdjacente();

	if (s->getSaude() == 100)
	{
		// Verificacao na sala actual
		if (getVI().size() > 0)
		{
			for (size_t i = 0; i < getVI().size(); i++)
			{
				if (getVI().at(i)->getCombater())
				{
					// Diminuir vida considerando o Exoesqueleto
					getVI().at(i)->setSaude((getVI().at(i)->getSaude() + getVI().at(i)->getExoesqueleto()) - 1);
					getVI().at(i)->setExoesqueleto(getVI().at(i)->getExoesqueleto() - 1);
					cout << "Sala de seguranca interna atacou " + getVI().at(i)->getNomeUnidade() << endl;

					// Diminuir o exoesqueleto este turno da unidade
					if (getVI().at(i)->getExoesqueleto() < 0)
						getVI().at(i)->setExoesqueleto(0);

					if (getVI().at(i)->getSaude() > getVI().at(i)->getSaudeMax())
						getVI().at(i)->setSaude(getVI().at(i)->getSaudeMax());

					getVI().at(i)->setSaude(getVI().at(i)->getSaude() - 1);
				}
			}
		}
		if (getVX().size() > 0)
		{
			for (size_t i = 0; i < getVX().size(); i++)
			{
				if (getVX().at(i)->getCombater())
				{
					// Diminuir vida considerando o Exoesqueleto
					getVX().at(i)->setSaude((getVX().at(i)->getSaude() + getVX().at(i)->getExoesqueleto()) - 1);
					getVX().at(i)->setExoesqueleto(getVX().at(i)->getExoesqueleto() - 1);
					cout << "Sala de seguranca interna atacou " + getVX().at(i)->getNomeUnidade() << endl;

					// Diminuir o exoesqueleto este turno da unidade
					if (getVX().at(i)->getExoesqueleto() < 0)
						getVX().at(i)->setExoesqueleto(0);

					if (getVX().at(i)->getSaude() > getVX().at(i)->getSaudeMax())
						getVX().at(i)->setSaude(getVX().at(i)->getSaudeMax());

					getVX().at(i)->setSaude(getVX().at(i)->getSaude() - 1);
				}
			}
		}

		// Verificacao no resto das salas
		for (int i = 0; i < tam; i++)
		{
			sala* salaActual = n->getSala(adjacente.at(i));

			if (salaActual->getVI().size() > 0)
			{
				for (size_t i = 0; i < salaActual->getVI().size(); i++)
				{
					if (salaActual->getVI().at(i)->getCombater())
					{
						// Diminuir vida considerando o Exoesqueleto
						salaActual->getVI().at(i)->setSaude((salaActual->getVI().at(i)->getSaude() + salaActual->getVI().at(i)->getExoesqueleto()) - 1);
						salaActual->getVI().at(i)->setExoesqueleto(salaActual->getVI().at(i)->getExoesqueleto() - 1);
						cout << "Sala de seguranca interna atacou " + salaActual->getVI().at(i)->getNomeUnidade() << endl;

						// Diminuir o exoesqueleto este turno da unidade
						if (salaActual->getVI().at(i)->getExoesqueleto() < 0)
							salaActual->getVI().at(i)->setExoesqueleto(0);

						if (salaActual->getVI().at(i)->getSaude() > salaActual->getVI().at(i)->getSaudeMax())
							salaActual->getVI().at(i)->setSaude(salaActual->getVI().at(i)->getSaudeMax());

						salaActual->getVI().at(i)->setSaude(salaActual->getVI().at(i)->getSaude() - 1);
					}
				}
			}
			if (salaActual->getVX().size() > 0)
			{
				for (size_t i = 0; i <salaActual->getVX().size(); i++)
				{
					if (salaActual->getVX().at(i)->getCombater())
					{
						// Diminuir vida considerando o Exoesqueleto
						salaActual->getVX().at(i)->setSaude((salaActual->getVX().at(i)->getSaude() + salaActual->getVX().at(i)->getExoesqueleto()) - 1);
						salaActual->getVX().at(i)->setExoesqueleto(salaActual->getVX().at(i)->getExoesqueleto() - 1);
						cout << "Sala de seguranca interna atacou " + salaActual->getVX().at(i)->getNomeUnidade() << endl;

						// Diminuir o exoesqueleto este turno da unidade
						if (salaActual->getVX().at(i)->getExoesqueleto() < 0)
							salaActual->getVX().at(i)->setExoesqueleto(0);

						if (salaActual->getVX().at(i)->getSaude() > salaActual->getVX().at(i)->getSaudeMax())
							salaActual->getVX().at(i)->setSaude(salaActual->getVX().at(i)->getSaudeMax());

						salaActual->getVX().at(i)->setSaude(salaActual->getVX().at(i)->getSaude() - 1);
					}
				}
			}
		}
	}
}

//------------------------Enfermaria------------------------
enfermaria::enfermaria(){
	setId(ENFERMARIA);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
enfermaria::~enfermaria(){}
void enfermaria::fazEfeito(nave* n, sala* s){
	// Verificar que existem tripulantes na sala

	if (s->getVU().size() > 0 && s->getSaude()==100)
		for (size_t i = 0; i < s->getVU().size(); i++)
		{
			// Se a saude da unidade estiver abaixo da sua saude maxima
			// Adicionamos mais 1 de vida
			if (s->getVU().at(i)->getSaude() < s->getVU().at(i)->getSaudeMax())
				s->getVU().at(i)->setSaude(s->getVU().at(i)->getSaude() + 1);
			cout << "A enfermaria curou " + s->getVU().at(i)->getNomeUnidade() << endl;
		}
}

//------------------------Sala de Armas------------------------
armas::armas(){
	setId(SALADEARMAS);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
armas::~armas(){}
void armas::fazEfeito(nave* n, sala* s){
	// TO-DO
	if (s->getVU().size() > 0)
	{
		for (size_t i = 0; i < s->getVU().size(); i++)
		{
			int flag = 0;
			vector<caracteristicas*> vc = s->getVU().at(i)->getCaracteristicas();
			
			// Ciclo para confirmar que caracteristica não existe ja
			for (size_t j = 0; j < vc.size(); j++)
				if (vc.at(j)->getTipo() == ARMADO)
				{
					flag = 1;
				}

			if (flag != 1)
			{
				vc.push_back(new armado(1));
				s->getVU().at(i)->setCaracteristicas(vc);
			}
		}
	}
}

//------------------------Alojamento de Capitão------------------------
alojaCapitao::alojaCapitao(){
	setId(ALOJAMENTOCAPITAO);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
alojaCapitao::~alojaCapitao(){}
void alojaCapitao::fazEfeito(){
}

//------------------------Oficina de Robot------------------------
oficina::oficina(){
	setId(OFICINA);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
oficina::~oficina(){}
void oficina::fazEfeito(){
}



