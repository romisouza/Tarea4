#ifndef DATAHOSTALCOMP
#define DATAHOSTALCOMP
#include "../../include/clases/Habitacion.h"
#include "../../include/clases/Reserva.h"
#include "../../include/clases/Calificacion.h"
#include <iostream>
#include <set>
#include <map>
using namespace std;

class DataHostalComp {
    private:
        string nombre;
        string direccion;
        int telefono;
        float promedio;
        map<int, Habitacion*> ColHabit;
        map<int,Reserva*>  ColRes;
        set<Calificacion> ColCalif;
    public:
        DataHostalComp(string,string,int);
        ~DataHostalComp();
        string getNombre();
        string getDireccion();
        int getTelefono();
        Set(DTHabitacion) getHabitaciones();
        Set(DTReserva) getReservas();
        float getPromedio();
        Set(DTCalificacion) getComentarios();
        agregarReserva(int, Reserva*);
        agregarHabitacion(int,Habitacion*);
        
}:

#endif