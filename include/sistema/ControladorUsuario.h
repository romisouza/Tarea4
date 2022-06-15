#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include <iostream>
#include <map>
#include <set>
#include "../../include/clases/Huesped.h"
#include "../../include/clases/Empleado.h"
#include "../../include/datatypes/DTCal.h"
#include "../../include/sistema/IUsuario.h"
using namespace std;

class ControladorUsuario: public IUsuario {
	private:
		static ControladorUsuario* instancia;
		map<std::string, Empleado *> ColEmpleados; //clave email
		map<std::string, Huesped *> ColHuespedes; //clave email
		
		//Para ingresar huesped y empleado
		bool tipoUsuario;
		std::string nombreIngresado;
		std::string emailIngresado;
		std::string passIngresada;
		bool esFingIngresado;
		CargoEmpleado* cargoIngresado; 
		Empleado* empleadoIngresado;
		Hostal* hostalIngresado;
		Hostal* hostalTrabajaEmp;
		//NO VA
		int cantHuespedes,cantEmpleados =0; //(COTI)

		ControladorUsuario();
		~ControladorUsuario();
	public:
		//NO VA
		int getCantHuesped(); //es para ver si me ingreso correctamente los huespedes (COTI)
		int getCantEmpleado(); //es para ver si me ingreso correctamente los emp
		std::string getNombreIngresado(); // (COTI) tmp va
		bool getTipoUsuario();
		void setTipoUsuario(bool);
		static ControladorUsuario* getInstance();
		map<std::string,Empleado*> getColEmpleados();
		map<std::string,Huesped*> getColHuespedes();
		list<DTCal> obtenerComentariosAResponder(std::string mail);
		list<std::string> obtenerHuespedes();
		Empleado* getEmpleadoIngresado();
		CargoEmpleado* getCargoIngresado();
		void ingresarHostal(Hostal*);
		void IngresarHuesped(std::string nombre,std::string email,std::string password,bool esFinger);
		void IngresarEmpleado(std::string nombre,std::string email,std::string password);
		void ingresarEmpleadoPunt(Empleado*);
		void ingresarCargo(CargoEmpleado*);
		void ConfirmarAltaUsuario();
		void CancelarAltaUsuario();
		set<std::string> ObtenerUsuarios();
		Hostal* getHostalTrabajaEmp();
		DTHuesped* SeleccionarHuesped(std::string email);
		DataEmpleado* SeleccionarEmpleado2(std::string email);//cambie el nombre daba error
		list<DTEmpleado> getEmpleados(Hostal* h);
		Empleado* SeleccionarEmpleado(CargoEmpleado* cargoEmp,std::string mailEmp,Hostal*);
		void AsignarCargoAEmpleado();
		list<DTIdEstadia> BuscarHuesped(std::string email, DTFecha);//cambie el nombre
		Estadia* BuscarHuesped2(DTIdEstadia);//Nueva para calificar estadia
		list<DTEmpleado> getNombresEmp();//suscribir empleados
		Empleado* buscarEmpleado(std::string);
};
#endif
