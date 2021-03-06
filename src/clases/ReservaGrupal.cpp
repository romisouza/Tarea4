#include "../../include/clases/ReservaGrupal.h"
#include "../../include/datatypes/DTReservaGrupal.h"
#include "../../include/datatypes/DTReservaCompGrup.h"
#include "../../include/datatypes/DTReservaComp.h"


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


DTReservaComp* ReservaGrupal::getDTReservaComp(){
    //DTReservaComp *res;
    DTReservaCompGrup *res = new DTReservaCompGrup(getCodigo(),getCheckIn(),getCheckOut(),getHues(),getEstado(),getHab()->getNumero(),huespedes);
    return res;
}

DTReserva* ReservaGrupal::getDTReserva(){
    DTReservaGrupal* Res= new DTReservaGrupal(getCodigo(),getCheckIn(),getCheckOut(),getEstado(), getHuespedes(), getTotalHuesp());
    return Res;
}

bool ReservaGrupal::validarHuespedRegistrado(std::string email){
    bool resultado;
    set<Huesped*> mover = getHuespedes();
    //cout << getHuespedes().size();
    for(auto i= mover.begin(); i != mover.end(); i++){
        //Huesped* mailhuesp = (*i);
        //std::string el = mailhuesp->getEmail();
        if(email == (*i)->getEmail()){
            EstadoReserva est = getEstado();
            if (est != Cancelada){
                resultado = true;
            }
        }
    
    }
return resultado;
}

bool ReservaGrupal::validarHuesped(string email, DTFecha hs){
    bool res = false;
    for(set<Huesped*>::iterator i= huespedes.begin(); i != huespedes.end(); i++){
        if(email == (*i)->getEmail()){
            list<Estadia*> est = getEstadia();
            Estadia* estEncontrada;
            bool hay = false;
            for (list<Estadia*>::iterator i = est.begin(); i != est.end();i++){
                Huesped* huesp = (*i)->getHuesp();
                    if (huesp->getEmail() == email){
                        estEncontrada = (*i);
                        hay = true;
                    }
            }
            if(hay){
                DTFecha checkoutEst = estEncontrada->getCheckOut();
                DTFecha comparar;
                bool Ter = hs.compararFecha(checkoutEst, hs);//true  si a<= b
                    if (!Ter){
                        estEncontrada->setCheckOut(hs);
                        res = true;
                    }
            }
        }
    }
    return res;
}

ReservaGrupal::~ReservaGrupal(){
    huespedes.clear();
}
