#include "sala.h"



sala::sala(){}
sala::~sala(){}
// Função para verificar dano da sala, retorna false se não 
// puder funcionar
bool sala::verificaDano(){
	if (getSaude() < 100)
		return false;
	else
		return true;
}

//			Ponte
ponte::ponte(){
	setId(PONTE);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
ponte::~ponte(){}

//			Suporte de Vida
supVida::supVida(){
	setId(SUPORTEDEVIDA);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
supVida::~supVida(){}
// Função para fornecer oxigénio
void supVida::forneceOxigenio(){
	//TO-DO
}

//			Propulsor
propulsor::propulsor(){
	setId(PROPULSOR);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
propulsor::~propulsor(){}

//			Controlo de Escudos
ctrlDeEscudo::ctrlDeEscudo(){
	setId(CONSTROLODEESCUDO);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
ctrlDeEscudo::~ctrlDeEscudo(){}
//Função para buscar o actual escudo da nave N
int ctrlDeEscudo::getEscudo(nave n){
	return n.getEscudo();
}
//Função para atribuir o escudo a nava N
void ctrlDeEscudo::setEscudo(nave n, int esc){
	n.setEscudo(esc);
}

//			Sala Maquinas
maquinas::maquinas(){
	setId(SALADASMAQUINAS);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
maquinas::~maquinas(){}

//			Beliches
beliche::beliche(){
	setId(BELICHE);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
beliche::~beliche(){}
// Função que adiciona mais um membro possivel
void beliche::fazEfeito(nave n){
	return (n.setTripulantes(n.getTripulantes + 1));
}

//			Raio Laser
raioLaser::raioLaser(){
	setId(RAIOLASER);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
raioLaser::~raioLaser(){}

//			Sala Auto Reparadora
autoReparador::autoReparador(){
	setId(AUTOREPARADOR);
	setSaude(SAUDE);
	setIntegridade(INTEGRIDADE);
	setOxigenio(100);
}
autoReparador::~autoReparador(){}
// Função que repara salas adjacentes em 5 pontos cada
void autoReparador::fazEfeito(nave n){

}

