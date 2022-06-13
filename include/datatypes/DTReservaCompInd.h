#ifndef DTRESERVACOMPIND
#define DTRESERVACOMPIND
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/clases/Huesped.h"
class Huesped;

class DTReservaCompInd:DTReservaComp {
private:
public:
    DTReservaCompInd(int, DTFecha, DTFecha,EstadoReserva,int);
    ~DTReservaCompInd();
};

#endif