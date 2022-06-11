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
        set<Huesped*> huespedes;
        int TotalHuesp;
    public:
        ReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout,DTFecha realiza, int totalHuespedes);
        set<Huesped*> getHuespedes();
        int getTotalHuesp();
        void setTotalHuesp();
        ~ReservaGrupal();
};


#endif