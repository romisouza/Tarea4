#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include <iostream>
#include <map>
#include <set>
#include "../../include/clases/Huesped.h"
#include "../../include/clases/Empleado.h"
#include "../../include/datatypes/DTCal.h"
using namespace std;

class ControladorUsuario {
	private:
		static ControladorUsuario* instancia;
		map<std::string, Empleado *> ColEmpleados; //clave email
		map<std::string, Huesped *> ColHuesped; //clave email
		
		//Para ingresar huesped y empleado
		std::string nombreIngresado;
		std::string emailIngresado;
		std::string passIngresada;
		bool esFingIngresado;
		CargoEmpleado cargoIngresado;
		
		ControladorUsuario();
		~ControladorUsuario();
	public:
		static ControladorUsuario* getInstance();
		map<std::string,Empleado*> getColEmpleados();
		set<DTCal> obtenerComentariosAResponder(std::string mail);
		set<std::string> obtenerHuespedes();
		void seleccionar(std::string mailHuesped);
		void IngresarHuesped(std::string nombre,std::string email,std::string password,bool esFinger);
		void IngresarEmpleado(std::string nombre,std::string email,std::string password,CargoEmpleado cargo);
		void ConfirmarAltaUsuario();
		void CancelarAltaUsuario();
		set<std::string> ObtenerUsuarios();
		DTHuesped SeleccionarHuesped(std::string email);
		DataEmpleado SeleccionarEmpleado(std::string email);
		set<DTEmpleado> getEmpleados(Hostal h);
		Empleado SeleccionarEmpleado(CargoEmpleado cargoEmp,std::string mailEmp);
		void AsignarCargoAEmpleado();
		void BuscarHuesped(std::string email);
		void SuscribirEmpleado(std::string emp);
		set<DTCalificacion> ObtenerNotificaciones(std::string email);
		void EliminarNotificaciones();
};
#endif
