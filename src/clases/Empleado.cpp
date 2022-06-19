#include "../../include/clases/Empleado.h"

Empleado::Empleado(string nom,string mail,string pass):Usuario(nom,mail,pass) {
	nombre = nom;
	email = mail;
	password = pass;
	hostalAsociado = NULL;
	cargo = NULL;
	list<IObserver*> califObs; 
}

Empleado::~Empleado(){
	delete hostalAsociado;
	delete cargo;
	califObs.clear();
}

Hostal* Empleado::getHostalAsociado(){
	return hostalAsociado;
}

CargoEmpleado* Empleado::getCargoEmpleado(){
	return cargo;
}

list<Calificacion*> Empleado::getCalifObs(){
	return califObs;
}

void Empleado::setHostalAsociado(Hostal* host){
	hostalAsociado = host;
}

void Empleado::setCargoEmpleado(CargoEmpleado* car){
	cargo = car;
}

list<DTCal> Empleado::obtenerComentarios(){ //ADE PROBAR Q FUNCIONE BIEN
	Hostal* host = getHostalAsociado();
	list<Calificacion*> calificaciones = host->getColCal();
	list<DTCal> lista;
	for (auto it= calificaciones.begin(); it!=calificaciones.end();++it){
		std::string str = (*it)->getComentarioEmp();
		if (str.empty()){
			std::string com = (*it)->getComentarioHuesp();
			Estadia *est = (*it)->getEstadia();
			Reserva *res = est->getReserva();
			std::string email = est->getHuesp()->getEmail();
			DTCal calif = DTCal(com,email,res->getCodigo());
			lista.push_back(calif);
		}
	}
	return lista;
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
	DTEmpleado emp = DTEmpleado(nombre,email,cargo);
	return emp;
}

void Empleado::notificar(Calificacion* cal){
	califObs.push_back(cal);
}

IObserver* Empleado::getObserver(){
	Empleado* nuevo= new Empleado(getNombre(),getEmail(),getPassword());
	return nuevo;
}


string Empleado::getEmailObs(){
	return getEmail();
}

void Empleado::EliminarCalificaciones(){
	califObs.clear();
}