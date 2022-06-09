

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

Set(DTCal) ControladorUsuario::obtenerComentariosAResponder(string mail){
}

Set(string) ControladorUsuario::obtenerHuespedes(){
}

void ControladorUsuario::seleccionar(string mailHuesped){
}

void ControladorUsuario::IngresarHuesped(string nombre,string email,string password,bool esFinger){
}

void ControladorUsuario::IngresarEmpleado(string nombre,string email,string password,TipoCargo cargo){
}

void ControladorUsuario::ConfirmarAltaUsuario(){
}

void ControladorUsuario::CancelarAltaUsuario(){
}

Set(string) ControladorUsuario::ObtenerUsuarios(){
}

DTHuesped ControladorUsuario::SeleccionarHuesped(string email){
}

DataEmpleado ControladorUsuario::SeleccionarEmpleado(string email){
}

Set(DTEmpleado) ControladorUsuario::getEmpleados(Hostal h){
}

Empleado ControladorUsuario::SeleccionarEmpleado(TipoCargo cargoEmp,string mailEmp){
}

void ControladorUsuario::AsignarCargoAEmpleado(){
}

void ControladorUsuario::BuscarHuesped(string email){
}

void ControladorUsuario::SuscribirEmpleado(string emp){
}

Set(DTCalificacion) ControladorUsuario::ObtenerNotificaciones(string email){
}

void EliminarNotificaciones(){
}
