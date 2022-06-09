#ifndef IHOSTAL
#define IHOSTAL
#include"../../include/datatypes/DTCal.h"
#include "../../include/datatypes/DTHostalProm.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DTCalificacion.h"
#include "../../include/datatypes/DTEmpleado.h"
#include "../../include/datatypes/DTReservaComp.h"
#include "../../include/datatypes/DataHostalComp.h"
#include "../../include/clases/Empleado.h"

using namespace std;

class IHostal{
    public:
        virtual void agregarHostal(string, string)=0;
        virtual set<DTCal> ObtenerComentariosAResponder(string)=0;
        virtual void ResponderComentario(string, int, string)=0;
        virtual set<DTHostalProm> ObtenerHostales()=0;
        virtual void ingresarDatosReserva(string, DTFecha, DTFecha, bool, int)=0;
        virtual set<int> obtenerHabitacionesDisponibles(DTFecha, DTFecha)=0;
        virtual void seleccionarHabitacion(int)=0;
        virtual set<string> obtenerhuespedesRegistrados()=0;
        virtual void seleccionarHuesped(string)=0;
        virtual void confirmarAltaReserva()=0;
        virtual int generarCodigoReserva()=0;
        virtual void cancelarReserva()=0;
        virtual set<DTReserva> DatosHuesped(string, string)=0;
        virtual void ReservaNCElegida(int)=0;
        virtual void DatosHuesped(string, string)=0;
        virtual void registarHab()=0;
        virtual void cancelarAlta()=0;
        virtual void asginarHab(string, int, float, int)=0;
        virtual set<string> ObtenerHostales()=0;
        virtual set<DTIdEstadia> SeleccionarHostal(string)=0;
        virtual DataEstadia SeleccionarEstadia(DTIdEstadia)=0;
        virtual DTCalificacion MostrarCalificacion()=0;
        virtual DTReserva MostrarInfoReserva()=0;
        virtual set<DTEmpleado> SeleccionarHostal(string)=0;
        virtual void SeleccionarEmpleado(CargoEmpleado,string)=0;
        virtual void ConfirmarAsignacionAUusario()=0;
        virtual void CancelarAsignacionAUusario()=0;
        virtual set<DTReservaComp> SeleccionarHostal(string)=0;
        virtual set<string> ConsultarTop3Hostal(string)=0;
        virtual set<DTCalificacion> SeleccionarHostal(string)=0;
        virtual Empleado SeleccionarEmpleado(CargoEmpleado, string)=0;
        virtual set<DTReserva> SeleccionarHostal(string)=0;
        virtual void SeleccionarReserva(int)=0;
        virtual void ConfirmarEliminarReserva()=0;
        virtual void SeleccionarHostal(string)=0;
        virtual set<DTIdEstadia> ListaEstadiasFInalizada(string)=0;
        virtual void SeleccionarEstadia(DTIdEstadia)=0;
        virtual void ConfirmarCalificacion(string, int)=0;
        virtual DTHostalComp SeleccionarHostal(string)=0;
        virtual void CancelarBajaReserva()=0;
        virtual ~IHostal(){}; //vacio
};

#endif