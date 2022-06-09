#ifndef DTESTADIA
#define DTESTADIA
#include <iostream>
#include "../../include/datatypes/DTFecha.h"

class DTEstadia {
    private:
        DTFecha checkIn;
        DTFecha checkOut;
        int promo;
    public:
        DTEstadia(DTFecha, DTFecha, int);
        ~DTEstadia();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        int  getPromo();
};

#endif