#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DTReservaIndividual.h"
#include "Reserva.h"
#include <set>
#include <string>
#include <iostream>
using namespace std;
class ReservaIndividual:public Reserva{
    private:
    public:
        ReservaIndividual(int codigo, DTFecha checkin, DTFecha checkout,DTFecha realiza);
        virtual DTReserva* getDTReserva();
        virtual set<DTReserva*> validarHuespedRegistrado(string);
        virtual DTReservaComp* getDTReservaComp();
        virtual void validarHuesped(string);
        ~ReservaIndividual();
};

#endif