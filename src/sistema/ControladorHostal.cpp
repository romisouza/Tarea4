#include "../../include/sistema/ControladorHostal.h"

ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal(){

}

void ControladorHostal::ingresarHostal(Hostal* host){
	hostalIngresado = host;
}

void ControladorHostal::ingresarEmpleado(Empleado* emp){
	empleadoIngresado = emp;
}

ControladorHostal* ControladorHostal:: getInstance(){
	if (instancia == NULL)
		instancia = new ControladorHostal();
	return instancia; 
}

void ControladorHostal::agregarHostal(std::string nombre, std::string direccion, int telefono){ //LISTA
	Hostal *host = new Hostal(nombre,direccion,telefono,0);
	ControladorHostal::ColHostales.insert(pair<string,Hostal*>(nombre,host)); 
}
set<std::string> ControladorHostal::ObtenerNombreHostales() {
	/*set<string> hostales;
	for( map<std::string,Hostal*>:iterador i= ColHostales.begin(); i != ColHostales.end(); i++){
		hostales.insert((*i).first);
		//cout << (*i).first << endl;
	}*/
}

void ControladorHostal::asignarHab(std::string nombreHostal, int num, float precio, int capacidad){
	numero = num;
	precioNoche = precio;
	capacidad = capacidad;
	hostalIngresado = ColHostales.find(nombreHostal)->second;
}

void ControladorHostal::registrarHab(){
	//se anade una nueva habitacion al hostal seleccionado con los datos de la habi recordada ant
	//se crea una instancia de hab con los datos ing, se cea un link de la instancia hab y hostal, y se 
	//libera la mem asociada a hab hostal elegido
	Habitacion* hab = new Habitacion(numero, precioNoche, capacidad);
	
    //res?? = Reserva*;


}

void ControladorHostal::cancelarAltaHabitacion(){
//el sistema libera la memoria asocida a los daos de habitacion y hostal elegido
}

list<DTEmpleado> ControladorHostal::ObtenerDtEmpleado(std::string nombreHostal){
	/*list<DTEmpleado> dtemps;
	Hostal* h = ColHostales.find(nombreHostal)->second;
	ingresarHostal(h);
	if(h->getNombre()==nombreHostal){
		ControladorUsuario* cu = ControladorUsuario::getInstance();
		auto iter = cu->getColEmpleados().begin();
		while(iter!=cu->getColEmpleados().end()){
			Empleado* emp= h->getColEmpleados().find(iter->second->getEmail())->second;
			if(iter->second->getEmail()==emp->getEmail()){
				DTEmpleado dtemp = DTEmpleado(emp->getNombre(),emp->getEmail(),emp->getCargoEmpleado());
				dtemps.push_back(dtemp);			
				++iter;			
			}
		}
	}
	return dtemps;*/
}

void ControladorHostal::SeleccionarEmpleado(CargoEmpleado cargoEmp, std::string emailEmp){
	/*ControladorUsuario* cu = ControladorUsuario::getInstance();
	Empleado* emp = cu->getColEmpleados().find(emailEmp);
	if(emp->getEmail()==emailEmp){
		ingresarEmpleado(emp);
		cu->ingresarEmpleadoPunt(emp);
		cu->ingresarCargo(cargoEmp);
	}*/
}

void ControladorHostal::ConfirmarAsignacionDeEmpleado(){
	/*ControladorUsuario* cu = ControladorUsuario::getInstance();
	Empleado* emp = cu->getEmpleadoIngresado();
	emp->setCargoEmpleado(cu->getCargoIngresado());
	emp->setHostalAsociado(hostalIngresado);
	hostalIngresado->getColEmpleados().emplace(emp->getEmail(),emp);
	ingresarHostal(NULL);
	cu->ingresarEmpleadoPunt(NULL);*/
	
}

void ControladorHostal::CancelarAsignacionDeEmpleado(){
	/*ControladorUsuario* cu = ControladorUsuario::getInstance();
	ingresarHostal(NULL);
	cu->ingresarEmpleadoPunt(NULL);*/
}

set<DTHostalProm> ControladorHostal::ObtenerHostalesProm(){}

void ControladorHostal::ingresarDatosReserva(std::string nombreHostal, DTFecha in, DTFecha out, bool grupOind, int totalHuesp){}

set<int> ControladorHostal::obtenerHabitacionesDisponibles(DTFecha in, DTFecha out){}

void ControladorHostal::seleccionarHabitacion(int numHab){}

set<std::string> ControladorHostal::obtenerHuespedesRegistrados(){}

void ControladorHostal::seleccionarHuesped(std::string emailHuesp){}

void ControladorHostal::confirmarAltaReserva(){}

int ControladorHostal::generarCodigoReserva(){}

void ControladorHostal::cancelarAltaReserva(){}

set<std::string> ControladorHostal::ConsultarTop3Hostal(){}

set<DTCalificacion> ControladorHostal::ObtenerCalificaciones(std::string nombreHostal) {}

//void ControladorHostal::ObtenerCalificaciones(TipoCargo cargoEmp, std::string emailEmp){}

set<DTReserva> ControladorHostal::ObtenerReservasNC(std::string nombreHostal, std::string email, int promo){}

void ControladorHostal::ReservaNCElegida(int codigoRes){}

void ControladorHostal::DatosHuesped(std::string nombreHostal,std::string email){}

void ControladorHostal::SeleccionarHostal(std::string nomHostal){
	/*Hostal* Hst=ColHostales.find(nomHostal)->second;
	ingresarHostal(Hst);*/
}

set<DTIdEstadia> ControladorHostal::ListaEstadiasFinalizadas(std::string email){
	/*ControladorUsuario* cu = ControladorUsuario::getInstance();
	SingletonFechaHora* FH = SingletonFechaHora::getInstance();
	DTFecha hrs= FH->FechaHoraSitema();
	cu->BuscarHuesped(email);*/
}

void ControladorHostal::SeleccionarEstadia(DTIdEstadia estadia){}

void ControladorHostal::ConfirmarCalificacion (std::string comentario, int puntaje){}

void ControladorHostal::ResponderComentarios (std::string emailHuesp, int codigoRes, std::string respuesta) {}

set<DTCal> ControladorHostal::ObtenerComentariosAResponder(std::string email) {}

DataHostalComp ControladorHostal::ObtenerHostalComp(std::string nombreHostal){
	/*Hostal* Hst=ColHostales.find(nombreHostal)->second;
	DataHostalComp HstSel;
	if (Hst->getNombre()== nombreHostal){
		HstSel= Hst->getDTHostal();
	}
	return HstSel;*/
}

set<DTReservaComp> ControladorHostal::ObtenerReservasComp(std::string nombreHostal){}

set<DTIdEstadia> ControladorHostal::ObtenerDTIdEstadia(std::string nombreHostal){}

DataEstadia ControladorHostal::ObtenerinfoEstadia(DTIdEstadia estadia){}

DTCalificacion ControladorHostal::MostrarCalificacion(){}

DTReserva ControladorHostal::MostrarInfoReserva(){}

void ControladorHostal::LiberarMemoria(){}

set<DTReserva> ControladorHostal::ObtenerReservas(std::string nombreHostal){}

void ControladorHostal::SeleccionarReserva(int codigoRes){}

void ControladorHostal::ConfirmarEliminarReserva(){}

void ControladorHostal::CancelarBajaReserva(){}


