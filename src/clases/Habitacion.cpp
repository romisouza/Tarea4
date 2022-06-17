#include "../../include/clases/Habitacion.h"


Habitacion::Habitacion(int num, float priceN, int cap,Hostal* h){
    numero=num;
    precioNoche=priceN;
    capacidad=cap;
    map<int,Reserva*> ColReservas;
    host = h;
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

std::string Habitacion:: getNombreHostal(){
    return host->getNombre();
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

bool Habitacion::consultarReservas(DTFecha desde, DTFecha hasta){ //ADE - REVISAR Q FUNCIONE BIBEN.
    bool estaLibre = true; 
	auto it=ColReservas.begin();
      while (it!=ColReservas.end() && estaLibre) {
          bool x = hasta.compararFecha(hasta,it->second->getCheckIn()); //no se si es hasta. (ade)
          bool y = desde.compararFecha(desde,it->second->getCheckOut()); //no se si es desde. (ade)
          if (x == true || y == true) 
            estaLibre = false;
          it++;
      }
return estaLibre;
}

void Habitacion::asociarResAHab(Reserva* res){
    ColReservas.insert({res->getCodigo(),res});
}

void Habitacion::eliminarResHab(int codRes){
    ColReservas.erase(codRes);
}