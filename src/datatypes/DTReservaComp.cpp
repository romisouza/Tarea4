
#include "../../include/datatypes/DTReservaComp.h"


DTReservaComp::DTReservaComp(int codi, DTFecha CheckIn, DTFecha CheckOut,EstadoReserva Est, int Num,map<string,Huesped*> Huespedes){
    codigo=codi;
    checkIn=CheckIn;
    checkOut=CheckOut;
    estado=Est;
    numHab=Num;
    huespedes=Huespedes
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

map<string,Huesped*> DTReservaComp::getHuesp(){
    return huespedes;
}


DTReservaComp::~DTReservaComp(){
    
}