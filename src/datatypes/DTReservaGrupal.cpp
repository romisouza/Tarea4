#include "../include/datatypes/DTReservaGrupal.h"
#include "../include/datatypes/DTHuesped.h"
#include "../include/datatypes/DTReserva.h"
#include "../include/datatypes/DTFecha.h"
#include "../../include/clases/ReservaGrupal.h"

DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout,EstadoReserva estado, set<Huesped*> huespedes, int TotalHuesp):DTReserva(codigo, checkin, checkout, estado){
huespedes = huespedes;
TotalHuesp = TotalHuesp;
}


set<Huesped*> DTReservaGrupal::getHuespedes(){
    return huespedes;
}

int DTReservaGrupal::getTotalHuesp(){
    return TotalHuesp;
}