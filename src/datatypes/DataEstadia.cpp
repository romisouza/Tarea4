#include "../../include/datatypes/DataEstadia.h"

DataEstadia::DataEstadia(){

}

DataEstadia::DataEstadia(DTFecha in,DTFecha out,string host,string huesp,int habit,int prom,int codigo){
    checkin= in;
    checkout = out;
    hostal = host;
    huesped = huesp;
    hab = habit;
    promo = prom;
    cod = codigo;

}

DTFecha DataEstadia::getCheckIn(){
    return checkin;
}

DTFecha DataEstadia::getCheckOut(){
    return checkout;
}

string DataEstadia::getHostal(){
    return hostal;
 }

string DataEstadia::getHuesped(){
    return huesped;
 }

int DataEstadia::getHabitacion(){
    return hab;
 }

int DataEstadia::getPromo(){
    return promo;
 }

int DataEstadia::getCod(){
    return cod;
 }

DataEstadia::~DataEstadia(){

 }