#include "../../include/datatypes/DTReserva.h"

DTReserva::DTReserva(int cod, DTFecha ent, DTFecha sal){
    codigo = cod;
    checkIn = ent;
    checkOut = sal;
}
DTReserva::~DTReserva(){}

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

