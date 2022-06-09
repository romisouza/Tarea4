#ifndef HOSTAL
#define HOSTAL 
#include <iostream>
#include <set>
#include "../../include/datatypes/DTCal.h"
#include "../../include/datatypes/DataHostalComp.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DTHostalProm.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DTCalificacion.h"
#include "Reserva.h"
#include "Empleado.h"
#include "Calificacion.h"

using namespace std;


class Hostal{
	private:
		std::string nombre; 
		std::string direccion;
		int telefono;
		int promedio;
		map<int,Reserva*> ColReservas; // clave codigo
		map<int, Habitacion*> ColHabitaciones; //clave numero 
		set<Calificacion> ColCal;
		map<std::string,Empleado*> ColEmpleados;
	public:
		Hostal();
		Hostal(std::string,std::string,int,int); //faltan las colecciones de reservas y habitaciones
		~Hostal();
		map<std::string,Empleado*> getColEmpleados();
		std::string getNombre();
		std::string getDireccion();
		int getTelefono();
		int getPromedio();
		map<int,Reserva*> getColReservas();
		map<int, Habitacion*> getColHabitaciones();
		set<Calificacion> getColCal();
		void setNombre(std::string);
		void setDireccion(std::string);
		void setTelefono(int);
		void setPromedio(int);
		void agregarReserva(int, Reserva*);//nueva
		void agregarHabitacion(int, Habitacion*);//nueva
		set<DTCal> obtenerHostal();
		void BuscarReservas();
		void EliminarRes(Reserva*);
		void AgregarComentarios(std::string,int);
		DataHostalComp getDTHostal();
		DTIdEstadia accesoaReservas();
		DataEstadia accederaReservas(DTIdEstadia);
		void hallarReserva(std::string,int,std::string);
		DTHostalProm getDTHostalProm();
		set<int> obtenerHabitaciones(DTFecha, DTFecha);
		void seleccionarHab(int);
		void AgregarEmpleadoAHostal();
		set<DTReserva> ObtenerReservas();
		set<DTCalificacion> obtenerCalificaciones();
		int getPromCal();
		bool TrabajaEnHostal();
		void ingresoAlHostal(int);
		void buscarR(std::string);
		set<DTReserva> BuscarRes(std::string);
		void agregarHabAlHost();
		void recordarHostal();
};
#endif
