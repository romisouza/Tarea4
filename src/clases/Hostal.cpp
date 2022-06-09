#include "../../include/clases/Hostal.h"

Hostal::Hostal(){}

Hostal :: Hostal(string nom,string direc,int tel,int prom, !!!!, !!!!) { //faltan las colec de reservas y hab
	nombre = nom;
	direccion = direc;
	telefono = tel;
	promedio = prom; 

}

Hostal :: ~Hostal() {}

string Hostal::getNombre(){
	return nombre;
}

string Hostal::getDireccion(){
	return direccion;
}

int Hostal::getTelefono(){
	return telefono;
}

int Hostal::getPromedio(){
	return promedio;
}

void Hostal::setNombre(string nom){
	nombre = nom;
}

void Hostal::setDireccion(string direc){
	direccion = direc;
}

void Hostal::setTelefono(int tel){
	telefono = tel;
}

void Hostal::setPromedio(int prom){
	promedio = prom;
}

Set(DTCal) Hostal::obtenerHostal(){}

void Hostal::BuscarReservas(){}

void Hostal::EliminarRes(Reserva* res){}

void Hostal::AgregarComentarios(string comentario, int puntaje){}

DataHostalComp Hostal::getDTHostal(){
	DataHostalComp Hst=DataHostalComp(getNombre(),getDireccion(),getTelefono());
	map<int,Reserva*> Res=getColReservas();
	for(auto it=Res.begin();it!=Res.end();it++){

	}
}

DTIdEstadia Hostal::accesoaReservas(){}

DataEstadia Hostal::accederaReservas(DTIdEstadia est){}

void Hostal::hallarReserva(string mailHuesp, int codigoRes, string respuesta){}

DTHostalProm Hostal::getDTHostalProm(){}

Set(int) Hostal::obtenerHabitaciones( DTFecha in, DTFecha out){}

void Hostal::seleccionarHab(int numHab){}

void Hostal::AgregarEmpleadoAHostal() {}

Set(DTReserva) Hostal::ObtenerReservas(){}

Set(DTCalificacion) Hostal::obtenerCalificaciones(){}

int Hostal::getPromCal(){}

bool Hostal::TrabajaEnHostal(){}

void Hostal::ingresoAlHostal(int codigoRes){}

void Hostal::buscarR(string email ){}

Set(DTReserva) Hostal::BuscarRes(email string){}

void Hostal::agregarHabAlHost(){}

void Hostal::recordarHostal(){}





