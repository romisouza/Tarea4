#ifndef DTHUESPED
#define DTHUESPED
#include <iostream>
#include <string>
using namespace std;


class DTHuesped{
    private:
        string nombre;
        string email;
        bool esFinger;
    public:
        DTHuesped();
        DTHuesped(string, string, bool);
        string getNombre();
        string getMail();
        bool getEsFinger();
        ~DTHuesped();
};

#endif