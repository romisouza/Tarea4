#ifndef HABITACION
#define HABITACION
#include <iostream>
#include <string>
#include "../../include/datatypes/DTHabitacion.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/clases/Reserva.h"
#include "../../include/clases/Hostal.h"
using namespace std;

class Hostal;
class Reserva;
class Huesped;

class Habitacion{
private:
    int numero; 
    float precioNoche;
    int capacidad;
    map<int,Reserva*> ColReservas;
    Hostal* host;
public:
    Habitacion(int, float, int);
    int getCapacidad();
    int getNumero();
    float getPrecioNoche();
    std::string getNombreHostal();
    void setCapacidad(int);
    void setNumero(int);
    void setPrecioNoche(float);
    DTHabitacion getHabitacion();
    bool consultarReservas(DTFecha, DTFecha);
    void asociarResAHab(Reserva*);
    ~Habitacion();
};

#endif
