#include "../../include/clases/Hostal.h"

Hostal::Hostal(){}

Hostal::Hostal(std::string nom,std::string direc,int tel,int prom) {
	nombre = nom;
	direccion = direc;
	telefono = tel;
	promedio = prom; 
	map<int,Reserva*> ColReservas;
	map<int, Habitacion*> ColHabitaciones;
	list<Calificacion*> ColCal;
	map<std::string,Empleado*> ColEmpleados;
}

Hostal :: ~Hostal() {}

map<std::string,Empleado*> Hostal::getColEmpleados(){
	return ColEmpleados;
}

std::string Hostal::getNombre(){
	return nombre;
}

std::string Hostal::getDireccion(){
	return direccion;
}

int Hostal::getTelefono(){
	return telefono;
}

int Hostal::getPromedio(){
	return promedio;
}

void Hostal::setNombre(std::string nom){
	nombre = nom;
}

void Hostal::setDireccion(std::string direc){
	direccion = direc;
}

void Hostal::setTelefono(int tel){
	telefono = tel;
}

void Hostal::setPromedio(int prom){
	promedio = prom;
}

map<int,Reserva*> Hostal::getColReservas(){
	return ColReservas;
}

map<int, Habitacion*> Hostal::getColHabitaciones(){
	return ColHabitaciones;
}

list<Calificacion*> Hostal::getColCal(){
	return ColCal;
}

set<DTCal> Hostal::obtenerHostal(){
}

void Hostal::BuscarReservas(){}

void Hostal::EliminarRes(Reserva* res){}

void Hostal::AgregarComentarios(std::string comentario, int puntaje){}

DataHostalComp Hostal::getDTHostal(){
/*DataHostalComp Hst=DataHostalComp(getNombre(),getDireccion(),getTelefono(),getPromedio());
	map<int,Reserva*> ResHst=Hst.getReservas();
	map<int,Reserva*> Res=getColReservas();
	for(auto it=Res.begin();it!=Res.end();it++){
		ResHst.emplace(it->first,it->second);	
	}
	map<int, Habitacion*> HabHst= Hst.getHabitaciones();
	map<int, Habitacion*> Hab=getColHabitaciones();
	for(auto itH=Hab.begin();itH!=Hab.end();itH++){
		HabHst.emplace(itH->first,itH->second);
	}
	ColHabitaciones=Hab;
	list<Calificacion*> Cal=getColCal();
	list<DTCalificacion> Cali=Hst.getComentarios();
	list<Calificacion*>:: iterator it=Cal.begin();
	while(it!=Cal.end()){
		Calificacion* CalAux= *it;
		DTCalificacion aux= DTCalificacion(CalAux->getPuntaje(),CalAux->getComentarioHuesp(),CalAux->getComentarioEmp());
		Cali.push_back(aux);
		it++;
	}
	return Hst;*/
}


DTIdEstadia Hostal::accesoaReservas(){}

DataEstadia Hostal::accederaReservas(DTIdEstadia est){}

void Hostal::hallarReserva(std::string mailHuesp, int codigoRes, std::string respuesta){}

DTHostalProm Hostal::getDTHostalProm(){}

set<int> Hostal::obtenerHabitaciones( DTFecha in, DTFecha out){}

void Hostal::seleccionarHab(int numHab){}

void Hostal::AgregarEmpleadoAHostal() {}

set<DTReserva> Hostal::ObtenerReservas(){}

set<DTCalificacion> Hostal::obtenerCalificaciones(){}

int Hostal::getPromCal(){}

bool Hostal::TrabajaEnHostal(){}

void Hostal::ingresoAlHostal(int codigoRes){}

void Hostal::buscarR(std::string email ){}

set<DTReserva> Hostal::BuscarRes(std::string email){}

void Hostal::agregarHabAlHost(){}

void Hostal::recordarHostal(){}





