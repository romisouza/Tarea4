#ifndef DTRESERVACOMP
#define DTRESERVACOMP
#include <iostream>
#include <map>
#include "DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
//#include "../../include/datatypes/DTReservaCompInd.h"
//#include "../../include/datatypes/DTReservaCompGrup.h"
#include "../../include/clases/Huesped.h"
class Huesped;
using namespace std;

class DTReservaComp {
private:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    Huesped* huesp;
    int numHab;
    EstadoReserva estado;
public:
    DTReservaComp(int, DTFecha, DTFecha,Huesped*,EstadoReserva,int);
    int getCodigo();
    DTFecha getCheckIn();
    DTFecha getCheckOut();
    Huesped* getHuesped();
    EstadoReserva getEstado();
    int getNumHab();
    virtual ~DTReservaComp();
};

#endif