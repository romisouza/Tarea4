#ifndef DATAHOSTALCOMP
#define DATAHOSTALCOMP
#include "../../include/clases/Habitacion.h"
#include "../../include/clases/Reserva.h"
#include "../../include/clases/Calificacion.h"
#include <iostream>
#include <list>
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
        list<DTCalificacion> ColCalif;
    public:
        DataHostalComp();
        DataHostalComp(std::string,std::string,int,float);
        ~DataHostalComp();
        std::string getNombre();
        std::string getDireccion();
        int getTelefono();
        float getPromedio();
        map<int, Habitacion*> getHabitaciones();
        map<int, Reserva*> getReservas();
        list<DTCalificacion> getComentarios();
        void setHabitaciones(map<int, Habitacion*>);
        void setReservas(map<int, Reserva*>);
        void setComentarios(list<DTCalificacion>);
        
};

#endif