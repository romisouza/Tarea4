#include "../../include/datatypes/DataEmpleado.h"

DataEmpleado::DataEmpleado(){

}

DataEmpleado::DataEmpleado(std::string nombre,std::string email,CargoEmpleado* carg,std::string host){
    nombreEmp= nombre;
    emailEmp = email;
    cargo = carg;
    hostal = host;
}

std::string DataEmpleado::getNombre(){
    return nombreEmp;
}

std::string DataEmpleado::getEmail(){
    return emailEmp;
}

CargoEmpleado* DataEmpleado::getCargo(){
    return cargo;
}

std::string DataEmpleado::getHostal(){
    return hostal;
}

DataEmpleado::~DataEmpleado(){
    delete cargo;
}