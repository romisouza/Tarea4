#ifndef DATAHOSTALCOMP
#define DATAHOSTALCOMP
#include "../../include/clases/Habitacion.h"
#include "../../include/clases/Reserva.h"
#include "../../include/clases/Calificacion.h"
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Habitacion;
class Reserva;
class DTCalificacion;

class DataHostalComp {
    private:
        std::string nombre;
        std::string direccion;
        int telefono;
        float promedio;
        map<int, Habitacion*> ColHabit;
        map<int,Reserva*>  ColRes;
        set<DTCalificacion> ColCalif;
    public:
        DataHostalComp();
        DataHostalComp(std::string,std::string,int,float);
        ~DataHostalComp();
        std::string getNombre();
        std::string getDireccion();
        int getTelefono();
        float getPromedio();
        set<DTHabitacion> getHabitaciones();
        set<DTReserva> getReservas();
        float getPromedio();
        map<int, Habitacion*> getHabitaciones();
        map<int, Reserva*> getReservas();
        set<DTCalificacion> getComentarios();
        
};

#endif