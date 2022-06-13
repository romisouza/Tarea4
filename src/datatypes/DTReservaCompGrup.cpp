#include "../include/clases/ReservaGrupal.h"
#include "../include/clases/Reserva.h"
#include "../include/datatypes/DTFecha.h"
#include "../include/datatypes/DTReservaCompGrup.h"

DTReservaCompGrup::DTReservaCompGrup(int codi, DTFecha CheckIn, DTFecha CheckOut,EstadoReserva est,int Num, map<std::string,Huesped*> Huespedes):DTReservaComp(codi,CheckIn,CheckOut,est,Num){
    huespedes = Huespedes;
}

map<std::string,Huesped*> DTReservaCompGrup::getHuesp(){
    return huespedes;
}