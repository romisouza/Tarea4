#include "../../include/clases/Calificacion.h"

Calificacion::Calificacion(){//Implementar

}

Calificacion::Calificacion(DTFecha Fecha, int Puntaje,std::string ComenHuesp, Estadia* estt){
    fecha=Fecha;
    puntaje=Puntaje;
    comentarioHuesp=ComenHuesp;
    est=estt;
    comentarioEmp ="";
}

DTFecha Calificacion::getFecha(){
    return fecha;
}

int Calificacion::getPuntaje(){
    return puntaje;
}

std::string Calificacion::getComentarioHuesp(){
    return comentarioHuesp;
}

std::string Calificacion::getComentarioEmp(){
    return comentarioEmp;
}

Estadia* Calificacion::getEstadia(){
    return est;
}

void Calificacion::setFecha(DTFecha FechaNueva){
    fecha=FechaNueva;
}

void Calificacion::setPuntaje(int Punt){
    puntaje=Punt;
}

void Calificacion::setComentarioHuesp(std::string ComenNuevo){
    comentarioHuesp=ComenNuevo;
}

void Calificacion::setComentarioEmp(std::string ComenNuevo){
    comentarioEmp=ComenNuevo;
}

void Calificacion::setEstadia(Estadia* estt){
    est=estt;
}

DTCalificacion Calificacion::getDTCalificacion(){
    DTCalificacion Cal=DTCalificacion(getPuntaje(),getComentarioHuesp(),getComentarioEmp());
    return Cal;
}

Calificacion::~Calificacion(){//Implementar

}
