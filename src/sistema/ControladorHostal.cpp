#include "../../include/sistema/ControladorHostal.h"

ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal(){

}

ControladorHostal* ControladorHostal:: getInstance(){
	if (instancia == NULL)
		instancia = new ControladorHostal();
	return instancia; 
}

void ControladorHostal::agregarHostal(std::string nombre, std::string direccion, int telefono){}

set<DTCal> ControladorHostal::ObtenerComentariosAResponder(std::string email) {}

void ControladorHostal::ResponderComentarios (std::string emailHuesp, int codigoRes, std::string respuesta) {}

set<DTHostalProm> ControladorHostal::ObtenerHostales(){}

void ControladorHostal::ingresarDatosReserva(std::string nombreHostal, DTFecha in, DTFecha out, bool grupOind, int totalHuesp){}

set<int> ControladorHostal::obtenerHabitacionesDisponibles(DTFecha in, DTFecha out){}

void ControladorHostal::seleccionarHabitacion(int numHab){}

set<std::string> ControladorHostal::obtenerHuespedesRegistrados(){}

void ControladorHostal::seleccionarHuesped(std::string emailHuesp){}

void ControladorHostal::confirmarAltaReserva(){}

int ControladorHostal::generarCodigoReserva();

void ControladorHostal::cancelarReserva(){}

Set(DTReserva) ControladorHostal::DatosHuesped(std::string nombreHostal, std::string email, int promo){}

void ControladorHostal::ReservaNCElegida(int codigoRes){}

void ControladorHostal::DatosHuesped(std::string nombreHostal,std::string email){}

void ControladorHostal::registrarHab(){}

void ControladorHostal::cancelarAlta(){}

void ControladorHostal::asignarHab(std::string nombreHostal, int num, float precio, int capacidad){}

set<std::string> ControladorHostal::ObtenerHostales() {}

set<DTIdEstadia> ControladorHostal::SeleccionarHostal(std::string nombreHostal){}

DataEstadia ControladorHostal::SeleccionarEstadia(DTIdEstadia estadia){}

DTCalificacion ControladorHostal::MostrarCalificacion(){}

DTReserva ControladorHostal::MostrarInfoReserva(){}

void ControladorHostal::LiberarMemoria(){}

lista<DTEmpleado> ControladorHostal::ObtenerDtEmpleado(std::std::string nombreHostal){
	lista<DTEmpleado> dtemps;
	Hostal* h = ColHostales.find(nombreHostal)->second;
	if(h->getNombre()==nombreHostal){
		ControladorUsuario* cu = ControladorUsuario::getInstance();
		auto iter = cu->getColEmpleados().begin();
		while(iter!=cu->getColEmpleados().end()){
			Empleado* emp= h->getColEmpleados().find(iter->second->getEmail())->second;
			if(iter->second->getEmail()==emp->getEmail()){
				DTEmpleado dtemp = DTEmpleado(emp->getNombre(),emp->getEmail(),emp->getCargoEmpleado());
				dtemps.insert(dtemp);			+
			+iterator;			r
	return dtemps;eturn dtemps;}
	}
}

void ControladorHostal::SeleccionarEmpleado(TipoCargo cargoEmp, std::string emailEmp){}

void ControladorHostal::ConfirmarAsignacionAUsuario(){}

void ControladorHostal::CancelarAsignacionAUsuario(){}

Set(DTReservaComp) ControladorHostal::SeleccionarHostal(std::string nombreHostal){}

set<std::string> ControladorHostal::ConsultarTop3Hostal(){}

void ControladorHostal::SeleccionarEmpleado(TipoCargo cargoEmp, std::string emailEmp){}

Set(DTReserva) ControladorHostal::SeleccionarHostal(std::string nombreHostal){}

void ControladorHostal::SeleccionarReserva(int codigoRes){}

void ControladorHostal::ConfirmarEliminarReserva(){}

void ControladorHostal::SeleccionarHostal(std::string nombreHostal){}

set<DTIdEstadia> ControladorHostal::ListaEstadiasFinalizadas(std::string email){}

void ControladorHostal::SeleccionarEstadia(DTIdEstadia estadia){}

void ControladorHostal::ConfirmarCalificacion (std::string comentario, int puntaje){}

DataHostalComp ControladorHostal::ObtenerHostalComp(std::std::string nombreHostal){
	Hostal* Hst=ColHostales.find(nombreHostal)->second;
	if (Hst->getNombre()== nombreHostal){
		set<DataHostalComp> HstSel= Hst->getDTHostal();
	}
	
}

void ControladorHostal::CancelarBajaReserva(){}

Set(DTCalificacion) ControladorHostal::SeleccionarHostal(std::string nombreHostal) {}

