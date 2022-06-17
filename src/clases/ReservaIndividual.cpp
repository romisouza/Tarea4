#include "../../include/clases/ReservaIndividual.h"
#include "../../include/datatypes/DTReservaCompInd.h"

ReservaIndividual::ReservaIndividual(int codigo, DTFecha checkin, DTFecha checkout,DTFecha realiza):Reserva(codigo,checkin,checkout,realiza){
}

/*DTReservaComp ReservaIndividual::getDTReservaComp(){
    DTReservaComp(getCodigo(),getCheckIn(),getCheckOut(),getEstado(),getHab()->getNumero(),NULL);
}*/


DTReserva* ReservaIndividual::getDTReserva(){
    DTReserva* Res = new DTReservaIndividual(getCodigo(),getCheckIn(),getCheckOut(),getEstado());
    return Res;
}

DTReserva* ReservaIndividual::validarHuespedRegistrado(string email){
    DTReserva* resultado; //en realidad tengo que mandar DTReserva* y que el ultimo sea el set
    Huesped* huesp = getHues();
    if (email == huesp->getEmail()){
        EstadoReserva est = getEstado();
            if (est != Cancelada){
                DTReserva* resp = getDTReserva(); //ver
                resultado = resp; //se agrega al retorno que va para colReservasNC
            } 
    }
    return resultado;
}

void ReservaIndividual::validarHuesped(string email, DTFecha hs){
    if (getHues()->getEmail() == email){
        list<Estadia*> est = getEstadia();
        DTFecha checkoutEst = est.front()->getCheckOut();
        DTFecha comparar;
        bool Ter = comparar.compararFecha(checkoutEst, hs);
        if (!Ter){
            est.front()->setCheckOut(hs);
        }
    }
}

DTReservaComp* ReservaIndividual::getDTReservaComp(){
    DTReservaCompInd *res = new DTReservaCompInd(getCodigo(),getCheckIn(),getCheckOut(),getHues(),getEstado(),getHab()->getNumero());
    return res;
}

ReservaIndividual::~ReservaIndividual() {
}

/*
set<DTReserva> validarHuespedRegistrado(string email){}

void validarHuesped(string email){}*/
