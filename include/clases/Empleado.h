#ifndef EMPLEADO
#define EMPLEADO
#include "Usuario.h"
#include "Hostal.h"
#include "Calificacion.h"
#include <set>
#include "../../include/sistema/IObserver.h"
#include "../../include/datatypes/DTCal.h"
#include "../../include/datatypes/DataEmpleado.h"
#include "../../include/datatypes/DTEmpleado.h"
#include <iostream>
using namespace std;
class Hostal;

class Empleado: public Usuario{//, IObserver {
	private:
		Hostal* hostalAsociado;
		CargoEmpleado* cargo;
		list<Calificacion*> califObs;
	public:
		Empleado(std::string nombre, std::string email, std::string password);
		~Empleado();
		Hostal* getHostalAsociado();
		CargoEmpleado* getCargoEmpleado();
		void setHostalAsociado(Hostal*);
		void setCargoEmpleado(CargoEmpleado* cargo);
		set<DTCal> obtenerComentarios();
		DataEmpleado getDataEmpleado();
		bool TrabajaEnHostal();
		void AsignarEmpleadoAHostal(CargoEmpleado*,Hostal*);
		DTEmpleado getDTEmpleado();
		void notificar(Calificacion* cal);
};
#endif