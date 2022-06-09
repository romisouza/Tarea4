#ifndef DTIDESTADIA
#define DTIDESTADIA
#include <string>
#include <iostream>

class DTIdEstadia
{
private:
    int codigo;
    string email;
public:
    DTIdEstadia(int, string);
    int getCodigo();
    string getEmail();
    ~DTIdEstadia();
};

#endif
