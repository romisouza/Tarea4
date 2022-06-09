
#include "../../include/datatypes/DTHostalProm.h"

DTHostalProm::DTHostalProm(string Nomb,string Dir, int Prom){
    nombre=Nomb;
    direccion=Dir;
    calificacionesPromedio=Prom;    
}

string DTHostalProm::getNombre(){
    return nombre;
}
        
string DTHostalProm::getDireccion(){
    return direccion;
}

int DTHostalProm::getCalificacionesPromedio(){
    return calificacionesPromedio;
}


DTHostalProm::~DTHostalProm(){

}