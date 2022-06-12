#include "../../include/datatypes/DataHostalComp.h"

DataHostalComp::DataHostalComp(){

}

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

float DataHostalComp::getPromedio(){
    return promedio;
}

map<int, Habitacion*> DataHostalComp::getHabitaciones(){
    return ColHabit;
}

map<int, Reserva*> DataHostalComp::getReservas(){
    return ColRes;
}

list<DTCalificacion> DataHostalComp::getComentarios(){
    return ColCalif;
}

void DataHostalComp::setHabitaciones(map<int, Habitacion*> habs) {
    ColHabit=habs;
}

void DataHostalComp::setReservas(map<int, Reserva*> Res){
    ColRes=Res;
}

void DataHostalComp::setComentarios(list<DTCalificacion> Com){
    ColCalif=Com;
}