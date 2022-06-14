#ifndef HUESPED
#define HUESPED
#include "Usuario.h"
#include "Reserva.h"
#include "../../include/datatypes/DTHuesped.h"
#include "../../include/datatypes/DTIdEstadia.h"
#include <iostream>
#include <map>
#include <list>
using namespace std;
class Reserva;
class Estadia;

class Huesped: public Usuario {
	private:
		bool esFinger;
		map<int,Reserva*> ColReservasHuesp; 
	public:
		Huesped(std::string nom, std::string mail, std::string pass, bool finger);
		~Huesped();
		map<int,Reserva*> getColReservasHuesp();
		bool getEsFinger();
		void setEsFinger(bool finger);
		list<Estadia*> BuscarEstadias(std::string email, DTFecha hrs);//cambie el nombre
		DTHuesped getDTHuesped();
};

#endif
