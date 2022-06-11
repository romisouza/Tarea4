#include "../../include/clases/Huesped.h"

Huesped::Huesped(std::string nom,std::string mail,std::string pass, bool finger):Usuario(nom,mail,pass) {
	nombre = nom;
	email = mail;
	password = pass;
	esFinger = finger;
	map<int,Reserva*> ColReservasHuesp; 
}

Huesped::~Huesped(){
}


map<int,Reserva*> Huesped::getColReservasHuesp(){
	return ColReservasHuesp;
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
