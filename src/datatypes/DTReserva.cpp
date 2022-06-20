#include "../../include/datatypes/DTReserva.h"

DTReserva::DTReserva(int cod, DTFecha ent, DTFecha sal, EstadoReserva est){
    codigo = cod;
    checkIn = ent;
    checkOut = sal;
    estado = est;
}
DTReserva::~DTReserva(){
    checkIn.~DTFecha();
    checkOut.~DTFecha();
}

int DTReserva::getCodigo(){
    return codigo;
}

DTFecha DTReserva::getCheckIn(){
    return checkIn;
}

DTFecha DTReserva::getCheckOut(){
    return checkOut;
}

EstadoReserva DTReserva::getEstado(){
    return estado;
}

