#include "../../include/datatypes/DTCalificacion.h"

DTCalificacion::DTCalificacion(){}

DTCalificacion :: DTCalificacion(int punt,std::string comentarioH,std::string comentarioE){
	puntaje = punt;
	comentarioHuesp = comentarioH;
	comentarioEmp = comentarioE;
}

int DTCalificacion::getPuntaje() {
	return puntaje;
}

std::string DTCalificacion::getComentarioHuesp(){
	return comentarioHuesp;
}

std::string DTCalificacion::getComentarioEmp() {
	return comentarioEmp;
}

DTCalificacion::~DTCalificacion(){}