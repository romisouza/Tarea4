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
		map<std::string, Huesped *> ColHuespedes; //clave email
		
		//Para ingresar huesped y empleado
		std::string nombreIngresado;
		std::string emailIngresado;
		std::string passIngresada;
		bool esFingIngresado;
		CargoEmpleado* cargoIngresado; 
		Empleado* empleadoIngresado;
		Hostal* hostalIngresado;

		//NO VA
		int cantHuespedes,cantEmpleados =0; //(COTI)

		ControladorUsuario();
		~ControladorUsuario();
	public:
		//NO VA
		int getCantHuesped(); //es para ver si me ingreso correctamente los huespedes (COTI)
		int getCantEmpleado(); //es para ver si me ingreso correctamente los emp
		std::string getNombreIngresado(); // (COTI) tmp va

		static ControladorUsuario* getInstance();
		map<std::string,Empleado*> getColEmpleados();
		set<DTCal> obtenerComentariosAResponder(std::string mail);
		set<std::string> obtenerHuespedes();
		Empleado* getEmpleadoIngresado();
		CargoEmpleado* getCargoIngresado();
		void ingresarHostal(Hostal*);
		void seleccionar(std::string mailHuesped);
		void IngresarHuesped(std::string nombre,std::string email,std::string password,bool esFinger);
		void IngresarEmpleado(std::string nombre,std::string email,std::string password,CargoEmpleado* cargo);
		void ingresarEmpleadoPunt(Empleado*);
		void ingresarCargo(CargoEmpleado*);
		void ConfirmarAltaUsuario();
		void CancelarAltaUsuario();
		set<std::string> ObtenerUsuarios();
		DTHuesped SeleccionarHuesped(std::string email);
		DataEmpleado SeleccionarEmpleado2(std::string email);//cambie el nombre daba error
		list<DTEmpleado> getEmpleados(Hostal* h);
		Empleado* SeleccionarEmpleado(CargoEmpleado* cargoEmp,std::string mailEmp,Hostal*);
		void AsignarCargoAEmpleado();
		void BuscarHuesped(std::string email);
		void SuscribirEmpleado(std::string emp);
		set<DTCalificacion> ObtenerNotificaciones(std::string email);
		void EliminarNotificaciones();
};
#endif
