#include "../../include/datatypes/DTCal.h"

DTCal::DTCal(){

}

DTCal::DTCal(string comEmp,string comHuesp,int codigor){
    comentarioEmp = comEmp;
    comentarioHuesp = comHuesp;
    codigoRes = codigor;
}

string DTCal::getComentarioEmp(){
    return comentarioEmp;
}

string DTCal::getComentarioHuesp(){
    return comentarioHuesp;
}

int DTCal::getCodigoRes(){
    return codigoRes;
}

DTCal::~DTCal(){
    
}