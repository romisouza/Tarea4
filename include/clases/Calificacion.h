#ifndef CALIFICACION
#define CALIFICACION
#include <string>
#include <iostream>
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTCalificacion.h"
#include "../../include/clases/Estadia.h"
using namespace std;

class Calificacion{
    private:
        DTFecha fecha;
        int puntaje;
        string comentarioHuesp;
        string comentarioEmp;
        Estadia* estadia;
    public:
        Calificacion();
        Calificacion(DTFecha, int, string, string, Estadia*);
        DTFecha getFecha();
        int getPuntaje();
        string getComentarioHuesp();
        string getComentarioEmp();
        Estadia* getEstadia();
        void setFecha(DTFecha);
        void setPuntaje(int);
        void setComentarioHuesp(string);
        void setComentarioEmp(string);
        void setEstadia(Estadia*);
        int ActualizarProm(int);
        DTCalificacion getDTCalificacion();
        ~Calificacion();
};

#endif