#include "../../include/datatypes/DTReservaIndividual.h"
#include "../../include/datatypes/DTFecha.h"
#include "../../include/datatypes/DTReserva.h"
#include "../../include/clases/ReservaIndividual.h"

DTReservaIndividual::DTReservaIndividual(int codigo, DTFecha checkin, DTFecha checkout,EstadoReserva estado):DTReserva(codigo, checkin, checkout, estado){
}