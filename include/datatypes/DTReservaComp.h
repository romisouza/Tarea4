#ifndef DTRESERVACOMP
#define DTRESERVACOMP
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/clases/Huesped.h"
class Huesped;

class DTReservaComp {
private:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    int numHab;
    EstadoReserva estado;
public:
    DTReservaComp(int, DTFecha, DTFecha,EstadoReserva,int);
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    int getNumHab();
    ~DTReservaComp();
};

#endif