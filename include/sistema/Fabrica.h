#ifndef FABRICA
#define FABRICA
#include "IUsuario.h"
#include "IHostal.h"
#include "ControladorHostal.h"
#include "ControladorUsuario.h"

class Fabrica{
    private:
        static Fabrica * instancia;
        Fabrica();
    public:
        ~Fabrica();
        static Fabrica* getInstancia();
        IUsuario* obtenerControladorUsuario();
        IHostal * obtenerControladorHostal();

};

#endif