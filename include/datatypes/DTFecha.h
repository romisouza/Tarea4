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
        std::string convertirFechaToString(int anio, int mes, int dia,int hora,int min); //la agregue para poder comparar fechas mas facil
        bool compararFecha(DTFecha,DTFecha);
        ~DTFecha();
};

#endif
