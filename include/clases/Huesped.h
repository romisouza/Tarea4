#ifndef HUESPED
#define HUESPED
#include "Usuario.h"
#include "Reserva.h"
#include "../../include/datatypes/DTHuesped.h"
#include <iostream>
#include <map>
using namespace std;
class Reserva;

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
		void BuscarEstadias(std::string email);
		DTHuesped getDTHuesped();
};

#endif
