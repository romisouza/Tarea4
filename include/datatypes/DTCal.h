#ifndef DTCAL
#define DTCAL
#include <iostream>
using namespace std;

class DTCal{
    private:
        std::string comentarioHuesp;
        std::string mailHuesp;
        int codigoRes;
    public:
        DTCal();
        DTCal(std::string,std::string,int);
        std::string getComentarioHuesp();
        std::string getMailHuesp();
        int getCodigoRes();
        ~DTCal();
        

};

#endif