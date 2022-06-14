#include "../../include/sistema/ControladorHostal.h"

ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal(){
	codigoRes = 1000; //inicializo el codigo de las reservas, luego se incrementa uno en cada reserva q se haga
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
	this->capacidad = capacidad;
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

list<DTHostalProm> ControladorHostal::ObtenerHostalesProm(){
	list<DTHostalProm> res;
	for(map<std::string,Hostal*>::iterator i= ColHostales.begin(); i != ColHostales.end(); i++){
		DTHostalProm infoHostal = (*i).second->getDTHostalProm((*i).second);
		res.push_back(infoHostal);
	}
	return res;
}

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

void ControladorHostal::confirmarAltaReserva(){
	SingletonFechaHora *horario = SingletonFechaHora::getInstance();
	DTFecha horaactual = horario->FechaHoraSistema();
	int codigo = generarCodigoReserva();
	Reserva* res = hostalIngresado->reservar(horaactual,codigo,fechaInIngresada,fechaOutIngresada,huespRecordado,gruppOindIngresado,totalHuespIngresado,acompaniantesIngresados); //si la reserva es individual  lepaso acompañantes vacio
	res->setHab(habRecordada);
	habRecordada->asociarResAHab(res);
	acompaniantesIngresados.clear();
	huespRecordado = NULL;
	nombreHostalIngresado = "";
	//DTFecha fechaInIngresada;
	//DTFecha fechaOutIngresada;
	//bool gruppOindIngresado;
	//int totalHuespIngresado;
	habRecordada = NULL;
}

int ControladorHostal::generarCodigoReserva(){
	codigoRes++;
	return codigoRes;
}

void ControladorHostal::cancelarAltaReserva(){
	acompaniantesIngresados.clear();
	huespRecordado = NULL;
	nombreHostalIngresado = "";
	//DTFecha fechaInIngresada;
	//DTFecha fechaOutIngresada;
	//bool gruppOindIngresado;
	//int totalHuespIngresado;
	habRecordada = NULL;
}

set<std::string> ControladorHostal::ConsultarTop3Hostal(){}

set<DTCalificacion> ControladorHostal::ObtenerCalificaciones(std::string nombreHostal) {}

//void ControladorHostal::ObtenerCalificaciones(TipoCargo cargoEmp, std::string emailEmp){}

set<DTReserva*> ControladorHostal::ObtenerReservasNC(std::string nombreHostal, std::string email, int promo){
	promo = promo; //para recordar
	Hostal* Hst =ColHostales.find(nombreHostal)->second;
	hostalIngresado = Hst; //para recordar
	set<DTReserva*> colReservasNC = Hst->BuscarRes(email);
	return colReservasNC;
}

void ControladorHostal::ReservaNCElegida(int codigoRes){
	bool resp = hostalIngresado->ingresoAlHostal(codigoRes); //para mi devuelvo un bool xq tengo que saber si el codigo que puso es correcto o puso cualqueir cosa
	SingletonFechaHora *FH = SingletonFechaHora::getInstance();
	DTFecha hs = FH->FechaHoraSistema();
	hostalIngresado->CreateAddEstadia(hs,promo, codigoRes);
}

void ControladorHostal::DatosHuesped(std::string nombreHostal,std::string email){}

void ControladorHostal::SeleccionarHostal(std::string nomHostal){
	Hostal* Hst=ColHostales.find(nomHostal)->second;
	ingresarHostal(Hst);
}

void ControladorHostal::ingresarEstadiasFinalizadas(list<Estadia*> Est){
	EstadiasFinalizadas=Est;
}

void ControladorHostal::ingresarEstadiaFinalizada(Estadia* est){
	EstadiaFinalizada=est;
}

void ControladorHostal::ingresarEmailHuesped(string email){
	emailHuesped=email;
}

void ControladorHostal::ingresarNombreHuesped(string nom){
	nombreHuesped=nom;
}


list<Estadia*> ControladorHostal::ListaEstadiasFinalizadas(std::string email){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	SingletonFechaHora* FH = SingletonFechaHora::getInstance();
	DTFecha hrs= FH->FechaHoraSistema();
	string nombre;
	list<Estadia*> estadias=cu->BuscarHuesped(email, hrs, nombre);
	ingresarNombreHuesped(nombre);
	ingresarEmailHuesped(email);
	ingresarEstadiasFinalizadas(estadias);
	return estadias;
}

void ControladorHostal::SeleccionarEstadia(Estadia estadia){
	list<Estadia*>::iterator it=EstadiasFinalizadas.begin();
	while((*it)->getReserva()->getCodigo()!=estadia.getReserva()->getCodigo()){
		++it;
	}
	ingresarEstadiaFinalizada(*it);
}

void ControladorHostal::ConfirmarCalificacion (std::string comentario, int puntaje){
	SingletonFechaHora* FH = SingletonFechaHora::getInstance();
	DTFecha hrs=FH->FechaHoraSistema();
	hostalIngresado->AgregarComentarios(comentario,puntaje,hrs,EstadiaFinalizada,obs);
}

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

list<DTReservaComp*> ControladorHostal::ObtenerReservasComp(std::string nombreHostal){
	Hostal* h= ColHostales.find(nombreHostal)->second;
	list<DTReservaComp*> dtreservas = h->ObtenerReservas();
	return dtreservas;
}

set<DTIdEstadia> ControladorHostal::ObtenerDTIdEstadia(std::string nombreHostal){}

DataEstadia ControladorHostal::ObtenerinfoEstadia(DTIdEstadia estadia){}

DTCalificacion ControladorHostal::MostrarCalificacion(){}

DTReserva ControladorHostal::MostrarInfoReserva(){}

void ControladorHostal::LiberarMemoria(){}

set<DTReserva> ControladorHostal::ObtenerReservas(std::string nombreHostal){}

void ControladorHostal::SeleccionarReserva(int codigoRes){}

void ControladorHostal::ConfirmarEliminarReserva(){}

void ControladorHostal::CancelarBajaReserva(){}


