#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

#include <string>
#include <iostream>
#include "Huesped.h"
#include "../../include/datatypes/DTFecha.h"
#include "Reserva.h"
using namespace std;
class ReservaGrupal:public Reserva{
    private:
        set<Huesped> huespedes;
        int TotalHuesp;
    public:
        ReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout, EstadoReserva estado, Habitacion* hab,Huesped* huesp, set<Huesped*> huespedes,int TotalHuespedes);
        set(Huesped) getHuespedes();
        int getTotalHuesp();
        void setTotalHuesp();
        ~ReservaGrupal();
};


#endif