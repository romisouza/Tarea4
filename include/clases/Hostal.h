#ifndef HOSTAL
#define HOSTAL 
#include <iostream>
#include <set>
#include <map>
#include <list>
#include "../../include/datatypes/DTCal.h"
#include "../../include/datatypes/DataHostalComp.h"
#include "../../include/datatypes/DTReservaComp.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include "../../include/datatypes/DataEstadia.h"
#include "../../include/datatypes/DTHostalProm.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/datatypes/DTCalificacion.h"
#include "Reserva.h"
//#include "ReservaGrupal.h"
//#include "ReservaIndividual.h"
#include "Empleado.h"
#include "Calificacion.h"


class Empleado;
class Reserva;
class Habitacion;
class Calificacion;
class DataHostalComp;

using namespace std;


class Hostal{
	private:
		std::string nombre; 
		std::string direccion;
		int telefono;
		int promedio;
		map<int,Reserva*> ColReservas; // clave codigo
		map<int, Habitacion*> ColHabitaciones; //clave numero 
		list<Calificacion*> ColCal;
		map<std::string,Empleado*> ColEmpleadosHost;
	public:
		Hostal();
		Hostal(std::string,std::string,int,int); 
		~Hostal();
		map<std::string,Empleado*> getColEmpleados();
		std::string getNombre();
		std::string getDireccion();
		int getTelefono();
		int getPromedio();
		map<int,Reserva*> getColReservas();
		map<int, Habitacion*> getColHabitaciones();
		list<Calificacion*> getColCal();
		void setNombre(std::string);
		void setDireccion(std::string);
		void setTelefono(int);
		void setPromedio(int);
		set<DTCal> obtenerHostal();
		void BuscarReservas();
		void EliminarRes(Reserva*);
		void AgregarComentarios(std::string,int);
		DataHostalComp getDTHostal();
		DTIdEstadia accesoaReservas();
		DataEstadia accederaReservas(DTIdEstadia);
		void hallarReserva(std::string,int,std::string);
		DTHostalProm getDTHostalProm(Hostal* host);
		set<int> obtenerHabitaciones(DTFecha, DTFecha);
		Habitacion* seleccionarHab(int);
		void AgregarEmpleadoAHostal(Empleado*);
    	Reserva* reservar(DTFecha,int, DTFecha, DTFecha, Huesped*,bool,int,set<Huesped*>);
		//list<DTReservaComp*> ObtenerReservas();
		set<DTCalificacion> obtenerCalificaciones();
		int getPromCal();
		bool TrabajaEnHostal();
		void ingresoAlHostal(int);
		void buscarR(std::string);
		set<DTReserva> BuscarRes(std::string);
		void agregarHabAlHost(Habitacion*);
		void recordarHostal();
};
#endif
