#include "../../include/datatypes/DataHostalComp.h"

DataHostalComp::DataHostalComp(){

}

DataHostalComp::DataHostalComp(std::string nom,std::string dir,std::string tel,float prom){
    nombre = nom;
    direccion = dir;
    telefono = tel;
    promedio = prom;
    map<int, Habitacion*> ColHabit;
    map<int, Reserva*> ColRes;
    list<DTCalificacion> ColCalif;
}

DataHostalComp::~DataHostalComp(){
    ColHabit.clear();
    ColRes.clear();
    ColCalif.clear();
}

std::string DataHostalComp::getNombre(){
    return nombre;
}

std::string DataHostalComp::getDireccion(){
    return direccion;
}

std::string DataHostalComp::getTelefono(){
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
    this->ColHabit=habs;
}

void DataHostalComp::setReservas(map<int, Reserva*> Res){
    ColRes=Res;
}

void DataHostalComp::setComentarios(list<DTCalificacion> Com){
    ColCalif=Com;
}