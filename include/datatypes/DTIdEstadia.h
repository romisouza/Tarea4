#ifndef DTIDESTADIA
#define DTIDESTADIA
#include <iostream>

class DTIdEstadia
{
private:
    int codigo;
    std::string email;
public:
    DTIdEstadia(int, std::string);
    int getCodigo();
    std::string getEmail();
    ~DTIdEstadia();
};

#endif
