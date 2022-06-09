#include "../../include/datatypes/DataHostalComp.h"

DataHostalComp::DataHostalComp(string nom,string dir,int tel,float prom){
    nombre = nom;
    direccion = dir;
    telefono = tel;
    promedio = prom;
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

float DataHostalComp::getPromedio(){
        return promedio;
}

map<int, Habitacion*> DataHostalComp::getHabitaciones(){
    return ColHabit;
}

map<int,Reserva*> DataHostalComp::getReservas(){
    return ColRes;
}

float DataHostalComp::getPromedio(){
    return promedio;
}

Set<DTCalificacion> DataHostalComp::getComentarios(){
    return ColCalif;
}

void Hostal::agregarReserva(int cod, Reserva* Res){
	ColReservas[cod]=Res;
}

void Hostal::agregarHabitacion(int num, Habitacion* Hab){
	ColHabitaciones[num]=Hab;
}
