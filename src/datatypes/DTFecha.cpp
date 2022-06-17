#include "../../include/datatypes/DTFecha.h"
#include <iostream>
using namespace std;

DTFecha::DTFecha(){}

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

bool DTFecha::compararFecha(DTFecha a,DTFecha b){ // ASUMO Q SE USAN LAS 24HRS DEL DIA
        if (a.anio == b.anio){
            if (a.mes == b.mes){
                if (a.dia == b.dia){
                    if (a.hora == a.hora){
                        if (a.minutos <= b.minutos)
                            return true;
                        else
                            return false;
                    } else if (a.hora < b.hora)
                        return true;
                    else
                        return false;
                } else if (a.dia < b.dia)
                    return true;
                else
                    return false;
            } else if (a.mes < b.mes)
                return true;
            else
                return false;
        } else if (a.anio < b.anio)
            return true;
            else
            return false;
}

DTFecha::~DTFecha(){

}