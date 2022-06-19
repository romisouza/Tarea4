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

void ControladorHostal::agregarHostal(std::string nombre, std::string direccion, string telefono){ //LISTA
	auto it = ColHostales.begin();
	while (it != ColHostales.end() && ((*it).second->getNombre() != nombre)){
		++it;
	}
	if (it == ColHostales.end()){
		Hostal *host = new Hostal(nombre,direccion,telefono,0);
		ControladorHostal::ColHostales.insert(pair<string,Hostal*>(nombre,host));
	} else {
		throw std::invalid_argument("Ya existe un hostal registrado con ese nombre.");
	}
}

set<std::string> ControladorHostal::ObtenerNombreHostales() {
	set<string> hostales;
	for( map<std::string,Hostal*>::iterator i= ColHostales.begin(); i != ColHostales.end(); i++){
		std::string nombre = (*i).first;
		std::string frase = nombre;
		hostales.insert(frase);
	}
return hostales;
}

void ControladorHostal::asignarHab(std::string nombreHostal, int num, float precio, int capacidad){
	if (ColHostales.find(nombreHostal) == ColHostales.end()) {
		throw std::invalid_argument("No existe un hostal con el nombre ingresado"); 
	}else {
		this->numero = num;
		this->precioNoche = precio;
		this->capacidad = capacidad;
		hostalIngresado = ColHostales.find(nombreHostal)->second;
	}
}

void ControladorHostal::registrarHab(){
	//se anade una nueva habitacion al hostal seleccionado con los datos de la habi recordada ant
	//se crea una instancia de hab con los datos ing, se cea un link de la instancia hab y hostal, y se 
	//libera la mem asociada a hab hostal elegido
	map<int,Habitacion*> hab = hostalIngresado->getColHabitaciones();
	if (hab.find(numero) != hab.end()) {//no se si esta bien
		throw std::invalid_argument("Ya existe una habitacion registrada en el sistema."); 
	}else{
		Habitacion *hab = new Habitacion(numero, precioNoche, capacidad,hostalIngresado);
		hostalIngresado->agregarHabAlHost(hab);
		hostalIngresado = NULL; //estas cosas para mi van afuera del else, xq si o si tengo que resetear o no?
		numero = -1;
		precioNoche = -1;
		capacidad = -1;
	}	
}

void ControladorHostal::cancelarAltaHabitacion(){
//el sistema libera la memoria asocida a los daos de habitacion y hostal elegido
numero = -1;
precioNoche = -1;
capacidad = -1;
hostalIngresado = NULL;
}

list<DTEmpleado> ControladorHostal::ObtenerEmpleados(std::string nombreHostal){
	if (ColHostales.find(nombreHostal) == ColHostales.end()) {
		throw std::invalid_argument("No existe un hostal con el nombre ingresado"); 
	}
	else{
		list<DTEmpleado> dtemps;
		Hostal* h = ColHostales.find(nombreHostal)->second;
		ingresarHostal(h);
		if(h->getNombre()==nombreHostal){
			ControladorUsuario* cu = ControladorUsuario::getInstance();
			dtemps = cu->getEmpleados(h);
		}
		return dtemps;
	}
}

void ControladorHostal::SeleccionarEmpleado(CargoEmpleado *cargoEmp, std::string emailEmp){
	if (hostalIngresado->getColEmpleados().find(emailEmp) == hostalIngresado->getColEmpleados().end()) {
		throw std::invalid_argument("No existe un empleado con el email ingresado"); 
	}
	else{
		ControladorUsuario* cu = ControladorUsuario::getInstance();
		Empleado* emp = cu->SeleccionarEmpleado(cargoEmp,emailEmp,hostalIngresado);
		ingresarEmpleado(emp);
	}
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
	if (ColHostales.find(nombreHostal) == ColHostales.end() || in.compararFecha(out,in)) {
		throw std::invalid_argument("Se produjo un error con los datos ingresados."); 
	} else {
		nombreHostalIngresado = nombreHostal;
		fechaInIngresada = in;
		fechaOutIngresada = out;
		gruppOindIngresado = grupOind;
		totalHuespIngresado = totalHuesp;
	}
}

list<int> ControladorHostal::obtenerHabitacionesDisponibles(DTFecha in, DTFecha out,int totalHuesp){
	if(in.compararFecha(out,in)){
		throw std::invalid_argument("La fecha de salida ingresada es menor a la fecha de entrada.");
	} else {
	Hostal* Host=ColHostales.find(nombreHostalIngresado)->second;
	list<int> ColHabDisp = Host->obtenerHabitaciones(in,out,totalHuesp);
	return ColHabDisp;
	}
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
	if (ctrl->getColHuespedes().find(emailHuesp) == ctrl->getColHuespedes().end()){
		throw std::invalid_argument("No existe un huesped con el mail ingresado.");
	} else
		huespRecordado = ctrl->getColHuespedes().find(emailHuesp)->second;
}

void ControladorHostal::seleccionarAcompaniante(std::string emailHuesp){// va a ir loopeada en el main, con algo tipo "ingrese el mail de cada huesped q forme parte de la reserva, para finalizar presione 0"
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	Huesped *huesp = ctrl->getColHuespedes().find(emailHuesp)->second;
	acompaniantesIngresados.insert(huesp);
}

int ControladorHostal::confirmarAltaReserva(){
	SingletonFechaHora *horario = SingletonFechaHora::getInstance();
	DTFecha horaactual = horario->FechaHoraSistema();
	int codigo = generarCodigoReserva();
	Reserva* res = hostalIngresado->reservar(horaactual,codigo,fechaInIngresada,fechaOutIngresada,huespRecordado,gruppOindIngresado,totalHuespIngresado,acompaniantesIngresados); //si la reserva es individual  lepaso acompañantes vacio
	res->setHab(habRecordada);
	map<int,Reserva*> colRes = huespRecordado->getColReservasHuesp();
	colRes.insert({codigo,res});
	huespRecordado->setColReservasHuesp(colRes);
	for (auto it=acompaniantesIngresados.begin();it!=acompaniantesIngresados.end();++it){
		map<int,Reserva*> reservas = (*it)->getColReservasHuesp();
		reservas.insert({codigo,res});
		(*it)->setColReservasHuesp(colRes);
	}
	habRecordada->asociarResAHab(res);
	acompaniantesIngresados.clear();
	huespRecordado = NULL;
	nombreHostalIngresado = "";
	//DTFecha fechaInIngresada;
	//DTFecha fechaOutIngresada;
	//bool gruppOindIngresado;
	//int totalHuespIngresado;
	habRecordada = NULL;
	return codigo;
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

list<std::string> ControladorHostal::ConsultarTop3Hostal(){
	//auto iter = ColHostales.begin();
	map<std::string,Hostal*> aux = ColHostales;
	//sort(aux.begin(),aux.end(),comparePuntajeHostal);
	list<Hostal*> ranking;
	for(auto it=aux.begin();it!=aux.end();it++){
		auto it2 = ranking.begin(); 
		while((*it2)!=NULL && it->second->getPromedio()< (*it2)->getPromedio()){
			it2++;	
		}
		if((*it2)==NULL)
			ranking.push_back(it->second);
		else{
			ranking.insert(it2,it->second);
		}
	}
	list<std::string> rankingOficial;
	auto it=ranking.begin();
	if(ranking.size()>3){
		int i=1;
		while(i<4){
			rankingOficial.push_back((*it)->getNombre());
			it++;
			i++;
		}
	}
	else{
		while((*it)!=NULL)
			rankingOficial.push_back((*it)->getNombre());
	}
	return rankingOficial;
}

list<DTCalificacion> ControladorHostal::ObtenerCalificaciones(std::string nombreHostal) {
	if (ColHostales.find(nombreHostal) == ColHostales.end()) {
		throw std::invalid_argument("No existe un hostal con el nombre ingresado"); 
	}
	else{
		Hostal *h = ColHostales.find(nombreHostal)->second;
		list<DTCalificacion> aux=h->obtenerCalificaciones();
		return aux;
	}
}

//void ControladorHostal::ObtenerCalificaciones(TipoCargo cargoEmp, std::string emailEmp){}

list<int> ControladorHostal::ObtenerReservasNC(std::string nombreHostal, std::string email){
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	if (ColHostales.find(nombreHostal) == ColHostales.end() || ctrl->getColHuespedes().find(email) == ctrl->getColHuespedes().end()) {
		throw std::invalid_argument("Ocurrió un error con los datos ingresados."); 
	}else{ //para recordar
	Hostal* Hst =ColHostales.find(nombreHostal)->second;
	this->hostalIngresado = Hst; //para recordar
	list<int> colReservasNC = Hst->BuscarRes(email);
	return colReservasNC;
	}
}

void ControladorHostal::ReservaNCElegida(int codigoRes,Huesped* huesp){
	map<int, Reserva*> res =hostalIngresado->getColReservas(); //asumo que hostal esta bien?
	SingletonFechaHora *FH = SingletonFechaHora::getInstance();
	if (res.find(codigoRes) == res.end()|| (FH->FechaHoraSistema()).compararFecha(FH->FechaHoraSistema(),(res.find(codigoRes))->second->getCheckOut())!=1 ) {
		throw std::invalid_argument("Ocurrió un error con los datos ingresados."); 
	}else{
	hostalIngresado->ingresoAlHostal(codigoRes); 
	SingletonFechaHora *FH = SingletonFechaHora::getInstance();
	DTFecha hs = FH->FechaHoraSistema();
	hostalIngresado->CreateAddEstadia(hs, codigoRes,huesp);
	}
}

void ControladorHostal::DatosHuesped(std::string nombreHostal,std::string email,bool &finalizoEst){ //finalizarEst
	ControladorUsuario *ctrl = ControladorUsuario::getInstance();
	map<std::string,Huesped*> huespedes = ctrl->getColHuespedes();
	if (ColHostales.find(nombreHostal) == ColHostales.end() || huespedes.find(email) == huespedes.end()) {
		throw std::invalid_argument("Ocurrió un error con los datos ingresados."); 
	}else{
		Hostal* Hst =ColHostales.find(nombreHostal)->second;
		SingletonFechaHora *FH = SingletonFechaHora::getInstance();
		DTFecha hs = FH->FechaHoraSistema();
		Hst->buscarR(email,hs,finalizoEst);
	}
}

void ControladorHostal::SeleccionarHostal(std::string nomHostal){
	if (ColHostales.find(nomHostal) == ColHostales.end()) {
		throw std::invalid_argument("No existe un hostal con el nombre ingresado"); 
	}
	else{
		Hostal* Hst=ColHostales.find(nomHostal)->second;
		ingresarHostal(Hst);
	}
}


void ControladorHostal::ingresarEstadiaFinalizada(Estadia* est){
	EstadiaFinalizada=est;
}


list<DTIdEstadia> ControladorHostal::ListaEstadiasFinalizadas(string email){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	map<std::string,Huesped*> huespedes = cu->getColHuespedes();
	if (huespedes.find(email) == huespedes.end()) {
		throw std::invalid_argument("No existe un usuario con el email ingresado"); 
	}
	else{
		
		SingletonFechaHora* FH = SingletonFechaHora::getInstance();
		DTFecha hrs= FH->FechaHoraSistema();
		list<DTIdEstadia> estadias=cu->BuscarHuesped(email, hrs);
		return estadias;
	}
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
	hostalIngresado=NULL;
	EstadiaFinalizada=NULL;
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

DataHostalComp ControladorHostal::ObtenerHostalComp(string nombreHostal){
	if (ColHostales.find(nombreHostal) == ColHostales.end()) {
		throw std::invalid_argument("No existe hostal con el nombre ingresado"); 
	}
	else{
		Hostal* Hst=ColHostales.find(nombreHostal)->second;
		DataHostalComp HstSel=Hst->getDTHostal();
		return HstSel;
	}
}

list<DTReservaComp*> ControladorHostal::ObtenerReservasComp(std::string nombreHostal){
	if (ColHostales.find(nombreHostal) == ColHostales.end()) {
		throw std::invalid_argument("No existe un hostal con el nombre ingresado"); 
	}
	else{
		Hostal* h= ColHostales.find(nombreHostal)->second;
		list<DTReservaComp*> dtreservas = h->ObtenerReservas();
		return dtreservas;
	}
}

list<DTIdEstadia> ControladorHostal::ObtenerDTIdEstadia(std::string nombreHostal){
	if (ColHostales.find(nombreHostal) != ColHostales.end()){
		hostalRecordado = nombreHostal;
		Hostal* host = ColHostales.find(hostalRecordado)->second;
		list<DTIdEstadia> SetDTIdEstadia = host->accesoaReservas(host);
		return SetDTIdEstadia;
	}else
		throw std::invalid_argument("No existe un hostal con ese email"); 
}

DataEstadia* ControladorHostal::ObtenerinfoEstadia(DTIdEstadia estadia){
	Hostal *host = ColHostales.find(hostalRecordado)->second;
	estadiaRecordada = host->accederaReservas(estadia,hostalRecordado);
	return estadiaRecordada;
}

DTCalificacion ControladorHostal::MostrarCalificacion(){
		existe = false;
		DTCalificacion cal;
		Hostal* h = ColHostales.find(hostalRecordado)->second;
		DataEstadia* estadia = estadiaRecordada;
		int codigo = estadia->getCod();
		Reserva* res = h->getColReservas().find(codigo)->second;
		list<Estadia*> est = res->getEstadia();
		for (list<Estadia*>::iterator i = est.begin(); i != est.end();i++){
			string email = (*i)->getHuesp()->getEmail();
			string mail = estadia->getHuesped();
			if ((*i)->getCal() != NULL) {
				existe = true;
				if (email.compare(mail) == 0){
					cal= (*i)->getCal()->getDTCalificacion();
				}
			}
		}
		return cal;
}

bool ControladorHostal:: ExisteCalif(){
	return existe;
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
	if (ColHostales.find(nombreHostal) == ColHostales.end()) {
		throw std::invalid_argument("No existe un hostal con el nombre ingresado"); 
	}
	else{
		Hostal* Hst=ColHostales.find(nombreHostal)->second;
		ingresarHostal(Hst);
		list<DTReserva*> lista=Hst->BuscarReservas();
		return lista;
	}
}

void ControladorHostal::SeleccionarReserva(int codigoRes){
	if (hostalIngresado->getColReservas().find(codigoRes) == hostalIngresado->getColReservas().end()) {
		throw std::invalid_argument("No existe una reserva con el codigo ingresado"); 
	}
	else{
		Reserva* res=hostalIngresado->getColReservas().find(codigoRes)->second;
		ingresarReserva(res);
	}
}

void ControladorHostal::ConfirmarEliminarReserva(){
	hostalIngresado->EliminarRes(reservaIngresada);
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Huesped* aux=reservaIngresada->getHues();
	cu->eliminarReserva(aux->getEmail(),reservaIngresada->getCodigo());

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
	if (!cu->existeEmp(email))
		throw std::invalid_argument("Email incorrecto."); 
	IObserver* EmpSel=BuscarEmp(email);
	EmpNoti=EmpSel;
	list<DTCalificacion> aux;
	list<Calificacion*> iter= EmpSel->getCalifObs();
	for(auto it=iter.begin();it!=iter.end(); ++it){
		DTCalificacion cal= DTCalificacion((*it)->getPuntaje(),(*it)->getComentarioHuesp(), (*it)->getComentarioEmp());
		aux.push_back(cal);
	}
	return aux;
}

IObserver* ControladorHostal::BuscarEmp(string email){
		auto it=obs.begin();
		while(((it)!= obs.end()) && ((*it)->getEmailObs()!=email)){
			it++;
		}
		return (*it);
}

void ControladorHostal::EliminarNotificaciones(){
	//list<Calificacion*> aux=empleadoIngresado->getCalifObs();
	//while(!aux.empty()){
		//aux.pop_front();
	//}
	EmpNoti->EliminarCalificaciones();
	EmpNoti=NULL;
}

list<DTEmpleado> ControladorHostal::ObtenerEmpleados(){
	ControladorUsuario* cu=ControladorUsuario::getInstance();
	list<DTEmpleado> emp=cu->getNombresEmp();
	return emp;
}

list<IObserver*> ControladorHostal::ObtenerSuscritos(){
	list<IObserver*>::iterator it=obs.begin();
	list<IObserver*> aux;
	while (it!=obs.end()){
		IObserver* emp=(*it)->getObserver();
		aux.push_back(emp);
		++it;
	}
	
	return aux;
}

void ControladorHostal::eliminarSuscripcion(string emp){
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Empleado* EmpSel=cu->buscarEmpleado(emp);
	eliminarObserver(EmpSel);
}

void ControladorHostal::actualizarFS(int anio,int mes,int dia ,int hora,int minutos){
	SingletonFechaHora* FH = SingletonFechaHora::getInstance();
	FH->actualizarFechaSistema(anio, mes, dia, hora, minutos);
}
