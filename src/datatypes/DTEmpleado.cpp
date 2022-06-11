#include "../../include/datatypes/DTEmpleado.h"

DTEmpleado::DTEmpleado(std::string nom,std::string mail,CargoEmpleado* car){
    nombre = nom;
    email = mail;
    cargo = car;
}

DTEmpleado::~DTEmpleado(){
    
}

std::string DTEmpleado::getNombre(){
    return nombre;
}
std::string DTEmpleado::getEmail(){
    return email;
}

CargoEmpleado* DTEmpleado::getCargo(){
    return cargo;
}