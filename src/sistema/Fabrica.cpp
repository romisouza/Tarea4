#include Fabrica.h

Fabrica * Fabrica::instancia=NULL;

Fabrica * Fabrica::getInstancia(){
    if(instancia==NULL)
        instancia = new Fabrica;
    return instancia;
}

IUsuario Fabrica::getIUsuario(){
    if(this->usuario==NULL)
        this->usuario = new ControladorUsuario();
    return this->usuario;
}

IHostal Fabrica::getIHostal(){
    if(this->hostal==NULL)
        this->hostal = new ControladorHostal();
    return this->hostal;
}