#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL
#include <string>
#include <iostream>
#include "../clases/Reserva.h"
#include "../clases/ReservaIndividual.h"

using namespace std;
class DTReservaIndividual:public DTReserva{
    private:
    public:
        DTReservaIndividual(int, DTFecha, DTFecha,EstadoReserva);
        virtual ~DTReservaIndividual();
};

#endif