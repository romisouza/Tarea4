#include "../../include/clases/Hostal.h"

Hostal::Hostal(){}

Hostal::Hostal(std::string nom,std::string direc,int tel,int prom) {
	nombre = nom;
	direccion = direc;
	telefono = tel;
	promedio = prom; 

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

set<Calificacion> Hostal::getColCal(){
	return ColCal;
}

set<DTCal> Hostal::obtenerHostal(){
}

void Hostal::BuscarReservas(){}

void Hostal::EliminarRes(Reserva* res){}

void Hostal::AgregarComentarios(std::string comentario, int puntaje){}

DataHostalComp Hostal::getDTHostal(){
DataHostalComp Hst=DataHostalComp(getNombre(),getDireccion(),getTelefono(),getPromedio());
	map<int,Reserva*> Res=getColReservas();
	for(auto it=Res.begin();it!=Res.end();it++){
		Hst.agregarReserva(it->first,it->second);	
	}
	map<int, Habitacion*> Hab=getColHabitaciones();
	for(auto itH=Hab.begin();itH!=Hab.end();it++){
		Hst.agregarHabitacion(itH->first,itH->second);
	}
	//Falta lo de calificacion
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





