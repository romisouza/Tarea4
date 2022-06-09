#include "../../include/datatypes/DTIdEstadia.h"

DTIdEstadia::DTIdEstadia(int cod, string mail){
    codigo=cod;
    email=mail;
}

int DTIdEstadia::getCodigo(){
    return codigo;
}

string DTIdEstadia::getEmail(){
    return email;
}


DTIdEstadia::~DTIdEstadia(){
    
}