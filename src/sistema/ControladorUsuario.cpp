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


Empleado* ControladorUsuario::getEmpleadoIngresado(){
	return empleadoIngresado;
}

bool ControladorUsuario::existeEmp(std::string email){
	bool res = (ColEmpleados.find(email) != ColEmpleados.end());
	return res;
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
		if (ColHuespedes.find(emailIngresado) == ColHuespedes.end() && ColEmpleados.find(emailIngresado) == ColEmpleados.end() )
			esta = false;
		else 
			esta = true;
		if (!esta){
			Huesped *huesp = new Huesped(nombreIngresado,emailIngresado,passIngresada,esFingIngresado);
			ColHuespedes.insert({emailIngresado,huesp});
			cantHuespedes++; 
		}
		else
			throw std::invalid_argument("Ya existe un usuario con el mismo email.");   
	}
	else {
		if (ColEmpleados.find(emailIngresado) == ColEmpleados.end() && ColHuespedes.find(emailIngresado) == ColHuespedes.end())
			esta = false;
		else 
			esta = true;
		if (!esta){
			Empleado *emp = new Empleado(nombreIngresado,emailIngresado,passIngresada);
			ColEmpleados.insert({emailIngresado,emp});
			cantEmpleados++;
		}
		else 
			throw std::invalid_argument("Ya existe un usuario con el mismo email.");   
		
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
list<DTCal> ControladorUsuario::obtenerComentariosAResponder(string mail){
	if (ColEmpleados.find(mail) == ColEmpleados.end()){
		throw std::invalid_argument("No existe un empleado con dicho mail.");
	} else {
	Empleado *emp = ColEmpleados.find(mail)->second;
	hostalTrabajaEmp = emp->getHostalAsociado();
	list<DTCal> res = emp->obtenerComentarios();
	return res;
	}
}

Hostal* ControladorUsuario::getHostalTrabajaEmp(){
	return hostalTrabajaEmp;
}

list<string> ControladorUsuario::obtenerHuespedes(){
	list<string> emailHuespedes;
	for(map<std::string, Huesped*>::iterator i= ColHuespedes.begin(); i != ColHuespedes.end(); i++){
		std::string email = (*i).first;
		emailHuespedes.push_back(email);
	}
	return emailHuespedes;
}

map<std::string,Empleado*> ControladorUsuario::getColEmpleados(){
	return ColEmpleados;
}

map<std::string,Huesped*> ControladorUsuario::getColHuespedes(){
	return ColHuespedes;
}

set<string> ControladorUsuario::ObtenerUsuarios(){ //BIEN
	set<string> users;
	for( map<std::string, Huesped*>::iterator i= ColHuespedes.begin(); i != ColHuespedes.end(); i++){
		std::string email = (*i).first;
		std::string nombre = (*i).second->getNombre();
		std::string user = "Huesped: \n nombre: "+nombre+" \n email: " + email;
		users.insert(user);
	} 
	for( map<std::string, Empleado*>::iterator i= ColEmpleados.begin(); i != ColEmpleados.end(); i++){
		std::string email = (*i).first;
		std::string nombre = (*i).second->getNombre();
		std::string user = "Empleado: \n nombre: "+nombre+" \n email: " + email;
		users.insert(user);
	} 
	return users;		
}

DTHuesped* ControladorUsuario::SeleccionarHuesped(string email){ //BIEN 
	if (ColHuespedes.find(email) != ColHuespedes.end()){
		Huesped* h = ColHuespedes.find(email)->second;
		std::string nom = h->getNombre();
		std::string mail = email;
		bool esFinger = h->getEsFinger();
		DTHuesped *huesped = new DTHuesped(nom,mail,esFinger);
		return huesped;
	}else
		throw std::invalid_argument("No existe un huesped con ese email"); 
}

DataEmpleado* ControladorUsuario::SeleccionarEmpleado2(string email){//cambie el nombre daba error sobrecarga 
	if (ColEmpleados.find(email) != ColEmpleados.end()){
		Empleado* e = ColEmpleados.find(email)->second;
		std::string nom = e->getNombre();
		std::string mail = email;
		CargoEmpleado* cargo = e->getCargoEmpleado();
		Hostal* h = e->getHostalAsociado();
		std::string hostal = h->getNombre();
		DataEmpleado *empleado = new DataEmpleado(nom,mail,cargo,hostal);
		return empleado;
	} else
		throw std::invalid_argument("No existe un empleado con ese email"); 

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
	if (ColEmpleados.find(mailEmp) != ColEmpleados.end()){
		Empleado* emp = ColEmpleados.find(mailEmp)->second;
		if(emp->getEmail()==mailEmp){
			ingresarEmpleadoPunt(emp);
			ingresarCargo(cargoEmp);
		}
		return emp;
	}
	else
		throw std::invalid_argument("No existe un empleado con ese email."); 
}

void ControladorUsuario::AsignarCargoAEmpleado(){
	empleadoIngresado->AsignarEmpleadoAHostal(cargoIngresado,hostalIngresado);
	ingresarCargo(NULL);
	ingresarHostal(NULL);
	ingresarEmpleadoPunt(NULL);
}

list<DTIdEstadia> ControladorUsuario::BuscarHuesped(string email, DTFecha hrs){
	Huesped* Hsp= ColHuespedes.find(email)->second;
	list<DTIdEstadia> Est=Hsp->BuscarEstadias(email, hrs);
	return Est;
}

Estadia* ControladorUsuario::BuscarHuesped2(DTIdEstadia est){
	Huesped* Hsp= ColHuespedes.find(est.getEmail())->second;
	Estadia* Est=Hsp->BuscarEstadias2(est);
	return Est;
}

list<DTEmpleado> ControladorUsuario::getNombresEmp(){
	list<DTEmpleado> aux;
	for(auto it=ColEmpleados.begin();it!=ColEmpleados.end();it++){
		DTEmpleado emp= DTEmpleado(it->second->getNombre(),it->second->getEmail(), it->second->getCargoEmpleado());
		aux.push_back(emp);
	}
	return aux;
}

Empleado* ControladorUsuario::buscarEmpleado(std::string emp){
	if(ColEmpleados.find(emp) == ColEmpleados.end()){
		throw std::invalid_argument ("No existe empleado con el email ingresado.");
	}
	else{
		Empleado* aux=ColEmpleados.find(emp)->second;
	return aux;
	}
	
}

void ControladorUsuario::eliminarReserva(string email, int codRes){
	Huesped* Hsp=ColHuespedes.find(email)->second;
	Hsp->EliminarResHsp(codRes);
}

Huesped* ControladorUsuario::buscarHuesped(std::string email){
	Huesped* huesp = ColHuespedes.find(email)->second;
	return huesp;
}

list<std::string> ControladorUsuario::empleadosEnHostal(std::string nombreHostal){
	list<string> emp;
	bool hay= false;
	for (auto it=ColEmpleados.begin();it!=ColEmpleados.end();it++){
		if ((*it).second->getHostalAsociado() != NULL){
			if ((*it).second->getHostalAsociado()->getNombre() == nombreHostal){
				emp.push_back((*it).second->getEmail());
				hay = true;
			}
		}
	}
	if (!hay)
		throw std::invalid_argument("No hay empleados trabajando en ese hostal.");

	return emp;
}
