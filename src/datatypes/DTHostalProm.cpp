
#include "../../include/datatypes/DTHostalProm.h"

DTHostalProm::DTHostalProm(std::string Nomb,std::string Dir, int Prom){
    nombre=Nomb;
    direccion=Dir;
    calificacionesPromedio=Prom;    
}

std::string DTHostalProm::getNombre(){
    return nombre;
}
        
std::string DTHostalProm::getDireccion(){
    return direccion;
}

int DTHostalProm::getCalificacionesPromedio(){
    return calificacionesPromedio;
}


DTHostalProm::~DTHostalProm(){

}