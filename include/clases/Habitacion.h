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

class Habitacion{
private:
    int numero; 
    float precioNoche;
    int capacidad;
    Reserva* res;
    Hostal* host;
public:
    Habitacion(int, float, int);
    int getCapacidad();
    int getNumero();
    float getPrecioNoche();
    void setCapacidad(int);
    void setNumero(int);
    void setPrecioNoche(float);
    DTHabitacion getHabitacion();
    void consultarReservas(DTFecha, DTFecha);
    void reservar(int, DTFecha, DTFecha, Huesped);
    ~Habitacion();
};

#endif
