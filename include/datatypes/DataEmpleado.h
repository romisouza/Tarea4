#ifndef DATAEMPLEADO
#define DATAEMPLEADO
#include <iostream>
#include <string>
#include "../../include/clases/Empleado.h"
using namespace std;

class DataEmpleado{
    private:
        string nombreEmp;
        string emailEmp;
        CargoEmpleado cargo;
        string hostal;
    public:
        DataEmpleado();
        DataEmpleado(string,string,CargoEmpleado,string);
        string getNombre();
        string getEmail();
        CargoEmpleado getCargo();
        string getHostal();
        ~DataEmpleado();

};

#endif