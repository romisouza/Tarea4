#ifndef DTHOSTAL
#define DTHOSTAL
#include <iostream>
using namespace std;

class DTHostal {
    private:
        std::string nombre;
        std::string direccion;
        int telefono;
    public:
        DTHostal(std::string, std::string, int);
        ~DTHostal();
        std::string getNombre();
        std::string getDireccion();
        int  getTelefono();
};

#endif