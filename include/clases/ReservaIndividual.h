#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL
#include "../../include/datatypes/DTReserva.h"
#include "Reserva.h"
#include <set>
#include <string>
#include <iostream>
using namespace std;
class ReservaIndividual:public Reserva{
    private:
    public:
        ReservaIndividual();
        set<DTReserva> validarHuespedRegistrado(string);
        void validarHuesped(string);
        ~ReservaIndividual();

};

#endif