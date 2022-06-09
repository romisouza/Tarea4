#include "../../include/clases/Huesped.h"

Huesped::Huesped(string nom,string mail,string pass, bool finger):Usuario(nom,mail,pass) {
	nombre = nom;
	email = mail;
	password = pass;
	esFinger = finger;
}

Huesped::~Huesped(){
}

bool Huesped::getEsFinger(){
	return esFinger;
}

void Huesped::setEsFinger(bool finger){
	esFinger = finger;
}

void Huesped::BuscarEstadias(string email){
}

DTHuesped Huesped::getDTHuesped(){
}
