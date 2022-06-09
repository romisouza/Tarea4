#include "../../include/clases/ReservaGrupal.h"


ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout, EstadoReserva estado, Habitacion* hab,Huesped* huesp, Huesped **huespedes,int totalHuespedes):Reserva(codigo, checkin, checkout, hab, huesp){
    this->huespedes = huespedes;
    TotalHuesp = totalHuespedes;
};

set<Huesped> ReservaGrupal::getHuespedes(){
    return huespedes;
}

int ReservaGrupal::getTotalHuesp(){
    return TotalHuesp;
}

