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
	set<string> hostales;
	for( map<std::string,Hostal*>::iterator i= ColHostales.begin(); i != ColHostales.end(); i++){
		std::string nombre = (*i).first;
		std::string frase = "Hostal: "+nombre+"";
		hostales.insert(frase);
	}
return hostales;
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
	Habitacion *hab = new Habitacion(numero, precioNoche, capacidad);
	hostalIngresado->agregarHabAlHost(hab);
	hostalIngresado = NULL;
	numero = -1;
	precioNoche = -1;
	capacidad = -1;

}

void ControladorHostal::cancelarAltaHabitacion(){
//el sistema libera la memoria asocida a los daos de habitacion y hostal elegido
numero = -1;
precioNoche = -1;
capacidad = -1;
hostalIngresado = NULL;
}

list<DTEmpleado> ControladorHostal::ObtenerEmpleados(std::string nombreHostal){
	list<DTEmpleado> dtemps;
	Hostal* h = ColHostales.find(nombreHostal)->second;
	ingresarHostal(h);
	if(h->getNombre()==nombreHostal){
		ControladorUsuario* cu = ControladorUsuario::getInstance();
		dtemps = cu->getEmpleados(h);
	}
	return dtemps;
}

void ControladorHostal::SeleccionarEmpleado(CargoEmpleado *cargoEmp, std::string emailEmp){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Empleado* emp = cu->SeleccionarEmpleado(cargoEmp,emailEmp,hostalIngresado);
	ingresarEmpleado(emp);
}

void ControladorHostal::ConfirmarAsignacionDeEmpleado(){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	cu->AsignarCargoAEmpleado();
	hostalIngresado->AgregarEmpleadoAHostal(empleadoIngresado);
	cout << hostalIngresado->getColEmpleados().size();
	ingresarHostal(NULL);
	ingresarEmpleado(NULL);
}

void ControladorHostal::CancelarAsignacionDeEmpleado(){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	ingresarHostal(NULL);
	ingresarEmpleado(NULL);
	cu->ingresarEmpleadoPunt(NULL);
	cu->ingresarCargo(NULL);
	cu->ingresarHostal(NULL);
}

set<DTHostalProm> ControladorHostal::ObtenerHostalesProm(){}

void ControladorHostal::ingresarDatosReserva(std::string nombreHostal, DTFecha in, DTFecha out, bool grupOind, int totalHuesp){ //LISTA
	std::string nombreHostalIngresado = nombreHostal;
	DTFecha fechaInIngresada = in;
	DTFecha fechaOutIngresada = out;
	bool gruppOindIngresado = grupOind;
	int totalHuespIngresado = totalHuesp;
}

set<int> ControladorHostal::obtenerHabitacionesDisponibles(DTFecha in, DTFecha out){
	Hostal* Host=ColHostales.find(nombreHostalIngresado)->second;
	set<int> ColHabDisp = Host->obtenerHabitaciones(in,out);
	return ColHabDisp;
}

void ControladorHostal::seleccionarHabitacion(int numHab){ //ADE - VERIFICAR Q FUNCIONE
	hostalIngresado = ColHostales.find(nombreHostalIngresado)->second;
	habRecordada = hostalIngresado->seleccionarHab(numHab);
}

set<std::string> ControladorHostal::obtenerHuespedesRegistrados(){//ADE - VERIFICAR Q FUNCIONE
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	set<std::string> res = ctrl->obtenerHuespedes();
	return res;
}

void ControladorHostal::seleccionarHuesped(std::string emailHuesp){
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	huespRecordado = ctrl->getColHuespedes().find(emailHuesp)->second;
}

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
	Hostal* Hst=ColHostales.find(nombreHostal)->second;
	DataHostalComp HstSel;
	if (Hst->getNombre()== nombreHostal){
		HstSel= Hst->getDTHostal();
	}
	return HstSel;
}

/*set<DTReservaComp> ControladorHostal::ObtenerReservasComp(std::string nombreHostal){
	Hostal* h= ColHostales.find(nombreHostal)->second;
	list<DTReservaComp> dtreservas = h->ObtenerReservas();
}*/

set<DTIdEstadia> ControladorHostal::ObtenerDTIdEstadia(std::string nombreHostal){}

DataEstadia ControladorHostal::ObtenerinfoEstadia(DTIdEstadia estadia){}

DTCalificacion ControladorHostal::MostrarCalificacion(){}

DTReserva ControladorHostal::MostrarInfoReserva(){}

void ControladorHostal::LiberarMemoria(){}

set<DTReserva> ControladorHostal::ObtenerReservas(std::string nombreHostal){}

void ControladorHostal::SeleccionarReserva(int codigoRes){}

void ControladorHostal::ConfirmarEliminarReserva(){}

void ControladorHostal::CancelarBajaReserva(){}


