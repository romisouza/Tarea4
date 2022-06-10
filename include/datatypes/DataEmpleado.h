#ifndef DATAEMPLEADO
#define DATAEMPLEADO
#include <iostream>
using namespace std;
enum CargoEmpleado {Administracion, Limpieza, Recepcion, Infraestructura};

class DataEmpleado{
    private:
        std::string nombreEmp;
        std::string emailEmp;
        CargoEmpleado cargo;
        std::string hostal;
    public:
        DataEmpleado();
        DataEmpleado(std::string,std::string,CargoEmpleado,std::string);
        std::string getNombre();
        std::string getEmail();
        CargoEmpleado getCargo();
        std::string getHostal();
        ~DataEmpleado();

};

#endif