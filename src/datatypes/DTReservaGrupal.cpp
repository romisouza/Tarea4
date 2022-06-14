#include "../../include/datatypes/DTReservaGrupal.h"

DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout,EstadoReserva estado, set<Huesped*> huespedes, int TotalHuesp):DTReserva(codigo, checkin, checkout, estado){
    this->huespedes = huespedes;
    this->TotalHuesp = TotalHuesp;
}


set<Huesped*> DTReservaGrupal::getHuespedes(){
    return huespedes;
}

int DTReservaGrupal::getTotalHuesp(){
    return TotalHuesp;
}

DTReservaGrupal::~DTReservaGrupal(){

}