#ifndef DTRESERVACOMPGRUP
#define DTRESERVACOMPGRUP
#include <iostream>
#include <set>
#include "DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/clases/Huesped.h"
class Huesped;
using namespace std;

class DTReservaCompGrup:public DTReservaComp {
private:
    set<Huesped*> huespedes;
public:
    DTReservaCompGrup(int, DTFecha, DTFecha,EstadoReserva,int, set<Huesped*>);
    set<Huesped*> getHuesp();
    ~DTReservaCompGrup();
};

#endif