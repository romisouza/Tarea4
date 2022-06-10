#ifndef DTRESERVACOMP
#define DTRESERVACOMP
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "../../include/clases/Huesped.h"
#include "../../include/clases/Reserva.h"

class DTReservaComp {
private:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    int numHab;
    map<std::string,Huesped*> huespedes;
public:
    DTReservaComp(int, DTFecha, DTFecha, EstadoReserva, int, map<std::string,Huesped*>);
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    EstadoReserva getEstado();
    int getNumHab();
    map<std::string,Huesped*> getHuesp();
    ~DTReservaComp();
};

#endif