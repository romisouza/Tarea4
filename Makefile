all: principal
#cosas que no tienen archivos 
.PHONY: all clean
#directorios
Clases_CPP 	=src/clases
Clases_H	=include/clases
DT_CPP		=src/datatypes
DT_H		=include/datatypes
Sistema_CPP =src/sistema
Sistema_H	=include/sistema

CLASES_NOMBRES = Calificacion Empleado Estadia Habitacion Hostal Huesped Reserva ReservaGrupal ReservaIndividual Usuario
CLASES_O = $(CLASES_NOMBRES:%=$(Clases_CPP)/%.o)

DT_NOMBRES = DataEmpleado DataEstadia DataHostalComp DTCal DTCalificacion DTEmpleado DTEstadia DTFecha DTHabitacion DTHostal DTHostalProm DTHuesped DTIdEstadia DTReserva DTReservaComp
DT_O = $(DT_NOMBRES:%=$(DT_CPP)/%.o)

SISTEMA_NOMBRES = ControladorHostal ControladorUsuario #IHostal IObserver Fabrica IUsuario SingletonFechaHora
SISTEMA_O =$(SISTEMA_NOMBRES:%=$(Sistema_CPP)/%.o)


#Compilador 
CC = g++

#opciones de compilacion
CCFLAGS = -Wall -fPIC -pthread -I$(Clases_H) -I$(DT_H) -I$(Sistema_H) -g


principal.o: principal.cpp 
	$(CC) $(CCFLAGS) -c $< -o $@

$(Clases_CPP)/%.o: $(Clases_CPP)/%.cpp $(Clases_H)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(DT_CPP)/%.o: $(DT_CPP)/%.cpp $(DT_H)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(Sistema_CPP)/%.o: $(Sistema_CPP)/%.cpp $(Sistema_H)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@
principal: principal.o $(DT_O) $(CLASES_O) $(SISTEMA_O) 

clean:
	@rm -f principal.o $(CLASES_O) $(DT_O) $(SISTEMA_O)