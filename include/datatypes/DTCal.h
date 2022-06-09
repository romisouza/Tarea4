#ifndef DTCAL
#define DTCAL
#include <iostream>
using namespace std;

class DTCal{
    private:
        std::string comentarioEmp;
        std::string comentarioHuesp;
        int codigoRes;
    public:
        DTCal();
        DTCal(std::string,std::string,int);
        std::string getComentarioEmp();
        std::string getComentarioHuesp();
        int getCodigoRes();
        ~DTCal();
        

};

#endif