#include "../../include/datatypes/DTHostal.h"

DTHostal::DTHostal(std::string name, std::string dir, int tel){
    nombre = name;
    direccion = dir;
    telefono = tel;
}

DTHostal::~DTHostal(){}

std::string DTHostal::getNombre(){
    return nombre;
}

std::string DTHostal::getDireccion(){
    return direccion;
}

int DTHostal::getTelefono(){
    return telefono;
}