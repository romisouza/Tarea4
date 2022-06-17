/*#include "../include/clases/ReservaGrupal.h"
#include "../include/clases/Reserva.h"
#include "../include/datatypes/DTFecha.h"*/
#include "../../include/datatypes/DTReservaCompGrup.h"

DTReservaCompGrup::DTReservaCompGrup(int codi, DTFecha CheckIn, DTFecha CheckOut,Huesped* huesp,EstadoReserva est,int Num, set<Huesped*> Huespedes):DTReservaComp(codi,CheckIn,CheckOut,huesp,est,Num){
    huespedes = Huespedes;
}

set<Huesped*> DTReservaCompGrup::getHuesp(){
    return huespedes;
}

DTReservaCompGrup::~DTReservaCompGrup(){
    
}