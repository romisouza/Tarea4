#include "../../include/datatypes/DTCal.h"

DTCal::DTCal(){

}

DTCal::DTCal(std::string comEmp,std::string comHuesp,int codigor){
    comentarioEmp = comEmp;
    comentarioHuesp = comHuesp;
    codigoRes = codigor;
}

std::string DTCal::getComentarioEmp(){
    return comentarioEmp;
}

std::string DTCal::getComentarioHuesp(){
    return comentarioHuesp;
}

int DTCal::getCodigoRes(){
    return codigoRes;
}

DTCal::~DTCal(){
    
}