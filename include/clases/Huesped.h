#ifndef HUESPED
#define HUESPED
#include "Usuario.h"
#include "../../include/datatypes/DTHuesped.h"
#include <iostream>
using namespace std;

class Huesped: public Usuario {
	private:
		bool esFinger;
	public:
		Huesped(std::string nom, std::string mail, std::string pass, bool finger);
		~Huesped();
		bool getEsFinger();
		void setEsFinger(bool finger);
		void BuscarEstadias(std::string email);
		DTHuesped getDTHuesped();
};

#endif
