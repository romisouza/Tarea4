#include "../../include/datatypes/DataHostalComp.h"

DataHostalComp::DataHostalComp(std::string nom,std::string dir,int tel,float prom){
    nombre = nom;
    direccion = dir;
    telefono = tel;
    promedio = prom;
}

DataHostalComp::~DataHostalComp(){

}

std::string DataHostalComp::getNombre(){
    return nombre;
}

std::string DataHostalComp::getDireccion(){
    return direccion;
}

int DataHostalComp::getTelefono(){
    return telefono;
}

map<int, Habitacion*> DataHostalComp::getHabitaciones(){
    return ColHabit;
}

map<int, Reserva*> DataHostalComp::getReservas(){
    return ColRes;
}

float DataHostalComp::getPromedio(){
    return promedio;
}

set<DTCalificacion> DataHostalComp::getComentarios(){
    return ColCalif;
}

