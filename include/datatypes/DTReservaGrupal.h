#ifndef DTRESERVAGRUPAL
#define DTRESERVAGRUPAL
#include <string>
#include <iostream>
#include "DTHuesped.h"
#include "../clases/Reserva.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/clases/Huesped.h"
#include "../../include/clases/ReservaGrupal.h"
#include <set>
using namespace std;

class DTReservaGrupal: public DTReserva {
    private:
        set<Huesped*> huespedes;
        int TotalHuesp;
    public:
        DTReservaGrupal(int, DTFecha, DTFecha, EstadoReserva,set<Huesped*>,int);
        set<Huesped*> getHuespedes();
        int getTotalHuesp();
        virtual ~DTReservaGrupal();

};

#endif