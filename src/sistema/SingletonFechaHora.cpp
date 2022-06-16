#include "../../include/sistema/SingletonFechaHora.h"

SingletonFechaHora *SingletonFechaHora::instancia =NULL;

SingletonFechaHora *SingletonFechaHora::getInstance(){
    if(instancia==NULL)
        instancia = new SingletonFechaHora;
    return instancia;
}

SingletonFechaHora::SingletonFechaHora(){
    
}

DTFecha SingletonFechaHora::FechaHoraSistema(){
    return fechaActual;
}

void SingletonFechaHora::actualizarFechaSistema(int anio,int mes,int dia ,int hora,int minutos){
DTFecha nueva = DTFecha(dia ,mes ,anio ,hora ,minutos);
fechaActual = nueva;
}