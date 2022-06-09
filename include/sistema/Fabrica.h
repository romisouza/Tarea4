#ifndef FABRICA
#define FABRICA
#include "../../include/sistema/IUsuario.h"
#include "../../include/sistema/IHostal.h"

class Fabrica{
    private:
        static Fabrica * instancia;
        Fabrica();
    public:
        static Fabrica * getInstancia();
        static IUsuario * getIUsuario();
        static IHostal * getIHostal;

};

#endif