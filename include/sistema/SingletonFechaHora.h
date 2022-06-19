#ifndef SINGLETONFECHAHORA
#define SINGLETONFECHAHORA

#include "../../include/datatypes/DTFecha.h"

class SingletonFechaHora{
    private:
        static SingletonFechaHora* instancia;
        SingletonFechaHora();
        DTFecha fechaActual;
        ~SingletonFechaHora();
    public:
        static SingletonFechaHora *getInstance();
        DTFecha FechaHoraSistema();
        void actualizarFechaSistema(int,int,int,int,int);
};

#endif