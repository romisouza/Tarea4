#include "../../include/clases/Empleado.h"

Empleado::Empleado(string nom,string mail,string pass, CargoEmpleado* car):Usuario(nom,mail,pass) {
	nombre = nom;
	email = mail;
	password = pass;
	hostalAsociado = NULL;
	cargo = car;
}

Empleado::~Empleado(){
}

Hostal* Empleado::getHostalAsociado(){
	return hostalAsociado;
}

CargoEmpleado* Empleado::getCargoEmpleado(){
	return cargo;
}

void Empleado::setHostalAsociado(Hostal* host){
	hostalAsociado = host;
}

void Empleado::setCargoEmpleado(CargoEmpleado* car){
	cargo = car;
}

set<DTCal> Empleado::obtenerComentarios(){
}

DataEmpleado Empleado::getDataEmpleado(){
}

bool Empleado::TrabajaEnHostal(){//cambio respecto a dcd
	return hostalAsociado==NULL;
}

void Empleado::AsignarEmpleadoAHostal(CargoEmpleado* cargoEmp,Hostal* host){
	setCargoEmpleado(cargoEmp);
	setHostalAsociado(host);
}

DTEmpleado Empleado::getDTEmpleado(){
	return DTEmpleado(nombre,email,cargo);
}

void Empleado::notificar(Calificacion cal){
}
