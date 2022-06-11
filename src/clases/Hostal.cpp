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
	DataHostalComp Hst=DataHostalComp(getNombre(),getDireccion(),getTelefono(),getPromedio());
	cout<< Hst.getNombre()<< "," << Hst.getDireccion() <<","<< Hst.getTelefono() << "," << Hst.getPromedio()<< endl;
	map<int,Reserva*> ResHst;
	map<int,Reserva*> Res=getColReservas();
	cout<< "Las reservas asociadas son:"<< endl;
	for(auto it=Res.begin();it!=Res.end();it++){
		ResHst.emplace(it->first,it->second);
		cout<< it->second->getCodigo(), it->second->getCheckIn(), it->second->getCheckOut();
	}
	Hst.getReservas()=ResHst;
	map<int, Habitacion*> HabHst;
	map<int, Habitacion*> Hab=getColHabitaciones();
	cout<< "Las habitaciones son:"<< endl;
	for(auto itH=Hab.begin();itH!=Hab.end();itH++){
		HabHst.emplace(itH->first,itH->second);
		cout<< itH->second->getNumero(), itH->second->getPrecioNoche(), itH->second->getPrecioNoche();
	}
	Hst.getHabitaciones()=HabHst;
	list<Calificacion*> Cal=getColCal();
	list<DTCalificacion> Cali;
	list<Calificacion*>:: iterator it=Cal.begin();
	cout<< "Las comentarios son:"<< endl;
	while(it!=Cal.end()){
		DTCalificacion aux=(*it)->getDTCalificacion();
		Cali.push_back(aux);
		cout<< (*it)->getPuntaje(), (*it)->getComentarioEmp(), (*it)->getComentarioHuesp();
		it++;
	}
	Hst.getComentarios()=Cali;
	return Hst;
}

DTIdEstadia Hostal::accesoaReservas(){}

DataEstadia Hostal::accederaReservas(DTIdEstadia est){}

void Hostal::hallarReserva(std::string mailHuesp, int codigoRes, std::string respuesta){}

DTHostalProm Hostal::getDTHostalProm(){}

set<int> Hostal::obtenerHabitaciones(DTFecha in, DTFecha out){ //ADE - PROBARLA Y VER Q ANDE BIEN
	set<int> res;
	for(auto it=ColHabitaciones.begin();it!=ColHabitaciones.end();it++){
		if (it->second->consultarReservas(in, out))
			res.insert(it->second->getNumero());
	}
return res;
}

Habitacion* Hostal::seleccionarHab(int numHab){ //ADE - VERIFICAR Q FUNCION
	return ColHabitaciones.find(numHab)->second;
}

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





