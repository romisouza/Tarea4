#include "../../include/sistema/SingletonFechaHora.h"

SingletonFechaHora *SingletonFechaHora::instancia =NULL;

SingletonFechaHora *SingletonFechaHora::getInstance(){
    if(instancia==NULL)
        instancia = new SingletonFechaHora;
    return instancia;
}

SingletonFechaHora::SingletonFechaHora(){}

DTFecha SingletonFechaHora::FechaHoraSistema(){
    DTFecha res = DTFecha(12,3,2009,22,53);
    return res;
}