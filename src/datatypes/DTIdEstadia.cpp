#include "../../include/datatypes/DTIdEstadia.h"

DTIdEstadia::DTIdEstadia(int cod, std::string mail){
    codigo=cod;
    email=mail;
}

int DTIdEstadia::getCodigo(){
    return codigo;
}

std::string DTIdEstadia::getEmail(){
    return email;
}


DTIdEstadia::~DTIdEstadia(){
    
}