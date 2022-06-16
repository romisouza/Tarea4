#ifndef DTRESERVACOMPIND
#define DTRESERVACOMPIND
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "../../include/datatypes/DTReservaComp.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/clases/Huesped.h"
class Huesped;
using namespace std;

class DTReservaCompInd:public DTReservaComp {
private:
public:
    DTReservaCompInd(int, DTFecha, DTFecha,EstadoReserva,int);
    virtual ~DTReservaCompInd();
};

#endif