#include "../include/datatypes/DTReservaGrupal.h"
#include "../include/datatypes/DTHuesped.h"
#include "../include/datatypes/DTReserva.h"

 set<Huesped*> DTReservaGrupal::getHuespedes(){
    return huespedes;
}

int DTReservaGrupal::getTotalHuesp(){
    return TotalHuesp;
}