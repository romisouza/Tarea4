#include "../../include/datatypes/DTHostal.h"

DTHostal::DTHostal(string name, string dir, int tel){
    nombre = name;
    direccion = dir;
    telefono = tel;
}

DTHostal::~DTHostal(){}

string DTHostal::getNombre(){
    return nombre;
}

string DTHostal::getDireccion(){
    return direccion;
}

int DTHostal::getTelefono(){
    return telefono;
}