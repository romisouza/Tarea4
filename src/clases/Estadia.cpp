#include "../../include/clases/Estadia.h"


Estadia::Estadia(){//(Implementar)

}

Estadia::Estadia(DTFecha CheckIn,DTFecha CheckOut,Huesped* Huespp,Reserva* Ress){
    checkIn=CheckIn;
    checkOut=CheckOut;
    huesp=Huespp;
    res=Ress;
    Calificacion* cal;
}

DTFecha Estadia:: getCheckIn(){
    return checkIn;
}

DTFecha Estadia:: getCheckOut(){
    return checkOut;
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


void Estadia::setHuesp(Huesped* Huespedd){
    huesp=Huespedd;
}

void Estadia::setReserva(Reserva* res){
    this->res=res;
}

void Estadia::setCalificacion(Calificacion* calif){
    this->cal=calif;
}

Estadia* Estadia::getEstadia(){
    Estadia* est= new Estadia(checkOut,checkIn, huesp, res);
    return est;
}

DTIdEstadia Estadia::getDTIdEstadia(){
    DTIdEstadia Est= DTIdEstadia(res->getCodigo(),huesp->getEmail());
    return Est;
}

DataEstadia* Estadia::getDataEstadia(){
    DataEstadia *est = new DataEstadia(checkIn,checkOut,res->getHab()->getNombreHostal(),huesp->getEmail(),res->getHab()->getNumero(),res->getCodigo());
    return est;
}

    

Estadia::~Estadia(){ 
    delete huesp;
    delete res;
    delete cal;
}