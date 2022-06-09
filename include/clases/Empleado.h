#ifndef EMPLEADO
#define EMPLEADO
#include "Usuario.h"
#include "Hostal.h"
#include "Calificacion.h"
#include "../../include/sistema/IObserver.h"
#include "../../include/datatypes/DTCal.h"
#include "../../include/datatypes/DataEmpleado.h"
#include "../../include/datatypes/DTEmpleado.h"
#include <iostream>
using namespace std;
enum CargoEmpleado {Administracion, Limpieza, Recepcion, Infraestructura};

class Empleado: public Usuario, IObserver {
	private:
		CargoEmpleado cargo;
	public:
		Empleado(string nombre, string email, string password, CargoEmpleado cargo);
		~Empleado();
		CargoEmpleado getCargoEmpleado();
		void setCargoEmpleado(CargoEmpleado cargo);
		Set(DTCal) obtenerComentarios();
		DataEmpleado getDataEmpleado();
		bool TrabajaEnHostal(Hostal);
		void AsignarEmpleadoAHostal();
		DTEmpleado getDTEmpleado();
		void notificar(Calificacion cal);
};
#endif