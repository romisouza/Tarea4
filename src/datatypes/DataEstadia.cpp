#include "../../include/datatypes/DataEstadia.h"

DataEstadia::DataEstadia(){

}

DataEstadia::DataEstadia(DTFecha in,DTFecha out,std::string host,std::string huesp,int habit,int codigo){
    checkin= in;
    checkout = out;
    hostal = host;
    huesped = huesp;
    hab = habit;
    cod = codigo;

}

DTFecha DataEstadia::getCheckIn(){
    return checkin;
}

DTFecha DataEstadia::getCheckOut(){
    return checkout;
}

std::string DataEstadia::getHostal(){
    return hostal;
 }

std::string DataEstadia::getHuesped(){
    return huesped;
 }

int DataEstadia::getHabitacion(){
    return hab;
 }


int DataEstadia::getCod(){
    return cod;
 }

DataEstadia::~DataEstadia(){

 }