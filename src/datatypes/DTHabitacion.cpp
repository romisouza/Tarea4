#include "../../include/datatypes/DTHabitacion.h"

DTHabitacion::DTHabitacion(int num, float precio, int cap) {
	numero = num;
	precioNoche = precio;
	capacidad = cap;
}	

int DTHabitacion::getNumero(){
	return numero;
}

float DTHabitacion::getPrecioNoche(){
	return precioNoche;
}

int DTHabitacion::getCapacidad(){
	return capacidad;
}

DTHabitacion::~DTHabitacion(){}
