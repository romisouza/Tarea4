#ifndef IUSUARIO
#define IUSUARIO
#include <iostream>
#include <string>
#include "../../include/clases/Empleado.h"
#include "../../include/clases/Hostal.h"
#include"../../include/datatypes/DTCal.h"
#include"../../include/datatypes/DTHuesped.h"
#include"../../include/datatypes/DataEmpleado.h"
#include"../../include/datatypes/DTEmpleado.h"

class IUsuario {
    public:
        virtual int getCantHuesped() =0; //es para ver si me ingreso correctamente los huespedes (COTI)
		virtual int getCantEmpleado() =0; //es para ver si me ingreso correctamente los emp
		virtual std::string getNombreIngresado() =0; // (COTI) tmp va
		virtual bool getTipoUsuario() =0;
		virtual void setTipoUsuario(bool) =0;
		virtual map<std::string,Empleado*> getColEmpleados() =0;
		virtual map<std::string,Huesped*> getColHuespedes() =0;
		virtual list<DTCal> obtenerComentariosAResponder(std::string mail) =0;
		virtual list<std::string> obtenerHuespedes() =0;
		virtual Empleado* getEmpleadoIngresado() =0;
		virtual CargoEmpleado* getCargoIngresado() =0;
		virtual void ingresarHostal(Hostal*) =0;
		virtual void IngresarHuesped(std::string nombre,std::string email,std::string password,bool esFinger) =0;
		virtual void IngresarEmpleado(std::string nombre,std::string email,std::string password) =0;
		virtual void ingresarEmpleadoPunt(Empleado*) =0;
		virtual void ingresarCargo(CargoEmpleado*) =0;
		virtual void ConfirmarAltaUsuario() =0;
		virtual void CancelarAltaUsuario() =0;
		virtual set<std::string> ObtenerUsuarios() =0;
		virtual Hostal* getHostalTrabajaEmp() =0;
		virtual DTHuesped* SeleccionarHuesped(std::string email) =0;
		virtual DataEmpleado* SeleccionarEmpleado2(std::string email) =0;//cambie el nombre daba error
		virtual list<DTEmpleado> getEmpleados(Hostal* h) =0;
		virtual Empleado* SeleccionarEmpleado(CargoEmpleado* cargoEmp,std::string mailEmp,Hostal*) =0;
		virtual void AsignarCargoAEmpleado() =0;
		virtual list<DTIdEstadia> BuscarHuesped(std::string email, DTFecha) =0;//cambie el nombre
		virtual Estadia* BuscarHuesped2(DTIdEstadia) =0;//Nueva para calificar estadia
		virtual list<DTEmpleado> getNombresEmp() =0;//suscribir empleados
		virtual Empleado* buscarEmpleado(std::string) =0;
		virtual Huesped* buscarHuesped(std::string) = 0;
		virtual list<std::string> empleadosEnHostal(std::string) = 0;
		virtual bool existeEmp(std::string )=0;
		virtual ~IUsuario(){};

};

#endif
