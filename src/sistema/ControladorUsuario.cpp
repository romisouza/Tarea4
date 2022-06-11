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

void ControladorUsuario::IngresarHuesped(std::string nombre,std::string email,std::string password,bool esFinger){
	nombreIngresado = nombre;	
	emailIngresado = email;
	passIngresada = password;
	esFingIngresado = esFinger;
}

void ControladorUsuario::IngresarEmpleado(std::string nombre,std::string email,std::string password,CargoEmpleado *cargo){
	nombreIngresado = nombre;
	emailIngresado = email;
	passIngresada = password;
	cargoIngresado = cargo; 
}

void ControladorUsuario::ConfirmarAltaUsuario(){
	bool esta;
	if (cargoIngresado == NULL) {//Si cargoIngresado es Null, entonces se ingreso un huesp
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
			Empleado *emp = new Empleado(nombreIngresado,emailIngresado,passIngresada,cargoIngresado);
			ColEmpleados.insert({emailIngresado,emp});
			cantEmpleados++;
		}
		else 
			throw std::invalid_argument("Ya existe un empleado con el mismo email.");   
		
	}
} 
 
void ControladorUsuario::CancelarAltaUsuario(){
	nombreIngresado = "";
	emailIngresado = "";
	passIngresada = "";
	if (cargoIngresado == NULL) //Si cargoIngresado es Null, entonces se ingreso un huesp
		esFingIngresado = false; //
	else // sino se ingreso un emp
		cargoIngresado = NULL;
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

DataEmpleado ControladorUsuario::SeleccionarEmpleado2(string email){//cambie el nombre daba error sobrecarga 
}

list<DTEmpleado> ControladorUsuario::getEmpleados(Hostal* h){
		list<DTEmpleado> dtemps;
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
	if(emp->getEmail()==mailEmp){
		ingresarEmpleadoPunt(emp);
		ingresarCargo(cargoEmp);
	}
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
