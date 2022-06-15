#ifndef RESERVA
#define RESERVA
#include <string>
#include <iostream>
#include <list>
#include <set>
#include "Habitacion.h"
#include "Huesped.h"
#include "Estadia.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include "../../include/datatypes/DTReservaComp.h"

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
        list<Estadia*> est;
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
        list<Estadia*> getEstadia();
        virtual DTReserva* getDTReserva()=0;
        virtual DTReservaComp* getDTReservaComp()=0;
        DataEstadia* BuscarRes(Reserva*,DTIdEstadia,std::string);
        void BuscarEstadia(string, DTFecha, DTIdEstadia &);//cambie el nombre
        list<DTIdEstadia> accederaEstadias(Reserva*);
        void hallarEstadia(string,string);
        virtual set<DTReserva*> validarHuespedRegistrado(string)=0;
        virtual void validarHuesped(string)=0;
        void setCodigo(int);
        void setCheckIn(DTFecha);
        void setCheckOut(DTFecha);
        void setRelizada(DTFecha);
        void setEstado(EstadoReserva);
        void setHab(Habitacion*);
        void setHues(Huesped*);
        void setEstadia(list<Estadia*>);
        ~Reserva();
};

#endif
