#include "../../include/datatypes/DTEstadia.h"

DTEstadia::DTEstadia(DTFecha ent ,DTFecha sal){
    checkIn = ent;
    checkOut = sal;
}

DTEstadia::~DTEstadia(){}

DTFecha DTEstadia::getCheckIn(){
    return checkIn;
}

DTFecha DTEstadia::getCheckOut(){
    return checkOut;
}
