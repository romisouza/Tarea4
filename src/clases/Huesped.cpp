#include "../../include/clases/Huesped.h"

Huesped::Huesped(std::string nom,std::string mail,std::string pass, bool finger):Usuario(nom,mail,pass) {
	nombre = nom;
	email = mail;
	password = pass;
	esFinger = finger;
	map<int,Reserva*> ColReservasHuesp; 
}

Huesped::~Huesped(){
	ColReservasHuesp.clear();
}


map<int,Reserva*> Huesped::getColReservasHuesp(){
	return ColReservasHuesp;
}

void Huesped::setColReservasHuesp(map<int,Reserva*> colRes){
	ColReservasHuesp = colRes;
}

bool Huesped::getEsFinger(){
	return esFinger;
}

void Huesped::setEsFinger(bool finger){
	esFinger = finger;
}

list<DTIdEstadia> Huesped::BuscarEstadias(std::string email,  DTFecha hrs){
	map<int,Reserva*> Res=getColReservasHuesp();
	list<DTIdEstadia> ListasFin;
	DTIdEstadia aux= DTIdEstadia();
	for(auto it=Res.begin();it!=Res.end();it++){
		it->second->BuscarEstadia(email,hrs,ListasFin);
	}
	return ListasFin;
}

Estadia* Huesped::BuscarEstadias2(DTIdEstadia est){
	Reserva* res= ColReservasHuesp.find(est.getCodigo())->second;
	list<Estadia*> aux= res->getEstadia();
	list<Estadia*>::iterator it=aux.begin();
	while(est.getEmail()!=(*it)->getHuesp()->getEmail()){
		it++;
	}
	if ((*it)->getCal()!=NULL){
		throw std::invalid_argument("La estadia seleccionada ya fue calificada.");
	}
	return (*it);
}

void Huesped::EliminarResHsp(int codRes){
	if(!ColReservasHuesp.empty()){
		
	/*	auto it=ColReservasHuesp.begin();
		while (it!=ColReservasHuesp.end() && it->second->getCodigo()!=codRes){
			++it;
		}*/
		Reserva *res = ColReservasHuesp.find(codRes)->second;
		ColReservasHuesp.erase(codRes);
		res->~Reserva();

	}	
}
