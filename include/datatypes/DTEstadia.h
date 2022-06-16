#ifndef DTESTADIA
#define DTESTADIA
#include <iostream>
#include "../../include/datatypes/DTFecha.h"

class DTEstadia {
    private:
        DTFecha checkIn;
        DTFecha checkOut;
    public:
        DTEstadia(DTFecha, DTFecha);
        ~DTEstadia();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
};

#endif