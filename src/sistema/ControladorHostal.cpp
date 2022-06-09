#include "../../include/sistema/ControladorHostal.h"

ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal(){

}

ControladorHostal* ControladorHostal:: getInstance(){
	if (instancia == NULL)
		instancia = new ControladorHostal();
	return instancia; 
}

void ControladorHostal::agregarHostal(string nombre, string direccion, int telefono){}

Set(DTCal) ControladorHostal::ObtenerComentariosAResponder(string email) {}

void ControladorHostal::ResponderComentarios (string emailHuesp, int codigoRes, string respuesta) {}

Set(DTHostalProm) ControladorHostal::ObtenerHostales(){}

void ControladorHostal::ingresarDatosReserva(string nombreHostal, DTFecha in, DTFecha out, bool grupOind, int totalHuesp){}

Set(int) ControladorHostal::obtenerHabitacionesDisponibles(DTFecha in, DTFecha out){}

void ControladorHostal::seleccionarHabitacion(int numHab){}

Set(string) ControladorHostal::obtenerHuespedesRegistrados(){}

void ControladorHostal::seleccionarHuesped(string emailHuesp){}

void ControladorHostal::confirmarAltaReserva(){}

int ControladorHostal::generarCodigoReserva();

void ControladorHostal::cancelarReserva(){}

Set(DTReserva) ControladorHostal::DatosHuesped(string nombreHostal, string email, int promo){}

void ControladorHostal::ReservaNCElegida(int codigoRes){}

void ControladorHostal::DatosHuesped(string nombreHostal,string email){}

void ControladorHostal::registrarHab(){}

void ControladorHostal::cancelarAlta(){}

void ControladorHostal::asignarHab(string nombreHostal, int num, float precio, int capacidad){}

Set(string) ControladorHostal::ObtenerHostales() {}

Set(DTIdEstadia) ControladorHostal::SeleccionarHostal(string nombreHostal){}

DataEstadia ControladorHostal::SeleccionarEstadia(DTIdEstadia estadia){}

DTCalificacion ControladorHostal::MostrarCalificacion(){}

DTReserva ControladorHostal::MostrarInfoReserva(){}

void ControladorHostal::LiberarMemoria(){}

set<DTEmpleado> ControladorHostal::ObtenerDtEmpleado(std::string nombreHostal){
	set<DTEmpleado> dtemps;
	Hostal* h = ColHostales.find(nombreHostal)->second;
	if(h->getNombre()==nombreHostal){
		ControladorUsuario* cu = ControladorUsuario::getInstance();
		auto iter = cu->getColEmpleados().begin();
		while(iter!=cu->getColEmpleados().end()){
			Empleado* emp= h->getColEmpleados().find(iter->second->getEmail())->second;
			if(iter->second->getEmail()==emp->getEmail()){
					
			}
			
		}
	}
}

void ControladorHostal::SeleccionarEmpleado(TipoCargo cargoEmp, string emailEmp){}

void ControladorHostal::ConfirmarAsignacionAUsuario(){}

void ControladorHostal::CancelarAsignacionAUsuario(){}

Set(DTReservaComp) ControladorHostal::SeleccionarHostal(string nombreHostal){}

Set(string) ControladorHostal::ConsultarTop3Hostal(){}

void ControladorHostal::SeleccionarEmpleado(TipoCargo cargoEmp, string emailEmp){}

Set(DTReserva) ControladorHostal::SeleccionarHostal(string nombreHostal){}

void ControladorHostal::SeleccionarReserva(int codigoRes){}

void ControladorHostal::ConfirmarEliminarReserva(){}

void ControladorHostal::SeleccionarHostal(string nombreHostal){}

Set(DTIdEstadia) ControladorHostal::ListaEstadiasFinalizadas(string email){}

void ControladorHostal::SeleccionarEstadia(DTIdEstadia estadia){}

void ControladorHostal::ConfirmarCalificacion (string comentario, int puntaje){}

DataHostalComp ControladorHostal::ObtenerHostalComp(std::string nombreHostal){
	Hostal* Hst=ColHostales.find(nombreHostal)->second;
	if (Hst->getNombre()== nombreHostal){
		set<DataHostalComp> HstSel= Hst->getDTHostal();
	}
	
}

void ControladorHostal::CancelarBajaReserva(){}

Set(DTCalificacion) ControladorHostal::SeleccionarHostal(string nombreHostal) {}

