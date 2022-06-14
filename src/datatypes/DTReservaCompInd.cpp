#include "../include/clases/ReservaGrupal.h"
#include "../include/clases/Reserva.h"
#include "../include/datatypes/DTFecha.h"
#include "../include/datatypes/DTReservaCompInd.h"

DTReservaCompInd::DTReservaCompInd(int codi, DTFecha CheckIn, DTFecha CheckOut,EstadoReserva est,int Num):DTReservaComp(codi,CheckIn,CheckOut,est,Num){
}
