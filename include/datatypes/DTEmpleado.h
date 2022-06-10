#ifndef DTEMPLEADO
#define DTEMPLEADO
#include <iostream>
using namespace std;
#include "../../include/datatypes/DataEmpleado.h"

class DTEmpleado {
    private:
        std::string nombre;
        std::string email;
        CargoEmpleado cargo;
    public:
        DTEmpleado(std::string,std::string,CargoEmpleado);
        ~DTEmpleado();
        std::string getNombre();
        std::string getEmail();
        CargoEmpleado getCargo();
};

#endif