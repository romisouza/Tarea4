#ifndef RESERVA
#define RESERVA
#include <string>
#include <iostream>
#include <set>
#include "Habitacion.h"
#include "Huesped.h"
#include "Estadia.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DTIdEstadia.h"

enum EstadoReserva {Abierta, Cerrada, Cancelada};
class Habitacion;
class Huesped;
class Estadia;
using namespace std;

class Reserva{
    private:
        int codigo;
        DTFecha checkIn;
        DTFecha checkOut;
        DTFecha fechaRealizada;
        EstadoReserva estado;
        Habitacion *hab;
        Huesped *hues;
        Estadia *est;
    public:
        Reserva();
        Reserva(int,DTFecha,DTFecha,DTFecha);
        int getCodigo();
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        DTFecha getRealizada();
        EstadoReserva getEstado();
        Habitacion* getHab();
        Huesped* getHues();
        Estadia* getEstadia();
        DTReserva getDTReserva();
        DataEstadia BuscarRes(DTIdEstadia);
        void BuscarEstadia();
        DTIdEstadia accederaEstadias();
        void hallarEstadia(string,string);
        virtual set<DTReserva> validarHuespedRegistrado(string)=0;
        virtual void validarHuesped(string)=0;
       // bool compararFecha(DTFecha,DTFecha); AHORA VA A ESTAR EN DTFECHA X LO Q DIJO EL PROFE EN LA CORRECION
        void setCodigo(int);
        void setCheckIn(DTFecha);
        void setCheckOut(DTFecha);
        void setRelizada(DTFecha);
        void setEstado(EstadoReserva);
        void setHab(Habitacion*);
        void setHues(Huesped*);
        void setEstadia(Estadia*);
        ~Reserva();
};

#endif
