#include "../../include/clases/Reserva.h"


Reserva::Reserva(int cod,DTFecha entrada,DTFecha salida,DTFecha realiza){
    codigo=cod;
    checkIn = entrada;
    checkOut = salida;
    fechaRealizada = realiza;
    estado= Abierta;
    this->hab = NULL;
    hues = NULL;
    //this->est = NULL;
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
    hab = habitacion;
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

void Reserva::BuscarEstadia(std::string email, DTFecha hrs,DTIdEstadia & estId){
    list<Estadia*>::iterator it=est.begin();
    while((*it)->getHuesp()->getEmail()!=email){
        ++it;
    }
    bool EsFin= hrs.compararFecha((*it)->getCheckOut(),hrs);
    if(EsFin==true){
        DTIdEstadia EstSel=(*it)->getDTIdEstadia();   
        estId=EstSel;
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
	for (list<Estadia*>::iterator i = res->getEstadia().begin(); i != res->getEstadia().end();i++){
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

void Reserva::EliminarEstadias(){
    auto it=est.begin();
    while((*it)!=NULL){
        (*it)->eliminarEstadia();
        est.remove((*it));
    }
    est.clear();
}

Reserva ::~Reserva() {
    delete hab;
    delete hues;
   //delete est;
}
