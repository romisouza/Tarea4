#ifndef DTRESERVACOMPGRUP
#define DTRESERVACOMPGRUP
#include <iostream>
#include <set>
#include "DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/clases/Huesped.h"
class Huesped;

class DTReservaCompGrup:DTReservaComp {
private:
    set<Huesped*> huespedes;
public:
    //DTReservaCompGrup(int, DTFecha, DTFecha,EstadoReserva,int, set<Huesped*>);
    set<Huesped*> getHuesp();
    ~DTReservaCompGrup();
};

#endif