#ifndef DTCAL
#define DTCAL
#include <iostream>
#include <string>
using namespace std;

class DTCal{
    private:
        string comentarioEmp;
        string comentarioHuesp;
        int codigoRes;
    public:
        DTCal();
        DTCal(string,string,int);
        string getComentarioEmp();
        string getComentarioHuesp();
        int getCodigoRes();
        ~DTCal();
        

};

#endif