#ifndef DTRESERVACOMPGRUP
#define DTRESERVACOMPGRUP
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/clases/Huesped.h"
class Huesped;

class DTReservaCompGrup:DTReservaComp {
private:
    map<std::string,Huesped*> huespedes;
public:
    DTReservaCompGrup(int, DTFecha, DTFecha,EstadoReserva,int, map<std::string,Huesped*>);
    map<std::string,Huesped*> getHuesp();
    ~DTReservaCompGrup();
};

#endif