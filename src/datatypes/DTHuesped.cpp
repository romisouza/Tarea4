#include "../../include/datatypes/DTHuesped.h"

DTHuesped::DTHuesped(std::string nom, std::string mail, bool esfing){
	nombre = nom;
	email = mail;
	esFinger = esfing; 
}

std::string DTHuesped::getNombre(){
	return nombre;
}

std::string DTHuesped::getMail(){
	return email;
}

bool DTHuesped::getEsFinger(){
	return esFinger;
}

DTHuesped::~DTHuesped(){}