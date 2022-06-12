#include "../../include/sistema/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){
}

//NO VA
int ControladorUsuario::getCantHuesped() {
	return cantHuespedes;
}
int ControladorUsuario::getCantEmpleado(){
	return cantEmpleados;
}

bool ControladorUsuario::getTipoUsuario(){
	return tipoUsuario;
}

void ControladorUsuario::setTipoUsuario(bool nuevoTipo){
	tipoUsuario = nuevoTipo;
}


std::string ControladorUsuario::getNombreIngresado(){
	return nombreIngresado;
}

ControladorUsuario* ControladorUsuario::getInstance(){
	if (instancia == NULL)
		instancia = new ControladorUsuario();
	return instancia;
}

map<string,Empleado*> ControladorUsuario::getColEmpleados(){
	return ColEmpleados;
}

Empleado* ControladorUsuario::getEmpleadoIngresado(){
	return empleadoIngresado;
}

CargoEmpleado* ControladorUsuario::getCargoIngresado(){
	return cargoIngresado;
}

void ControladorUsuario::ingresarHostal(Hostal* h){
	hostalIngresado = h;
}

void ControladorUsuario::ingresarEmpleadoPunt(Empleado* emp){
	empleadoIngresado = emp;
}

void ControladorUsuario::ingresarCargo(CargoEmpleado* cargo){
	cargoIngresado = cargo;
}

void ControladorUsuario::IngresarHuesped(std::string nombre,std::string email,std::string password,bool esFinger){//BIEN
	nombreIngresado = nombre;	
	emailIngresado = email;
	passIngresada = password;
	esFingIngresado = esFinger;
}

void ControladorUsuario::IngresarEmpleado(std::string nombre,std::string email,std::string password){//BIEN
	nombreIngresado = nombre;
	emailIngresado = email;
	passIngresada = password;
	hostalIngresado = NULL; 
}

void ControladorUsuario::ConfirmarAltaUsuario(){//BIEN
	bool esta;
	if (tipoUsuario == 0) {//Si tipoUsuario es 0, entonces se ingreso un huesp
		if (ColHuespedes.find(emailIngresado) == ColHuespedes.end())
			esta = false;
		else 
			esta = true;
		if (!esta){
			Huesped *huesp = new Huesped(nombreIngresado,emailIngresado,passIngresada,esFingIngresado);
			ColHuespedes.insert({emailIngresado,huesp});
			cantHuespedes++; 
		}
		else
			throw std::invalid_argument("Ya existe un huesped con el mismo email.");   
	}
	else {
		if (ColEmpleados.find(emailIngresado) == ColEmpleados.end())
			esta = false;
		else 
			esta = true;
		if (!esta){
			Empleado *emp = new Empleado(nombreIngresado,emailIngresado,passIngresada);
			ColEmpleados.insert({emailIngresado,emp});
			cantEmpleados++;
		}
		else 
			throw std::invalid_argument("Ya existe un empleado con el mismo email.");   
		
	}
} 
 
void ControladorUsuario::CancelarAltaUsuario(){//BIEN
	nombreIngresado = "";
	emailIngresado = "";
	passIngresada = "";
	if (tipoUsuario == 0) //Si tipoUsuario es 0, entonces se ingreso un huesp
		esFingIngresado = false; //
	else // sino se ingreso un emp
		cargoIngresado = NULL;
}
set<DTCal> ControladorUsuario::obtenerComentariosAResponder(string mail){
}

set<string> ControladorUsuario::obtenerHuespedes(){
	set<string> emailHuespedes;
	for( map<std::string, Huesped*>::iterator i= ColHuespedes.begin(); i != ColHuespedes.end(); i++){
		std::string email = (*i).first;
		emailHuespedes.insert(email);
	}
	return emailHuespedes;
}

void ControladorUsuario::seleccionar(string mailHuesped){
}

set<string> ControladorUsuario::ObtenerUsuarios(){ //BIEN
	set<string> users;
	for( map<std::string, Huesped*>::iterator i= ColHuespedes.begin(); i != ColHuespedes.end(); i++){
		std::string email = (*i).first;
		std::string nombre = (*i).second->getNombre();
		std::string user = "huesped: nombre: "+nombre+" ->email: " + email;
		users.insert(user);
	} 
	for( map<std::string, Empleado*>::iterator i= ColEmpleados.begin(); i != ColEmpleados.end(); i++){
		std::string email = (*i).first;
		std::string nombre = (*i).second->getNombre();
		std::string user = "empleado:nombre: "+nombre+" ->email: " + email;
		users.insert(user);
	} 
	return users;		
}

DTHuesped* ControladorUsuario::SeleccionarHuesped(string email){ //BIEN 
	Huesped* h = ColHuespedes.find(email)->second;
	std::string nom = h->getNombre();
	std::string mail = email;
	bool esFinger = h->getEsFinger();
	DTHuesped *huesped = new DTHuesped(nom,mail,esFinger);
	return huesped;
}

DataEmpleado* ControladorUsuario::SeleccionarEmpleado2(string email){//cambie el nombre daba error sobrecarga 
	Empleado* e = ColEmpleados.find(email)->second;
	std::string nom = e->getNombre();
	std::string mail = email;
	CargoEmpleado* cargo = e->getCargoEmpleado();
	Hostal* h = e->getHostalAsociado();
	std::string hostal = h->getNombre();
	DataEmpleado *empleado = new DataEmpleado(nom,mail,cargo,hostal);
	return empleado;
}

list<DTEmpleado> ControladorUsuario::getEmpleados(Hostal* h){
		list<DTEmpleado> dtemps;
		ingresarHostal(h);
		auto iter = ColEmpleados.begin();
		while(iter!=ColEmpleados.end()){
			Empleado* emp= iter->second;
			if(emp->TrabajaEnHostal()){
				DTEmpleado dtemp = emp->getDTEmpleado();
				dtemps.push_back(dtemp);
			}
			++iter;	
		}
	return dtemps;
}

Empleado* ControladorUsuario::SeleccionarEmpleado(CargoEmpleado* cargoEmp,string mailEmp,Hostal*  host){
	Empleado* emp = ColEmpleados.find(mailEmp)->second;
	//cout << getCantEmpleado();
	//cout << emp->getEmail();
	if(emp->getEmail()==mailEmp){
		ingresarEmpleadoPunt(emp);
		ingresarCargo(cargoEmp);
	}
	return emp;
}

void ControladorUsuario::AsignarCargoAEmpleado(){
	empleadoIngresado->AsignarEmpleadoAHostal(cargoIngresado,hostalIngresado);
	ingresarCargo(NULL);
	ingresarHostal(NULL);
	ingresarEmpleadoPunt(NULL);
}

void ControladorUsuario::BuscarHuesped(string email){
	Huesped* Hsp= ColHuespedes.find(email)->second;
}

void ControladorUsuario::SuscribirEmpleado(string emp){
}

set<DTCalificacion> ControladorUsuario::ObtenerNotificaciones(string email){
}

void EliminarNotificaciones(){
}
