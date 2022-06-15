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
	this->capacidad = capacidad;
	hostalIngresado = ColHostales.find(nombreHostal)->second;
}

void ControladorHostal::registrarHab(){
//se anade una nueva habitacion al hostal seleccionado con los datos de la habi recordada ant
	//se crea una instancia de hab con los datos ing, se cea un link de la instancia hab y hostal, y se 
	//libera la mem asociada a hab hostal elegido
	Habitacion *hab = new Habitacion(numero, precioNoche, capacidad,hostalIngresado);
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
	//cout << hostalIngresado->getColEmpleados().size();
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
	nombreHostalIngresado = nombreHostal;
	fechaInIngresada = in;
	fechaOutIngresada = out;
	gruppOindIngresado = grupOind;
	totalHuespIngresado = totalHuesp;
}

list<int> ControladorHostal::obtenerHabitacionesDisponibles(DTFecha in, DTFecha out){
	Hostal* Host=ColHostales.find(nombreHostalIngresado)->second;
	list<int> ColHabDisp = Host->obtenerHabitaciones(in,out);
	return ColHabDisp;
}

void ControladorHostal::seleccionarHabitacion(int numHab){ //ADE - VERIFICAR Q FUNCIONE
	hostalIngresado = ColHostales.find(nombreHostalIngresado)->second;
	habRecordada = hostalIngresado->seleccionarHab(numHab);
}

list<std::string> ControladorHostal::obtenerHuespedesRegistrados(){//ADE - VERIFICAR Q FUNCIONE
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	list<std::string> res = ctrl->obtenerHuespedes();
	return res;
}

void ControladorHostal::seleccionarHuesped(std::string emailHuesp){
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	huespRecordado = ctrl->getColHuespedes().find(emailHuesp)->second;
}

void ControladorHostal::seleccionarAcompaniante(std::string emailHuesp){// va a ir loopeada en el main, con algo tipo "ingrese el mail de cada huesped q forme parte de la reserva, para finalizar presione 0"
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	Huesped *huesp = ctrl->getColHuespedes().find(emailHuesp)->second;
	acompaniantesIngresados.insert(huesp);
}

void ControladorHostal::confirmarAltaReserva(){
	SingletonFechaHora *horario = SingletonFechaHora::getInstance();
	DTFecha horaactual = horario->FechaHoraSistema();
	int codigo = generarCodigoReserva();
	Reserva* res = hostalIngresado->reservar(horaactual,codigo,fechaInIngresada,fechaOutIngresada,huespRecordado,gruppOindIngresado,totalHuespIngresado,acompaniantesIngresados); //si la reserva es individual  lepaso acompañantes vacio
	res->setHab(habRecordada);
	map<int,Reserva*> colRes = huespRecordado->getColReservasHuesp();
	colRes.insert({codigo,res});
	huespRecordado->setColReservasHuesp(colRes);
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

set<std::string> ControladorHostal::ConsultarTop3Hostal(){
	auto iter = ColHostales.begin();
	
}

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
	hostalIngresado->ingresoAlHostal(codigoRes); //para mi devuelvo un bool xq tengo que saber si el codigo que puso es correcto o puso cualqueir cosa
	SingletonFechaHora *FH = SingletonFechaHora::getInstance();
	DTFecha hs = FH->FechaHoraSistema();
	hostalIngresado->CreateAddEstadia(hs,promo, codigoRes);
}

void ControladorHostal::DatosHuesped(std::string nombreHostal,std::string email){}

void ControladorHostal::SeleccionarHostal(std::string nomHostal){
	Hostal* Hst=ColHostales.find(nomHostal)->second;
	ingresarHostal(Hst);
}


void ControladorHostal::ingresarEstadiaFinalizada(Estadia* est){
	EstadiaFinalizada=est;
}


list<DTIdEstadia> ControladorHostal::ListaEstadiasFinalizadas(std::string email){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	SingletonFechaHora* FH = SingletonFechaHora::getInstance();
	DTFecha hrs= FH->FechaHoraSistema();
	list<DTIdEstadia> estadias=cu->BuscarHuesped(email, hrs);
	return estadias;
}

void ControladorHostal::SeleccionarEstadia(DTIdEstadia estadia){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Estadia* Est= cu->BuscarHuesped2(estadia);
	ingresarEstadiaFinalizada(Est);
}

void ControladorHostal::ConfirmarCalificacion (std::string comentario, int puntaje){
	SingletonFechaHora* FH = SingletonFechaHora::getInstance();
	DTFecha hrs=FH->FechaHoraSistema();
	hostalIngresado->AgregarComentarios(comentario,puntaje,hrs,EstadiaFinalizada,obs);
}

void ControladorHostal::ResponderComentario(std::string emailHuesp, int codigoRes, std::string respuesta){
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	Hostal* host = ctrl->getHostalTrabajaEmp();
	host->hallarReserva(emailHuesp,codigoRes,respuesta);
}

list<DTCal> ControladorHostal::ObtenerComentariosAResponder(std::string email){
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	list<DTCal> res = ctrl->obtenerComentariosAResponder(email);
	return res;
}

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

list<DTIdEstadia> ControladorHostal::ObtenerDTIdEstadia(std::string nombreHostal){
	hostalRecordado = nombreHostal;
	Hostal* host = ColHostales.find(hostalRecordado)->second;
	list<DTIdEstadia> SetDTIdEstadia = host->accesoaReservas(host);
	return SetDTIdEstadia;
}

DataEstadia* ControladorHostal::ObtenerinfoEstadia(DTIdEstadia estadia){
	Hostal *host = ColHostales.find(hostalRecordado)->second;
	estadiaRecordada = host->accederaReservas(estadia,hostalRecordado);
	return estadiaRecordada;
}

DTCalificacion ControladorHostal::MostrarCalificacion(){
	DTCalificacion cal;
	std::string host = hostalRecordado;
	Hostal* h = ColHostales.find(hostalRecordado)->second;
	DataEstadia* estadia = estadiaRecordada;
	int codigo = estadia->getCod();
	Reserva* res = h->getColReservas().find(estadia->getCod())->second;
	list<Estadia*> est = res->getEstadia();
	for (list<Estadia*>::iterator i = est.begin(); i != est.end();i++){
		string email = (*i)->getHuesp()->getEmail();
		string mail = estadia->getHuesped();
		if (email.compare(mail) == 0){
			cal= (*i)->getCal()->getDTCalificacion();
		}
	}
	return cal;
}

DTReserva* ControladorHostal::MostrarInfoReserva(std::string nombreHostal, int codigoRes){
	Hostal* host = ColHostales.find(nombreHostal)->second;
	DTReserva* res = host->ReservaAsociada(codigoRes);
	return res;
}

void ControladorHostal::LiberarMemoria(){}

void ControladorHostal::ingresarReserva(Reserva* res){
	reservaIngresada=res;
}

list<DTReserva*> ControladorHostal::ObtenerReservas(std::string nombreHostal){
	Hostal* Hst=ColHostales.find(nombreHostal)->second;
	ingresarHostal(Hst);
	list<DTReserva*> lista=Hst->BuscarReservas();
	return lista;
}

void ControladorHostal::SeleccionarReserva(int codigoRes){
	Reserva* res=hostalIngresado->getColReservas().find(codigoRes)->second;
	ingresarReserva(res);
}

void ControladorHostal::ConfirmarEliminarReserva(){
	hostalIngresado->EliminarRes(reservaIngresada);
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	cu->eliminarReserva(reservaIngresada->getHues()->getEmail(),reservaIngresada->getCodigo());

}

void ControladorHostal::CancelarBajaReserva(){
	hostalIngresado=NULL;
	reservaIngresada=NULL;
}

void ControladorHostal::agregarObserver(IObserver* o){
	obs.push_back(o);
}

void ControladorHostal::eliminarObserver(IObserver* o){
	auto it=obs.begin();
	while((*it)!=o){
		it++;
	}
	obs.erase(it);
}

void ControladorHostal::SuscribirEmpleado(string emp){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Empleado* EmpSel=cu->buscarEmpleado(emp);
	agregarObserver(EmpSel);
}

list<DTCalificacion> ControladorHostal::ObtenerNotificaciones(string email){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Empleado* EmpSel=cu->buscarEmpleado(email);
	empleadoIngresado=EmpSel;
	list<DTCalificacion> aux;
	for(auto it=EmpSel->getCalifObs().begin();it!=EmpSel->getCalifObs().end(); it++){
		DTCalificacion cal= DTCalificacion((*it)->getPuntaje(),(*it)->getComentarioHuesp(), (*it)->getComentarioEmp());
		aux.push_back(cal);
	}
	return aux;
}

void ControladorHostal::EliminarNotificaciones(){
	while(!empleadoIngresado->getCalifObs().empty()){
		empleadoIngresado->getCalifObs().pop_front();
	}
	empleadoIngresado=NULL;
}

list<DTEmpleado> ControladorHostal::ObtenerEmpleados(){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	list<DTEmpleado> aux=cu->getNombresEmp();
	return aux;
}

void ControladorHostal::eliminarSuscripcion(string emp){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Empleado* EmpSel=cu->buscarEmpleado(emp);
	eliminarObserver(EmpSel);
}
