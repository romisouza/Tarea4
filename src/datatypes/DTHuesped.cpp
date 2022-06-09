#include "../../include/datatypes/DTHuesped.h"

DTHuesped::DTHuesped(string nom, string mail, bool esfing){
	nombre = nom;
	email = mail;
	esFinger = esfing; 
}

string DTHuesped::getNombre(){
	return nombre;
}

string DTHuesped::getMail(){
	return email;
}

bool DTHuesped::getEsFinger(){
	return esFinger;
}

DTHuesped::~DTHuesped(){}