#ifndef HOSTAL
#define HOSTAL 
#include <string>
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

using namespace std;


class Hostal{
	private:
		string nombre; 
		string direccion;
		int telefono;
		int promedio;
		map<int,Reserva*> ColReservas; // clave codigo
		map<int, Habitacion*> ColHabitaciones; //clave numero 
		map<std::string,Empleado*> ColEmpleados;
	public:
		Hostal();
		Hostal(string,string,int,int); //faltan las colecciones de reservas y habitaciones
		~Hostal();
		map<std::string,Empleado*> getColEmpleados();
		string getNombre();
		string getDireccion();
		int getTelefono();
		int getPromedio();
		map<int,Reserva*> getColReservas();
		map<int, Habitacion*> getColHabitaciones();
		void setNombre(string);
		void setDireccion(string);
		void setTelefono(int);
		void setPromedio(int);
		void agregarReserva(int, Reserva*);//nueva
		void agregarHabitacion(int, Habitacion*);//nueva
		Set<DTCal> obtenerHostal();
		void BuscarReservas();
		void EliminarRes(Reserva*);
		void AgregarComentarios(string,int);
		DataHostalComp getDTHostal();
		DTIdEstadia accesoaReservas();
		DataEstadia accederaReservas(DTIdEstadia);
		void hallarReserva(string,int,string);
		DTHostalProm getDTHostalProm();
		Set(int) obtenerHabitaciones(DTFecha, DTFecha);
		void seleccionarHab(int);
		void AgregarEmpleadoAHostal();
		Set(DTReserva) ObtenerReservas();
		Set(DTCalificacion) obtenerCalificaciones();
		int getPromCal();
		bool TrabajaEnHostal();
		void ingresoAlHostal(int);
		void buscarR(string);
		Set(DTReserva) BuscarRes(string);
		void agregarHabAlHost();
		void recordarHostal();
};
#endif
