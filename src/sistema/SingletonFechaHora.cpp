#include "../../include/sistema/SingletonFechaHora.h"

SingletonFechaHora *SingletonFechaHora::instancia =NULL;

SingletonFechaHora *SingletonFechaHora::getInstance(){
    if(instancia==NULL)
        instancia = new SingletonFechaHora;
    return instancia;
}