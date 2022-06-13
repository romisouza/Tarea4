#include "../../include/datatypes/DTReservaComp.h"

DTReservaComp::DTReservaComp(int codi, DTFecha CheckIn, DTFecha CheckOut, EstadoReserva est,int Num){
    codigo=codi;
    checkIn=CheckIn;
    checkOut=CheckOut;
    estado=est;
    numHab=Num;
}

int DTReservaComp::getCodigo(){
    return codigo;
}

DTFecha DTReservaComp::getCheckIn(){
    return checkIn;
}

DTFecha DTReservaComp::getCheckOut(){
    return checkOut;
}

EstadoReserva DTReservaComp::getEstado(){
    return estado;
}

int DTReservaComp::getNumHab(){
    return numHab;
}




DTReservaComp::~DTReservaComp(){
    
}