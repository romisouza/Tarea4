#ifndef ESTADIA
#define ESTADIA
#include <string>
#include <iostream>
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DTCalificacion.h"
#include "../../include/clases/Huesped.h"
#include "Reserva.h"
#include "../../include/clases/Calificacion.h"

class Reserva;
class Huesped;
class Calificacion;
class DTFecha;

class Estadia{
    private:
        DTFecha checkOut;
        DTFecha checkIn;
        Huesped* huesp;
        Reserva* res;
        Calificacion* cal; 
    public:
        Estadia(DTFecha, DTFecha, Huesped*, Reserva*);
        Estadia();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        Huesped* getHuesp();
        Reserva* getReserva();
        Calificacion* getCal();
        void setCheckIn(DTFecha);
        void setCheckOut(DTFecha);
        void setHuesp(Huesped*);
        void setReserva(Reserva*);
        void setCalificacion(Calificacion*);
        Estadia* getEstadia();
        DTIdEstadia getDTIdEstadia();
        DataEstadia* getDataEstadia();
        void hallarHuesped(string, string);
        DTCalificacion accederaEstadia();
        ~Estadia();
};
#endif