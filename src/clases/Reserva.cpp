#include "../../include/clases/Reserva.h"


Reserva::Reserva(int cod,DTFecha entrada,DTFecha salida,DTFecha realiza,Habitacion* hab,Huesped* huesp,Estadia* est){
    codigo=cod;
    checkIn = entrada;
    checkOut = salida;
    fechaRealizada = realiza;
    estado= Abierta;
    this->hab = hab;
    hues = huesp;
    this->est = est;
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

Estadia* Reserva::getEstadia(){
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

void Reserva::setEstadia(Estadia* estadia){
    est = estadia;
}

DTReserva Reserva::getDTReserva(){
    DTReserva Res=DTReserva(getCodigo(),getCheckIn(),getCheckOut());
    return Res;
}

Reserva ::~Reserva() {
    delete hab;
    delete hues;
    delete est;
}
