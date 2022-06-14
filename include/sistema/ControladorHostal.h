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
		int codigoRes;
		//para calificar estadia
		list<Estadia*> EstadiasFinalizadas;
		Estadia* EstadiaFinalizada;
		string nombreHuesped;
		string emailHuesped;

		ControladorHostal();
		~ControladorHostal();
	public: 
		static ControladorHostal* getInstance();
		void ingresarHostal(Hostal*);
		void ingresarEmpleado(Empleado*);
		void agregarHostal(std::string, std::string, int);//Alta Hostal
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
		set<int> obtenerHabitacionesDisponibles(DTFecha, DTFecha);//realizar reserva
		void seleccionarHabitacion(int); //realizar res
		set<std::string> obtenerHuespedesRegistrados();//realizar res
		void seleccionarHuesped(std::string);//realizar res
		void confirmarAltaReserva();//realizar res
		int generarCodigoReserva();//realizar res
		void cancelarAltaReserva();//realizar res (cancelarReserva)
		set<std::string> ConsultarTop3Hostal();//Consultartop3
		set<DTCalificacion> ObtenerCalificaciones(std::string);//Consultartop3 (ObtenerHostal)
		set<DTReserva> ObtenerReservasNC(std::string, std::string,int);//registrar estadia (DatosHuesped)
		void ReservaNCElegida(int);//registrar estadia
		void DatosHuesped(std::string,std::string);//finalizar estadia NO SE QUE HACE LA FUNCION XD
		void SeleccionarHostal(std::string);//calificar estadia
		void ingresarEstadiasFinalizadas(list<Estadia*>);//Nueva, recuerda una estadia
		void ingresarEstadiaFinalizada(Estadia*);//Nueva, recuerda la estadia de un huesped
		void ingresarEmailHuesped(string); // Nueva, recuerda el email de un huesped
		void ingresarNombreHuesped(string); //Nueva, recuerda el nombre de un huesped
		list<Estadia*> ListaEstadiasFinalizadas(std::string);//calificar estadia
		void SeleccionarEstadia(Estadia);//calificar estadia, cambie el nombre
		void ConfirmarCalificacion (std::string, int);//calificar estadiaDatoet
		set<DTCal> ObtenerComentariosAResponder(std::string);//comentar calificacion
		void ResponderComentarios (std::string, int, std::string);//comentarcalificacion
		DataHostalComp ObtenerHostalComp(std::string);//Consulta Hostal (SeleccionarHostal)
		//set<DTReservaComp> ObtenerReservasComp(std::string);//consulta reserva (SeleccionarHostal)
		set<DTIdEstadia> ObtenerDTIdEstadia(std::string);//consulta estadia (SeleccionarHostal)
		DataEstadia ObtenerinfoEstadia(DTIdEstadia);//consulta estadia  (SeleccionarEstadia)
		DTCalificacion MostrarCalificacion();//consulta estadia
		DTReserva MostrarInfoReserva();//consulta estadia
		void LiberarMemoria(); //consulta estadia		
		set<DTReserva> ObtenerReservas(std::string);//baja reserva (Selecccionar Hostal)
		void SeleccionarReserva(int);//baja reserva 
		void ConfirmarEliminarReserva();//baja reserva
		void CancelarBajaReserva();//baja reserva	
};

#endif