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
		void setColReservasHuesp(map<int,Reserva*>);
		bool getEsFinger();
		void setEsFinger(bool finger);
		list<DTIdEstadia> BuscarEstadias(std::string email, DTFecha hrs);//cambie el nombre
		Estadia* BuscarEstadias2(DTIdEstadia);//nueva, calificr estadia
		DTHuesped getDTHuesped();
};

#endif
