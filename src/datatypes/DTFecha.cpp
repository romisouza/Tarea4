#include "../../include/datatypes/DTFecha.h"

DTFecha::DTFecha(int d, int m, int a, int h, int min){
    dia = d;
    mes = m;
    anio = a;
    hora = h;
    minutos = min;
}

int DTFecha::getDia(){
    return dia;
}

int DTFecha::getMes(){
    return mes;
}

int DTFecha::getAnio(){
    return anio;
}

int DTFecha::getHora(){
    return hora;
}

int DTFecha::getMinutos(){
    return minutos;
}

DTFecha::~DTFecha(){

}