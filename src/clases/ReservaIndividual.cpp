#include "../../include/clases/ReservaIndividual.h"
#include "../../include/datatypes/DTReservaIndividual.h"

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkin, DTFecha checkout,DTFecha realiza):Reserva(codigo,checkin,checkout,realiza){
}

/*DTReservaComp ReservaIndividual::getDTReservaComp(){
    DTReservaComp(getCodigo(),getCheckIn(),getCheckOut(),getEstado(),getHab()->getNumero(),NULL);
}*/


DTReserva* ReservaIndividual::getDTReserva(){
    DTReserva* Res = new DTReservaIndividual(getCodigo(),getCheckIn(),getCheckOut(),getEstado());
    return Res;
}

set<DTReserva*> ReservaIndividual::validarHuespedRegistrado(string email){
    set<DTReserva*> resultado; //en realidad tengo que mandar DTReserva* y que el ultimo sea el set
    Huesped* huesp = getHues();
    if (email == huesp->getEmail()){
        EstadoReserva est = getEstado();
            if (est != Cancelada){
                DTReserva* resp = getDTReserva();
            resultado.insert(resp); //se agrega al retorno que va para colReservasNC
            }
    }
    return resultado;
}

void ReservaIndividual::validarHuesped(string){

}

DTReservaComp* ReservaIndividual::getDTReservaComp(){

}

/*ReservaIndividual::~ReservaIndividual() {
}*/

/*
set<DTReserva> validarHuespedRegistrado(string email){}

void validarHuesped(string email){}*/
