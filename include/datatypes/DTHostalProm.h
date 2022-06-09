#ifndef DTHOSTALPROM
#define DTHOSTALPROM
#include <iostream>
using namespace std;

class DTHostalProm{
    private:
        std::string nombre;
        std::string direccion;
        int calificacionesPromedio;
    public:
        DTHostalProm(std::string, std::string, int);
        std::string getNombre();
        std::string getDireccion();
        int getCalificacionesPromedio();
        ~DTHostalProm();
};
#endif