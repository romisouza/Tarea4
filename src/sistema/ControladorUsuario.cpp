#include "../../include/sistema/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){
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

CargoEmpleado ControladorUsuario::getCargoIngresado(){
	return cargoIngresado;
}

void ControladorUsuario::ingresarEmpleadoPunt(Empleado* emp){
	empleadoIngresado = emp;
}

void ControladorUsuario::ingresarCargo(CargoEmpleado cargo){
	cargoIngresado = cargo;
}

void ControladorUsuario::IngresarHuesped(string nombre,string email,string password,bool esFinger){
	nombreIngresado = nombre;	
	emailIngresado = email;
	passIngresada = password;
	esFingIngresado = esFinger;
}

void ControladorUsuario::IngresarEmpleado(string nombre,string email,string password,CargoEmpleado cargo){
	nombreIngresado = nombre;
	emailIngresado = email;
	passIngresada = password;
	cargoIngresado = cargo;
}

void ControladorUsuario::ConfirmarAltaUsuario(){
	/*bool esta;
	if (cargoIngresadonombreIngresado) {//Si cargoIngresado es Nul, entonces se ingreso un huesp
		if (ColHuespedes.find(emailIngresado) == ColHuespedes.end())
			esta = false;
		else 
			esta = true;
		if (!esta){
			Huesped *huesp = new Huesped(nombreIngresado,emailIngresado,passIngresada,esFingIngresado);
			ColHuespedes.insert({emailIngresado,huesp});
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
			Empleado *emp = new Empleado(nombreIngresado,emailIngresado,passIngresada,cargoIngresado);
			ColEmpleados.insert({emailIngresado,emp});
		}
		else 
			throw std::invalid_argument("Ya existe un empleado con el mismo email.");   
		
	}*/
}

void ControladorUsuario::CancelarAltaUsuario(){
	/*nombreIngresado = "";
	emailIngresado = "";
	passIngresada = "";
	if (cargoIngresado.compare("")==0) //Si cargoIngresado es Null, entonces se ingreso un huesp
		esFingIngresado = "";
	else // sino se ingreso un emp
		cargoIngresado = ;*/
}
set<DTCal> ControladorUsuario::obtenerComentariosAResponder(string mail){
}

set<string> ControladorUsuario::obtenerHuespedes(){
}

void ControladorUsuario::seleccionar(string mailHuesped){
}

set<string> ControladorUsuario::ObtenerUsuarios(){
		set<string> users;
		for( map<std::string, Huesped*>::iterator i= ColHuespedes.begin(); i != ColHuespedes.end(); i++){
			users.insert((*i).first);
			//cout << (*i).first << ": " << (*i).second << endl;
		} 
		for( map<std::string, Empleado*>::iterator i= ColEmpleados.begin(); i != ColEmpleados.end(); i++){
			users.insert((*i).first);
			//cout << (*i).first << ": " << (*i).second << endl;
		} 
		
}

DTHuesped ControladorUsuario::SeleccionarHuesped(string email){
}

DataEmpleado ControladorUsuario::SeleccionarEmpleado(string email){
}

set<DTEmpleado> ControladorUsuario::getEmpleados(Hostal h){
}

Empleado ControladorUsuario::SeleccionarEmpleado(CargoEmpleado cargoEmp,string mailEmp){
}

void ControladorUsuario::AsignarCargoAEmpleado(){
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
