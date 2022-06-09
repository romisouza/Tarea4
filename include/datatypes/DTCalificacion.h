#ifndef DTCALIFICACION
#define DTCALIFICACION
#include <iostream>
using namespace std;

class DTCalificacion {
	private:
		int puntaje;
		std::string comentarioHuesp;
		std::string comentarioEmp;
	public:
		DTCalificacion(int,std::string,std::string);
		int getPuntaje();
		std::string getComentarioHuesp();
		std::string getComentarioEmp();
		~DTCalificacion();
};
#endif