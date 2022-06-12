#ifndef DTRESERVA
#define DTRESERVA
#include <iostream>
#include "../../include/datatypes/DTFecha.h"
enum EstadoReserva {Abierta, Cerrada, Cancelada};

class DTReserva {
    private:
        int codigo;
        DTFecha checkIn;
        DTFecha checkOut;
    public:
        DTReserva(int, DTFecha, DTFecha);
        ~DTReserva();
        int getCodigo();
        DTFecha getCheckIn();
        DTFecha getCheckOut(); 
};

#endif