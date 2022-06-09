#ifndef CONTROLADORHOSTAL
#define CONTROLADORHOSTAL
#include <iostream>
#include <stdlib.h>
#include <set>
#include <map>
#include "../../include/clases/Hostal.h"
#include "../../include/sistema/IHostal.h"
#include "../../include/clases/Empleado.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include "../../include/datatypes/DTEmpleado.h"
#include "../../include/datatypes/DTHostalProm.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DTCalificacion.h"
#include "../../include/datatypes/DTReservaComp.h"

using namespace std;

class ControladorHostal:public IHostal {
	private: 
		static ControladorHostal* instancia;
		map<std::string,Hostal*> ColHostales; // clave nombre 
		ControladorHostal();
		~ControladorHostal();
	public: 
		static ControladorHostal* getInstance();
		void agregarHostal(std::string, std::string, int);
		Set(DTCal) ObtenerComentariosAResponder(std::string);
		void ResponderComentarios (std::string, int, std::string);
		Set(DTHostalProm) ObtenerHostales();
		void ingresarDatosReserva(std::string, DTFecha, DTFecha, bool, int);
		Set(int) obtenerHabitacionesDisponibles(DTFecha, DTFecha);
		void seleccionarHabitacion(int);
		Set(std::string) obtenerHuespedesRegistrados();
		void seleccionarHuesped(std::string);
		void confirmarAltaReserva();
		int generarCodigoReserva();
		void cancelarReserva();
		Set(DTReserva) DatosHuesped(std::string, std::string,int);
		void ReservaNCElegida(int);
		void DatosHuesped(std::string,std::string);
		void registrarHab();
		void cancelarAlta();
		void asignarHab(std::string, int, float, int);
		Set(std::string) ObtenerHostales();
		Set(DTIdEstadia) SeleccionarHostal(std::string);
		DataEstadia SeleccionarEstadia(DTIdEstadia);
		DTCalificacion MostrarCalificacion();
		DTReserva MostrarInfoReserva();
		set<DTEmpleado> ControladorHostal::ObtenerDtEmpleado(std::string nombreHostal);
		void SeleccionarEmpleado(CargoEmpleado, std::string);
		void ConfirmarAsignacionAUsuario();
		void CancelarAsignacionAUsuario();
		Set(DTReservaComp) SeleccionarHostal(std::string);
		Set(std::string) ConsultarTop3Hostal();
		Set(DTReserva) SeleccionarHostal(std::string);
		void SeleccionarReserva(int);
		void ConfirmarEliminarReserva();
		void SeleccionarHostal(std::string);
		Set(DTIdEstadia) ListaEstadiasFinalizadas(std::string);
		void SeleccionarEstadia(DTIdEstadia);
		void ConfirmarCalificacion (std::string, int);
		DataHostalComp ObtenerHostalComp(std::string);
		void CancelarBajaReserva();
		void LiberarMemoria();
		Set(DTCalificacion) SeleccionarHostal(std::string);

};

#endif