#include "../../include/clases/ReservaGrupal.h"


ReservaGrupal::ReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout,DTFecha realiza,int totalHuespedes):Reserva(codigo, checkin, checkout, realiza){
    set<Huesped*> huespedes;
    TotalHuesp = totalHuespedes;
};

set<Huesped*> ReservaGrupal::getHuespedes(){
    return huespedes;
}

void ReservaGrupal::setHuespedes(set<Huesped*> nuevosHuesp){
    huespedes = nuevosHuesp;
}
int ReservaGrupal::getTotalHuesp(){
    return TotalHuesp;
}

/*ReservaGrupal::~ReservaGrupal() {
}*/

DTReservaComp* ReservaGrupal::getDTReservaComp(){

}

set<DTReserva> ReservaGrupal::validarHuespedRegistrado(string email){}

void ReservaGrupal::validarHuesped(string email){}