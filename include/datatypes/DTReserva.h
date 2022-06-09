#ifndef DTRESERVA
#define DTRESERVA
#include <iostream>
#include <string>
#include "../../include/datatypes/DTFecha.h"
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