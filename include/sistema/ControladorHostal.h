#ifndef CONTROLADORHOSTAL
#define CONTROLADORHOSTAL
#include <iostream>
#include <stdlib.h>
#include <set>
#include <map>
#include <list>
#include "../../include/clases/Hostal.h"
#include "../../include/sistema/IHostal.h"
#include "../../include/clases/Empleado.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include "../../include/datatypes/DTEmpleado.h"
#include "../../include/datatypes/DTHostalProm.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DataHostalComp.h"
#include "../../include/datatypes/DTCalificacion.h"
#include "../../include/datatypes/DTReservaComp.h"
#include "../../include/sistema/ControladorUsuario.h"
#include "../../include/sistema/SingletonFechaHora.h"
#include "../../include/sistema/IObserver.h"
#include "../../include/sistema/SingletonFechaHora.h"

using namespace std;

class ControladorHostal:public IHostal {
	private: 
		static ControladorHostal* instancia;
		map<std::string,Hostal*> ColHostales; // clave nombre
		//para asignar empleado a hostal
		Hostal* hostalIngresado;
		Empleado* empleadoIngresado; 
		//para alta de habitacion
		int numero; 
    	float precioNoche;
    	int capacidad;
		//Para realizar reserva
		set<Huesped*> acompaniantesIngresados;
		Huesped* huespRecordado;
		std::string nombreHostalIngresado;
		DTFecha fechaInIngresada;
		DTFecha fechaOutIngresada;
		bool gruppOindIngresado;
		int totalHuespIngresado;
		Habitacion* habRecordada;
		//para generar el codigo de las reservas
		int codigoRes = 100;
		//para calificar estadia
		Estadia* EstadiaFinalizada;
		//consulta de estadia
		std::string hostalRecordado;
		DataEstadia* estadiaRecordada;
		//baja de reserva
		Reserva* reservaIngresada;
		//Notificaciones
		list<IObserver*> obs;
		ControladorHostal();
		~ControladorHostal();
	public: 
		static ControladorHostal* getInstance();
		void ingresarHostal(Hostal*);
		void ingresarEmpleado(Empleado*);
		void agregarHostal(std::string, std::string, std::string);//Alta Hostal
		set<std::string> ObtenerNombreHostales(); //Alta habitacion (ObtenerHostales)
		void asignarHab(std::string, int, float, int);//Alta habitacion; 
		void registrarHab(); //Alta habitacion ; 
		void cancelarAltaHabitacion(); //Alta habitacion (cancelarAlta)
		list<DTEmpleado> ObtenerEmpleados(std::string nombreHostal); //Asignar Empleado a Hostal (SelecccionarHostal)
		void SeleccionarEmpleado(CargoEmpleado*, std::string);//Asignar emp a hostal
		void ConfirmarAsignacionDeEmpleado();//asignar emp a host (confirmarAsignacionAUsuario)
		void CancelarAsignacionDeEmpleado();//asignar emp a host (cancelarAsignacionAUsuario)
		list<DTHostalProm> ObtenerHostalesProm(); //Realizar reserva (ObtenerHostales)
		void ingresarDatosReserva(std::string, DTFecha, DTFecha, bool, int);//realizar reserva
		list<int> obtenerHabitacionesDisponibles(DTFecha, DTFecha,int);//realizar reserva
		void seleccionarHabitacion(int); //realizar res
		list<std::string> obtenerHuespedesRegistrados();//realizar res
		void seleccionarHuesped(std::string);//realizar res
		void seleccionarAcompaniante(std::string); //realizar res
		int confirmarAltaReserva();//realizar res
		int generarCodigoReserva();//realizar res
		void cancelarAltaReserva();//realizar res (cancelarReserva)
		list<std::string> ConsultarTop3Hostal();//Consultartop3
		list<DTCalificacion> ObtenerCalificaciones(std::string);//Consultartop3 (ObtenerHostal)
		list<DTReserva*> ObtenerReservasNC(std::string, std::string);//registrar estadia (DatosHuesped)
		void ReservaNCElegida(int,Huesped*);//registrar estadia
		void DatosHuesped(std::string,std::string);//finalizar estadia NO SE QUE HACE LA FUNCION XD
		void SeleccionarHostal(std::string);//calificar estadia
		void ingresarEstadiaFinalizada(Estadia*);//Nueva, recuerda la estadia de un huesped
		list<DTIdEstadia> ListaEstadiasFinalizadas(std::string);//calificar estadia
		void SeleccionarEstadia(DTIdEstadia);//calificar estadia, cambie el nombre
		void ConfirmarCalificacion (std::string, int);//calificar estadiaDatoet
		list<DTCal> ObtenerComentariosAResponder(std::string);//comentar calificacion
		void ResponderComentario(std::string, int, std::string);//comentarcalificacion
		DataHostalComp ObtenerHostalComp(std::string);//Consulta Hostal (SeleccionarHostal)
		list<DTReservaComp*> ObtenerReservasComp(std::string);//consulta reserva (SeleccionarHostal)
		list<DTIdEstadia> ObtenerDTIdEstadia(std::string);//consulta estadia (SeleccionarHostal)
		DataEstadia* ObtenerinfoEstadia(DTIdEstadia);//consulta estadia  (SeleccionarEstadia)
		DTCalificacion MostrarCalificacion();//consulta estadia
		DTReserva* MostrarInfoReserva(std::string, int codigoRes);//consulta estadia
		void LiberarMemoria(); //consulta estadia		
		void ingresarReserva(Reserva*);//nueva, recuerda una reserva
		list<DTReserva*> ObtenerReservas(std::string);//baja reserva (Selecccionar Hostal)
		void SeleccionarReserva(int);//baja reserva 
		void ConfirmarEliminarReserva();//baja reserva
		void agregarObserver(IObserver*);
		void eliminarObserver(IObserver*);
		void SuscribirEmpleado(string emp);
		list<DTCalificacion> ObtenerNotificaciones(string email);
		void EliminarNotificaciones();
		void eliminarSuscripcion(string emp);
		list<DTEmpleado> ObtenerEmpleados();
		void CancelarBajaReserva();//baja reserva
		void actualizarFS(int,int,int,int,int); //modificarFechaSistema
};

#endif
