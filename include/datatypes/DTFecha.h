#ifndef DTFECHA
#define DTFECHA
#include <iostream>

class DTFecha {
    private:
        int dia, mes, anio, hora, minutos;
    public:
        DTFecha();
        DTFecha(int d, int m, int a, int h, int min);
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinutos();
        bool compararFecha(DTFecha,DTFecha);
        ~DTFecha();
};

#endif
