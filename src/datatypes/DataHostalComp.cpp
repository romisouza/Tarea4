#include "../../include/datatypes/DataHostalComp.h"

DataHostalComp::DataHostalComp(string nom,string dir,int tel,float prom, Habitacion** hab,Reserva** res,Calificacion** cal){
    nombre = nom;
    direccion = dir;
    telefono = tel;
    promedio = prom;
    ColHabit = hab;
    ColRes = res;
    ColCalif = cal;
}

DataHostalComp::~DataHostalComp(){

}

string DataHostalComp::getNombre(){
    return nombre;
}

string DataHostalComp::getDireccion(){
    return direccion;
}

int DataHostalComp::getTelefono(){
    return telefono;
}

Set(DTHabitacion) DataHostalComp::getHabitaciones(){
    return ColHabit;
}

Set(DTReserva) DataHostalComp::getReservas(){
    return ColRes;
}

float DataHostalComp::getPromedio(){
    return promedio;
}

Set(DTCalificacion) DataHostalComp::getComentarios(){
    return ColCalif;
}

void Hostal::agregarReserva(int cod, Reserva* Res){
	ColReservas[cod]=Res;
}

void Hostal::agregarHabitacion(int num, Habitacion* Hab){
	ColHabitaciones[num]=Hab;
}