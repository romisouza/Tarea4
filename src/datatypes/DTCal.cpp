#include "../../include/datatypes/DTCal.h"

DTCal::DTCal(){

}

DTCal::DTCal(std::string comHuesp,std::string mail,int codigor){
    comentarioHuesp = comHuesp;
    mailHuesp = mail;
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
