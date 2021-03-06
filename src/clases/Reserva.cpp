#include "../../include/clases/Reserva.h"


Reserva::Reserva(int cod,DTFecha entrada,DTFecha salida,DTFecha realiza){
    codigo=cod;
    checkIn = entrada;
    checkOut = salida;
    fechaRealizada = realiza;
    estado= Abierta;
    this->hab = NULL;
    hues = NULL;
    list<Estadia*> est;
}

int Reserva::getCodigo(){
    return codigo;
}

DTFecha Reserva::getCheckIn(){
    return checkIn;
}

DTFecha Reserva::getCheckOut(){
    return checkOut;
}

DTFecha Reserva::getRealizada(){
    return fechaRealizada;
}

EstadoReserva Reserva::getEstado(){
    return estado;
}

Habitacion* Reserva::getHab(){
    return hab;
}

Huesped* Reserva::getHues(){
    return hues;
}

list<Estadia*> Reserva::getEstadia(){
    return est;
}

void Reserva::setCodigo(int cod){
    codigo=cod;
}

void Reserva::setCheckIn(DTFecha in){
    checkIn = in;
}

void Reserva::setCheckOut(DTFecha out){
    checkOut = out;
}

void Reserva::setRelizada(DTFecha realiza){
    fechaRealizada = realiza;
}

void Reserva::setEstado(EstadoReserva est){
    estado = est;
}

void Reserva::setHab(Habitacion* habitacion){
    this->hab = habitacion;
}


void Reserva::setHues(Huesped* huesped){
    hues=huesped;
}

void Reserva::setEstadia(list<Estadia*> estadia){
    est = estadia;
}

/*DTReserva Reserva::getDTReserva(){
    DTReserva Res=DTReserva(getCodigo(),getCheckIn(),getCheckOut(), getEstado());
    return Res;
}
*/

void Reserva::BuscarEstadia(std::string email, DTFecha hrs,list<DTIdEstadia> & estId){
    list<Estadia*>::iterator it=est.begin();
    while((it!=est.end() && (*it)->getHuesp()->getEmail()!=email)){
        ++it;
    }
    if (it != est.end()){
	bool EsFin= hrs.compararFecha((*it)->getCheckOut(),hrs);
	if(EsFin==true){
	    DTIdEstadia EstSel=(*it)->getDTIdEstadia();   
	    estId.push_back(EstSel);
	}
    }
}

list<DTIdEstadia> Reserva::accederaEstadias(Reserva* res){
	list<DTIdEstadia>  setEstadias;
	DTIdEstadia estadia;
    list<Estadia*> coleccionEst = res->getEstadia();
	for (list<Estadia*>::iterator i = coleccionEst.begin();i != coleccionEst.end();++i){
		setEstadias.push_back((*i)->getDTIdEstadia());
	}
	return setEstadias;
}

DataEstadia* Reserva::BuscarRes(Reserva* res,DTIdEstadia e, std::string nombreHostal){
	DataEstadia* estadia;
    	list<Estadia*> est = res->getEstadia(); 
	for (list<Estadia*>::iterator i = est.begin(); i != est.end();i++){
		std::string email = ((*i)->getHuesp()->getEmail());
		if (email.compare(e.getEmail())==0){
			estadia = (*i)->getDataEstadia();
		}
	}
	return estadia;
}

void Reserva::hallarEstadia(string mailHuesp,string respuesta){
    for(auto it=est.begin();it != est.end();++it){
        string mailActual = (*it)->getHuesp()->getEmail();
        if (mailActual == mailHuesp)
           (*it)->getCal()->setComentarioEmp(respuesta);
        }
}


set<Calificacion*> Reserva::eliminarComentarios(){
    set<Calificacion*> coment; 
    if(est.begin()!=est.end()){
        for(auto iter=est.begin();iter!=est.end();++iter){
            Calificacion* cal=(*iter)->getCal();
            coment.emplace(cal);
       }
    }
    return coment;
}


Reserva ::~Reserva() {
    delete hab;
    delete hues;
    est.clear();
}
