#include "../../include/sistema/SingletonFechaHora.h"

SingletonFechaHora *SingletonFechaHora::instancia =NULL;

SingletonFechaHora *SingletonFechaHora::getInstancia(){
    if(instancia==NULL)
        instancia = new SingletonFechaHora;
    return instancia
}