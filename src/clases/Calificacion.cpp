#include "../../include/clases/Calificacion.h"

Calificacion::Calificacion(){//Implementar
Puto
}

Calificacion::Calificacion(DTFecha Fecha, int Puntaje,string ComenHuesp,string ComenEmp, Estadia* est){
    fecha=Fecha;
    puntaje=Puntaje;
    comentarioHuesp=ComenHuesp;
    comentarioEmp= ComenEmp;
    estadia=est;
}

DTFecha Calificacion::getFecha(){
    return fecha;
}

int Calificacion::getPuntaje(){
    return puntaje;
}

string Calificacion::getComentarioHuesp(){
    return comentarioHuesp;
}

string Calificacion::getComentarioEmp(){
    return comentarioEmp;
}

Estadia* Calificacion::getEstadia(){
    return estadia;
}

void Calificacion::setFecha(DTFecha FechaNueva){
    fecha=FechaNueva;
}

void Calificacion::setPuntaje(int Punt){
    puntaje=Punt;
}

void Calificacion::setComentarioHuesp(string ComenNuevo){
    comentarioHuesp=ComenNuevo;
}

void Calificacion::setComentarioEmp(string ComenNuevo){
    comentarioEmp=ComenNuevo;
}

void Calificacion::setEstadia(Estadia* est){
    estadia=est;
}

DTCalificacion Calificacion::getDTCalificacion(){
    DTCalificacion Cal=DTCalificacion(getPuntaje(),getComentarioEmp(),getComentarioHuesp());
    return Cal;
}

Calificacion::~Calificacion(){//Implementar

}