#ifndef DTRESERVACOMP
#define DTRESERVACOMP
#include <string>
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "../../include/clases/Huesped.h"
#include "../../include/clases/Reserva.h"

class DTReservaComp
{
private:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    int numHab;
    map<string,Huesped*> huespedes;
public:
    DTReservaComp(int, DTFecha, DTFecha, EstadoReserva, int, map<string,Huesped*>);
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    int getNumHab();
    map<string,Huesped*> getHuesp();
    ~DTReservaComp();
};

#endif