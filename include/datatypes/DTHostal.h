#ifndef DTHOSTAL
#define DTHOSTAL
#include <iostream>
#include <string>
using namespace std;

class DTHostal {
    private:
        string nombre;
        string direccion;
        int telefono;
    public:
        DTHostal(string, string, int);
        ~DTHostal();
        string getNombre();
        string getDireccion();
        int  getTelefono();
};

#endif