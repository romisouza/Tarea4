#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include <iostream>
#include <map>
#include "../../include/clases/Huesped.h"
#include "../../include/clases/Empleado.h"
#include "../../include/datatypes/DTCal.h"
using namespace std;

class ControladorUsuario {
	private:
		static ControladorUsuario* instancia;
		map<string, Empleado *> ColEmpleados; //clave email
		map<string, Huesped *> ColHuesped; //clave email
		ControladorUsuario();
		~ControladorUsuario();
	public:
		static ControladorUsuario* getInstance();
		Set(DTCal) obtenerComentariosAResponder(string mail);
		Set(string) obtenerHuespedes();
		void seleccionar(string mailHuesped);
		void IngresarHuesped(string nombre,string email,string password,bool esFinger);
		void IngresarEmpleado(string nombre,string email,string password,CargoEmpleado cargo);
		void ConfirmarAltaUsuario();
		void CancelarAltaUsuario();
		Set(string) ObtenerUsuarios();
		DTHuesped SeleccionarHuesped(string email);
		DataEmpleado SeleccionarEmpleado(string email);
		Set(DTEmpleado) getEmpleados(Hostal h);
		Empleado SeleccionarEmpleado(CargoEmpleado cargoEmp,string mailEmp);
		void AsignarCargoAEmpleado();
		void BuscarHuesped(string email);
		void SuscribirEmpleado(string emp);
		Set(DTCalificacion) ObtenerNotificaciones(string email);
		void EliminarNotificaciones();
};
#endif