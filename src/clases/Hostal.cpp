#include "../../include/clases/Hostal.h"
#include "../../include/clases/ReservaGrupal.h"
#include "../../include/clases/ReservaIndividual.h"

Hostal::Hostal(){}

Hostal::Hostal(std::string nom,std::string direc,int tel,int prom) {
	nombre = nom;
	direccion = direc;
	telefono = tel;
	promedio = prom; 
	map<int,Reserva*> ColReservas;
	map<int, Habitacion*> ColHabitaciones;
	list<Calificacion*> ColCal;
	map<std::string,Empleado*> ColEmpleadosHost;
}

Hostal :: ~Hostal() {}

map<std::string,Empleado*> Hostal::getColEmpleados(){
	return ColEmpleadosHost;
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
	map<int,Reserva*> ResHst;
	map<int,Reserva*> Res=getColReservas();
	for(auto it=Res.begin();it!=Res.end();it++){
		ResHst.emplace(it->first,it->second);
	}
	Hst.setReservas(ResHst);
	map<int, Habitacion*> HabHst;
	map<int, Habitacion*> Hab=getColHabitaciones();
	for(auto itH=Hab.begin();itH!=Hab.end();itH++){
		HabHst.emplace(itH->first,itH->second);
	}
	Hst.setHabitaciones(HabHst);
	list<Calificacion*> Cal=getColCal();
	list<DTCalificacion> Cali;
	list<Calificacion*>:: iterator it=Cal.begin();
	while(it!=Cal.end()){
		DTCalificacion aux=(*it)->getDTCalificacion();
		Cali.push_back(aux);
		it++;
	}
	Hst.setComentarios(Cali);
	return Hst;
}

DTIdEstadia Hostal::accesoaReservas(){}

DataEstadia Hostal::accederaReservas(DTIdEstadia est){}

void Hostal::hallarReserva(std::string mailHuesp, int codigoRes, std::string respuesta){}

DTHostalProm Hostal::getDTHostalProm(Hostal* host){
	DTHostalProm infoHostal = DTHostalProm(host->getNombre(),host->getDireccion(),host->getPromedio());
	return infoHostal;
}

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

void Hostal::AgregarEmpleadoAHostal(Empleado* emp) {
	ColEmpleadosHost.insert({emp->getEmail(),emp});
	//cout<<emp->getEmail();
	//ColEmpleados.insert(pair<string,Empleado*>(emp->getEmail(),emp));
   // bool x = ColEmpleadosHost.empty();//getColEmpleados();
       /* for( map<std::string, Empleado*>::iterator i= x.begin(); i != x.end(); i++){
       		std::string email = (*i).first;
			cout << email;
    	}*/
}

list<DTReservaComp*> Hostal::ObtenerReservas(){
	list<DTReservaComp*> dtreservas;
	auto iter = ColReservas.begin();
	if(iter!=ColReservas.end())
		while(iter!=ColReservas.end()){
			Reserva* res = iter->second;
			DTReservaComp* dtres=res->getDTReservaComp();
			dtreservas.push_back(dtres);
			iter++;
		}
	else{
		Reserva* res = iter->second;
		DTReservaComp* dtres= res->getDTReservaComp();
		dtreservas.push_back(dtres);
	} 
return dtreservas;

}

set<DTCalificacion> Hostal::obtenerCalificaciones(){}

int Hostal::getPromCal(){}

bool Hostal::TrabajaEnHostal(){}

void Hostal::ingresoAlHostal(int codigoRes){}

void Hostal::buscarR(std::string email ){}

set<DTReserva*> Hostal::BuscarRes(std::string email){
	set<DTReserva*> colReservasNC;
	for(map<int,Reserva*>::iterator i= ColReservas.begin(); i != ColReservas.end(); i++){
		Reserva* res = (*i).second;
		colReservasNC = res->validarHuespedRegistrado(email);
	}

return colReservasNC;
}

void Hostal::agregarHabAlHost(Habitacion* hab){
	ColHabitaciones.insert(pair<int, Habitacion*>(hab->getNumero(),hab));
}


void Hostal::recordarHostal(){}

Reserva* Hostal::reservar(DTFecha horaactual, int cod, DTFecha desde, DTFecha hasta, Huesped* huesp,bool grupOind,int totalHuesp,set<Huesped*> acompaniantes){
	Reserva* res;
	if (grupOind == 1) {//es grupal
		ReservaGrupal *res = new ReservaGrupal(cod,desde,hasta,horaactual,totalHuesp);
		res->setHues(huesp);
		ColReservas.insert({cod,res});
		res->setHuespedes(acompaniantes);
	} else {
		ReservaIndividual *res = new ReservaIndividual(cod,desde,hasta,horaactual);
		res->setHues(huesp);
		ColReservas.insert({cod,res});
	}
	return res;
}


       


