#ifndef DTHABITACION
#define DTHABITACION
#include <iostream>
using namespace std;

class DTHabitacion {
	private:
		int numero;
		float precioNoche;
		int capacidad;
	public:
		DTHabitacion();
		DTHabitacion(int,float,int);
		int getNumero();
		float getPrecioNoche();
		int getCapacidad();
		~DTHabitacion();
};
#endif