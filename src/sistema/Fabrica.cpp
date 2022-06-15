#include "../../include/sistema/Fabrica.h"


Fabrica * Fabrica::instancia=NULL;

Fabrica::Fabrica(){}

Fabrica * Fabrica::getInstancia(){
    if(instancia==NULL)
        instancia = new Fabrica();
    return instancia;
}

Fabrica::~Fabrica(){
    delete instancia;
}

IHostal* Fabrica::obtenerControladorHostal(){
    return ControladorHostal::getInstance();
}

IUsuario* Fabrica::obtenerControladorUsuario(){
    return ControladorUsuario::getInstance();
}