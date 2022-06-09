#include "../../include/datatypes/DataEmpleado.h"

DataEmpleado::DataEmpleado(){

}

DataEmpleado::DataEmpleado(string nombre,string email,CargoEmpleado carg,string host){
    nombreEmp= nombre;
    emailEmp = email;
    cargo = carg;
    hostal = host;
}

string DataEmpleado::getNombre(){
    return nombreEmp;
}

string DataEmpleado::getEmail(){
    return emailEmp;
}

CargoEmpleado DataEmpleado::getCargo(){
    return cargo;
}

string DataEmpleado::getHostal(){
    return hostal;
}

DataEmpleado::~DataEmpleado(){
    
}