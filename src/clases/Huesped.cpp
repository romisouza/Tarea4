#include "../../include/clases/Huesped.h"

Huesped::Huesped(std::string nom,std::string mail,std::string pass, bool finger):Usuario(nom,mail,pass) {
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

void Huesped::BuscarEstadias(std::string email){
}

DTHuesped Huesped::getDTHuesped(){
}
