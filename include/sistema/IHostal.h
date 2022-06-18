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
		virtual void ingresarHostal(Hostal*) =0;
		virtual void ingresarEmpleado(Empleado*) =0;
		virtual void agregarHostal(std::string, std::string, std::string) =0;//Alta Hostal
		virtual set<std::string> ObtenerNombreHostales() =0; //Alta habitacion (ObtenerHostales)
		virtual void asignarHab(std::string, int, float, int) =0;//Alta habitacion; 
		virtual void registrarHab() =0; //Alta habitacion ; 
		virtual void cancelarAltaHabitacion() =0; //Alta habitacion (cancelarAlta)
		virtual list<DTEmpleado> ObtenerEmpleados(std::string nombreHostal) =0; //Asignar Empleado a Hostal (SelecccionarHostal)
		virtual void SeleccionarEmpleado(CargoEmpleado*, std::string) =0;//Asignar emp a hostal
		virtual void ConfirmarAsignacionDeEmpleado() =0;//asignar emp a host (confirmarAsignacionAUsuario)
		virtual void CancelarAsignacionDeEmpleado() =0;//asignar emp a host (cancelarAsignacionAUsuario)
		virtual list<DTHostalProm> ObtenerHostalesProm() =0; //Realizar reserva (ObtenerHostales)
		virtual void ingresarDatosReserva(std::string, DTFecha, DTFecha, bool, int) =0;//realizar reserva
		virtual list<int> obtenerHabitacionesDisponibles(DTFecha, DTFecha,int) =0;//realizar reserva
		virtual void seleccionarHabitacion(int) =0; //realizar res
		virtual list<std::string> obtenerHuespedesRegistrados() =0;//realizar res
		virtual void seleccionarHuesped(std::string) =0;//realizar res
		virtual void seleccionarAcompaniante(std::string) =0; //realizar res
		virtual int confirmarAltaReserva() =0;//realizar res
		virtual int generarCodigoReserva() =0;//realizar res
		virtual void cancelarAltaReserva() =0;//realizar res (cancelarReserva)
		virtual list<std::string> ConsultarTop3Hostal() =0;//Consultartop3
		virtual list<DTCalificacion> ObtenerCalificaciones(std::string) =0;//Consultartop3 (ObtenerHostal)
		virtual list<DTReserva*> ObtenerReservasNC(std::string, std::string) =0;//registrar estadia (DatosHuesped)
		virtual void ReservaNCElegida(int,Huesped*) =0;//registrar estadia
		virtual void DatosHuesped(std::string,std::string,bool&) =0;//finalizar estadia NO SE QUE HACE LA FUNCION XD
		virtual void SeleccionarHostal(std::string) =0;//calificar estadia
		virtual void ingresarEstadiaFinalizada(Estadia*) =0;//Nueva, recuerda la estadia de un huesped
		virtual list<DTIdEstadia> ListaEstadiasFinalizadas(std::string) =0;//calificar estadia
		virtual void SeleccionarEstadia(DTIdEstadia) =0;//calificar estadia, cambie el nombre
		virtual void ConfirmarCalificacion (std::string, int) =0;//calificar estadiaDatoet
		virtual list<DTCal> ObtenerComentariosAResponder(std::string) =0;//comentar calificacion
		virtual void ResponderComentario(std::string, int, std::string) =0;//comentarcalificacion
		virtual DataHostalComp ObtenerHostalComp(std::string) =0;//Consulta Hostal (SeleccionarHostal)
		virtual list<DTReservaComp*> ObtenerReservasComp(std::string) =0;//consulta reserva (SeleccionarHostal)
		virtual list<DTIdEstadia> ObtenerDTIdEstadia(std::string) =0;//consulta estadia (SeleccionarHostal)
		virtual DataEstadia* ObtenerinfoEstadia(DTIdEstadia) =0;//consulta estadia  (SeleccionarEstadia)
		virtual DTCalificacion MostrarCalificacion() =0;//consulta estadia
		virtual DTReserva* MostrarInfoReserva(std::string, int codigoRes) =0;//consulta estadia
		virtual void LiberarMemoria() =0; //consulta estadia		
		virtual void ingresarReserva(Reserva*) =0;//nueva, recuerda una reserva
		virtual list<DTReserva*> ObtenerReservas(std::string) =0;//baja reserva (Selecccionar Hostal)
		virtual void SeleccionarReserva(int) =0;//baja reserva 
		virtual void ConfirmarEliminarReserva() =0;//baja reserva
		virtual void agregarObserver(IObserver*) =0;
		virtual void eliminarObserver(IObserver*) =0;
		virtual void SuscribirEmpleado(string emp) =0;
		virtual list<DTCalificacion> ObtenerNotificaciones(string email) =0;
		virtual void EliminarNotificaciones() =0;
		virtual void eliminarSuscripcion(string emp) =0;
		virtual list<IObserver*> ObtenerSuscritos() =0;
		virtual list<DTEmpleado> ObtenerEmpleados()=0;
		virtual IObserver* BuscarEmp(string)=0;
		virtual void CancelarBajaReserva() =0;//baja reserva
		virtual void actualizarFS(int,int,int,int,int)=0;
};

#endif
