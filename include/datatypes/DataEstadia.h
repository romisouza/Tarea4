#ifndef DATAESTADIA
#define DATAESTADIA
#include <iostream>
#include "../../include/datatypes/DTFecha.h"
using namespace std;

class DataEstadia{
    private:
        DTFecha checkin;
        DTFecha checkout;
        std::string hostal;
        std::string huesped;
        int hab;
        int cod;
    public:
        DataEstadia();
        DataEstadia(DTFecha,DTFecha,std::string,std::string,int,int);
        DTFecha getCheckIn();
        DTFecha getCheckOut();
        std::string getHostal();
        std::string getHuesped();
        int getHabitacion();
        int getCod();
        ~DataEstadia();

};

#endif