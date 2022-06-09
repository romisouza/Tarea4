#include "../../include/datatypes/DTCalificacion.h"

DTCalificacion :: DTCalificacion(int punt,string comentarioH,string comentarioE){
	puntaje = punt;
	comentarioHuesp = comentarioH;
	comentarioEmp = comentarioE;
}

int DTCalificacion::getPuntaje() {
	return puntaje;
}

string DTCalificacion::getComentarioHuesp(){
	return comentarioHuesp;
}

string DTCalificacion::getComentarioEmp() {
	return comentarioEmp;
}

DTCalificacion::~DTCalificacion(){}