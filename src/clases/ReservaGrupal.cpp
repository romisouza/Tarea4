#include "../../include/clases/ReservaGrupal.h"
#include "../include/datatypes/DTReservaGrupal.h"



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
DTReserva* ReservaGrupal::getDTReserva(){
    DTReserva* Res= new DTReservaGrupal(getCodigo(),getCheckIn(),getCheckOut(),getEstado(), getHuespedes(), getTotalHuesp());
    return Res;
}

set<DTReserva*> ReservaGrupal::validarHuespedRegistrado(std::string email){
    set<DTReserva*> resultado;
    bool encontre = false;
    for(set<Huesped*>::iterator i= huespedes.begin(); i != huespedes.end(); i++){
		DTHuesped huesped = (*i)->getDTHuesped();
        if(email == huesped.getMail()){
            encontre = true;
        }
        if (encontre){
            EstadoReserva est = getEstado();
            if (est != Cancelada){
            DTReserva* resp = getDTReserva();
            resultado.insert(resp); //se agrega al retorno que va para colReservasNC
            } 
        }
	}
    return resultado;
}

void ReservaGrupal::validarHuesped(string email){}