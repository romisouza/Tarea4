#ifndef DATAESTADIA
#define DATAESTADIA
#include <iostream>
#include <string>
#include "../../include/datatypes/DTFecha.h"
using namespace std;

class DataEstadia{
    private:
        DTFecha checkin;
        DTFecha checkout;
        string hostal;
        string huesped;
        int hab;
        int promo;
        int cod;
    public:
        DataEstadia();
        DataEstadia(DTFecha,DTFecha,string,string,int,int,int);
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        string getHostal();
        string getHuesped();
        int getHabitacion();
        int getPromo();
        int getCod();
        ~DataEstadia();

};

#endif