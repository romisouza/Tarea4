#include "../../include/clases/ReservaGrupal.h"
#include "../../include/datatypes/DTReservaCompGrup.h"


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
   /* DTReservaCompGrup* dtres = new DTReservaCompGrup(getCodigo(),getCheckIn(),getCheckOut(),getEstado(),getHab()->getNumero(),huespedes);
    return dtres;*/
}

set<DTReserva> ReservaGrupal::validarHuespedRegistrado(string email){}

void ReservaGrupal::validarHuesped(string email){}