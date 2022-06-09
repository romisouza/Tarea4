#ifndef DTCALIFICACION
#define DTCALIFICACION
#include <string>
#include <iostream>
using namespace std;

class DTCalificacion {
	private:
		int puntaje;
		string comentarioHuesp;
		string comentarioEmp;
	public:
		DTCalificacion(int,string,string);
		int getPuntaje();
		string getComentarioHuesp();
		string getComentarioEmp();
		~DTCalificacion();
};
#endif