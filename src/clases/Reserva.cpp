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

void Reserva::BuscarEstadia(std::string email, DTFecha hrs, Estadia* & est){
    list<Estadia*>::iterator it;
    while((*it)->getHuesp()->getEmail()!=email){
        ++it;
    }
    bool EsFin= hrs.compararFecha((*it)->getCheckOut(),hrs);
    if(EsFin==true){
        Estadia* EstSel=(*it)->getEstadia();    
        est=EstSel;
    }
}

Reserva ::~Reserva() {
    delete hab;
    delete hues;
   //delete est;
}
