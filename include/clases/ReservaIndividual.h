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
        ReservaIndividual(int codigo, DTFecha checkin, DTFecha checkout,DTFecha realiza);
       // set<DTReserva> validarHuespedRegistrado(string);
        //virtual DTReservaComp getDTReservaComp();
        //void validarHuesped(string);
        //~ReservaIndividual();

};

#endif