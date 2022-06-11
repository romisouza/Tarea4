#include "../../include/datatypes/DTFecha.h"

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

std::string DTFecha::convertirFechaToString(int anio, int mes, int dia,int hora,int min){
    std::string anioConvertido = std::to_string(anio);
    std::string mesConvertido = std::to_string(mes);
    std::string diaConvertido = std::to_string(dia);
    std::string horaConvertido = std::to_string(hora);
    std::string minConvertido = std::to_string(min);
    std::string res = anioConvertido+'-'+mesConvertido+'-'+diaConvertido+' '+horaConvertido+'-'+minConvertido;
    return res;
}

bool DTFecha::compararFecha(DTFecha a,DTFecha b){ // ASUMO Q SE USAN LAS 24HRS DEL DIA
    std::string dateA = convertirFechaToString(a.anio,a.mes,a.dia,a.hora,a.minutos);
    std::string dateB = convertirFechaToString(b.anio,b.mes,b.dia,b.hora,b.minutos);
    if (dateA <= dateB)
        return true;
    else
        return false;
}

DTFecha::~DTFecha(){

}