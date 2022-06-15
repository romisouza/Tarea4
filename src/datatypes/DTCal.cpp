#include "../../include/datatypes/DTCal.h"

DTCal::DTCal(){

}

DTCal::DTCal(std::string comHuesp,std::string mailHuesp,int codigor){
    comentarioHuesp = comHuesp;
    comentarioHuesp = comHuesp;
    codigoRes = codigor;
}

std::string DTCal::getComentarioHuesp(){
    return comentarioHuesp;
}

std::string DTCal::getMailHuesp(){
    return mailHuesp;
}

int DTCal::getCodigoRes(){
    return codigoRes;
}

DTCal::~DTCal(){
    
}