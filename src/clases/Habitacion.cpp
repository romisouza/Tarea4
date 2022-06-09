#include "../../include/clases/Habitacion.h"


Habitacion::Habitacion(int num, float priceN, int cap){
    numero=num;
    precioNoche=priceN;
    capacidad=cap;
}

int Habitacion::getCapacidad(){
    return capacidad;
}

int Habitacion::getNumero(){
    return numero;
}

float Habitacion::getPrecioNoche(){
    return precioNoche;
}

void Habitacion::setNumero(int num){
    numero=num;
}

void Habitacion::setCapacidad(int cap){
    capacidad=cap;
}

void Habitacion::setPrecioNoche(float price){
    precioNoche=price;
}

Habitacion::~Habitacion() {

}

DTHabitacion Habitacion::getHabitacion(){
    DTHabitacion Hab;
    Hab=DTHabitacion(getNumero(), getPrecioNoche(), getCapacidad());
    return Hab;
}

void Habitacion::consultarReservas(DTFecha desde, DTFecha hasta){

}

void Habitacion::reservar(int a, DTFecha desde, DTFecha hasta, Huesped x){

}