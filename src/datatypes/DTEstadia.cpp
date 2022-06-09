#include "../../include/datatypes/DTEstadia.h"

DTEstadia::DTEstadia(DTFecha ent ,DTFecha sal ,int prom){
    checkIn = ent;
    checkOut = sal;
    promo = prom;
}

DTEstadia::~DTEstadia(){}

DTFecha DTEstadia::getCheckIn(){
    return checkIn;
}

DTFecha DTEstadia::getCheckOut(){
    return checkOut;
}

int DTEstadia::getPromo(){
    return promo;
}