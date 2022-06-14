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

list<Estadia*> Huesped::BuscarEstadias(std::string email,  DTFecha hrs){
	map<int,Reserva*> Res=getColReservasHuesp();
	list<Estadia*> ListasFin;
	Estadia* aux= new Estadia();
	for(auto it=Res.begin();it!=Res.end();it++){
		Estadia* est= new Estadia();
		it->second->BuscarEstadia(email,hrs,est);
		if((aux->getReserva()->getCodigo() != est->getReserva()->getCodigo()) && (aux->getHuesp()->getEmail())!=est->getHuesp()->getEmail()) {
			ListasFin.push_back(est);
		}
	}
	return ListasFin;
}

DTHuesped Huesped::getDTHuesped(){



}
