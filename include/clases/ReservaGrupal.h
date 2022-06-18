#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

#include <string>
#include <iostream>
#include "Reserva.h"
#include "Huesped.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/clases/Reserva.h"

using namespace std;

class ReservaGrupal:public Reserva{
    private:
        set<Huesped*> huespedes;
        int TotalHuesp;
    public:
        ReservaGrupal(int codigo, DTFecha checkin, DTFecha checkout,DTFecha realiza, int totalHuespedes);
        set<Huesped*> getHuespedes();
        void setHuespedes(set<Huesped*>);
        int getTotalHuesp();
        void setTotalHuesp();
        virtual DTReserva* getDTReserva();
        virtual DTReservaComp* getDTReservaComp();
        virtual bool validarHuespedRegistrado(string);
        /*virtual void agregarAcompañante(Huesped*);*/
        virtual void validarHuesped(string,DTFecha,bool&);
        virtual ~ReservaGrupal();
};


#endif
