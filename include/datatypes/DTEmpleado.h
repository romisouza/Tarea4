#ifndef DTEMPLEADO
#define DTEMPLEADO
#include <iostream>
using namespace std;
#include "../../include/clases/Empleado.h"

class DTEmpleado {
    private:
        string nombre;
        string email;
        CargoEmpleado cargo;
    public:
        DTEmpleado(string,string,CargoEmpleado);
        ~DTEmpleado();
        string getNombre();
        string getEmail();
        CargoEmpleado getCargo();
};

#endif