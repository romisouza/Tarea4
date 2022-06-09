#include "../../include/datatypes/DTEmpleado.h"

DTEmpleado::DTEmpleado(string nom,string mail,CargoEmpleado car){
    nombre = nom;
    email = mail;
    cargo = car;
}

DTEmpleado::~DTEmpleado(){
    
}

string DTEmpleado::getNombre(){
    return nombre;
}
string DTEmpleado::getEmail(){
    return email;
}

CargoEmpleado DTEmpleado::getCargo(){
    return cargo;
}