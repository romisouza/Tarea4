#ifndef DTHOSTALPROM
#define DTHOSTALPROM
#include <string>
#include <iostream>
using namespace std;

class DTHostalProm{
    private:
        string nombre;
        string direccion;
        int calificacionesPromedio;
    public:
        DTHostalProm(string, string, int);
        string getNombre();
        string getDireccion();
        int getCalificacionesPromedio();
        ~DTHostalProm();
};
#endif