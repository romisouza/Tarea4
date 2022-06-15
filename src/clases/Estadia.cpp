#include "../../include/clases/Estadia.h"


Estadia::Estadia(){//(Implementar)

}

Estadia::Estadia(DTFecha CheckIn,DTFecha CheckOut,int Promo,Huesped* Huespp,Reserva* Ress){
    checkIn=CheckIn;
    checkOut=CheckOut;
    promo=Promo;
    huesp=Huespp;
    res=Ress;
    Estadia* est;
}

DTFecha Estadia:: getCheckIn(){
    return checkIn;
}

DTFecha Estadia:: getCheckOut(){
    return checkOut;
}

int Estadia:: getPromo(){
    return promo;
}

Huesped* Estadia:: getHuesp(){
    return huesp;
}

Reserva* Estadia:: getReserva(){
    return res;
}

Calificacion* Estadia:: getCal(){
    return cal;
}

void Estadia::setCheckIn(DTFecha CheckIn){
    checkIn=CheckIn;
}

void Estadia::setCheckOut(DTFecha CheckOut){
    checkOut=CheckOut;
}

void Estadia::setPromo(int Prom){
    promo=Prom;
}

void Estadia::setHuesp(Huesped* Huespedd){
    huesp=Huespedd;
}

void Estadia::setReserva(Reserva* res){
    this->res=res;
}

void Estadia::setCalificacion(Calificacion* cal){
    this->cal=cal;
}

Estadia* Estadia::getEstadia(){
    Estadia* est= new Estadia(checkOut,checkIn, promo, huesp, res);
    return est;
}

DTIdEstadia Estadia::getDTIdEstadia(){
    DTIdEstadia Est= DTIdEstadia(res->getCodigo(),huesp->getEmail());
    return Est;
}

DataEstadia* Estadia::getDataEstadia(){
    DataEstadia *est = new DataEstadia(checkIn,checkOut,res->getHab()->getNombreHostal(),huesp->getEmail(),res->getHab()->getNumero(),promo,res->getCodigo());
    return est;
}

Estadia::~Estadia(){ //(Implementar)

}