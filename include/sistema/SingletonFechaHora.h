#ifndef SINGLETONFECHAHORA
#define SINGLETONFECHAHORA

#include "../../include/datatypes/DTFecha.h"

class SingletonFechaHora{
    private:
        static SingletonFechaHora* instancia;
        SingletonFechaHora();
    public:
        static SingletonFechaHora *getInstance();
        DTFecha FechaHoraSitema();
        void actualizarFechaSistema(int,int,int,int,int);

};

#endif