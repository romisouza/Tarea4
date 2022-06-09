#ifndef DTHUESPED
#define DTHUESPED
#include <iostream>
using namespace std;


class DTHuesped{
    private:
        std::string nombre;
        std::string email;
        bool esFinger;
    public:
        DTHuesped();
        DTHuesped(std::string, std::string, bool);
        std::string getNombre();
        std::string getMail();
        bool getEsFinger();
        ~DTHuesped();
};

#endif