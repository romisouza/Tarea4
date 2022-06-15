#include <iostream>
#include <string>
#include "include/sistema/Fabrica.h"
#include "include/datatypes/DataEmpleado.h"
#include "include/datatypes/DataEstadia.h"
#include "include/datatypes/DataHostalComp.h"
#include "include/datatypes/DTCal.h"
#include "include/datatypes/DTCalificacion.h"
#include "include/datatypes/DTEmpleado.h"
#include "include/datatypes/DTEstadia.h"
#include "include/datatypes/DTFecha.h"
#include "include/datatypes/DTHabitacion.h"
#include "include/datatypes/DTHostal.h"
#include "include/datatypes/DTHostalProm.h"
#include "include/datatypes/DTHuesped.h"
#include "include/datatypes/DTIdEstadia.h"
#include "include/datatypes/DTReserva.h"
#include "include/datatypes/DTReservaGrupal.h"
#include "include/datatypes/DTReservaIndividual.h"
#include "include/datatypes/DTReservaComp.h"
#include "include/datatypes/DTReservaCompGrup.h"
#include "include/datatypes/DTReservaCompInd.h"
using namespace std;

Fabrica *fabrica = Fabrica::getInstancia();

/*void opcionNoValida(){
    cout << "===============================" << endl;
    cout << "==      OPCION INVALIDA      ==" << endl;
    cout << "===============================" << endl;
}*/

void Menu(){
    cout << "MENÚ PRINCIPAL" << endl;
    cout << "Seleccione una opción" << endl;
    cout << "=====================================" << endl;
    cout << "1 - Cargar datos de prueba" << endl;
    cout << "2 - Alta de Usuario"<< endl;
    cout << "3 - Alta de Hostal"<< endl;
    cout << "4 - Alta de Habitacion"<< endl;
    cout << "5 - Asignar Empleado a Hostal"<< endl;
    cout << "6 - Realizar Reserva"<< endl;
    cout << "7 - Consultar top 3 de hostales"<< endl;
    cout << "8 - Registrar Estadía"<< endl;
    cout << "9 - Finalizar Estadía"<< endl;
    cout << "10 - Calificar Estadía"<< endl;
    cout << "11 - Comentar Calificación"<< endl;
    cout << "12 - Consulta de Usuario"<< endl;
    cout << "13 - Consulta de Hostal"<< endl;
    cout << "14 - Consulta de Reserva"<< endl;
    cout << "15 - Consulta de Estadía"<< endl;
    cout << "16 - Baja de Reserva"<< endl;
    cout << "17 - Modificar fecha del sistema"<< endl;
    cout << "18 - Suscribirse a Notificaciones"<< endl;
    cout << "19 - Consulta de Notificaciones"<< endl;
    cout << "20 - Eliminar suscripción"<< endl;
    cout << "21 - SALIR" << endl;
    cout << "- Ingrese su opción -" << endl;
}

void cargarDatosPrueba(){}

void altaUsuario(){
   /* IUsuario* ctrlUsuario = fabrica->obtenerControladorUsuario();
    cout << "Ingrese 0 si va a ingresar un Huesped y 1 si va a ingresar un Empleado: ";
    bool TipoUsuario;
    cin >> TipoUsuario;
    ctrlUsuario->setTipoUsuario(TipoUsuario);
    if (TipoUsuario == 0) {
        cout << "Ingrese el nombre del huesped: " << "\n"<< endl;
        std::string nombre;
        cin >> nombre;
        cout << "Ingrese el email del huesped: " << "\n"<< endl;
        std::string email;
        cin >> email;
        cout << "Ingrese la contraseña del huesped: " << "\n"<< endl;
        std::string password;
        cin >> password;
        cout << "Ingrese 1 si el huesped es finger y 0 en caso contrario: " << "\n"<< endl;
        //¿TENGO QUE VERIFICAR QUE INGRESO 0 o 1 Y NO CUALQ COSA?
        bool esfinger;
        cin >> esfinger; 
        ctrlUsuario->IngresarHuesped(nombre,email,password,esfinger);
        cout << "¿Desea confirmar el alta del Huesped? Si es así ingrese 1, de lo contrario ingrese 0: "<< "\n"<< endl;
        //¿TENGO QUE VERIFICAR QUE INGRESO 0 o 1 Y NO CUALQ COSA?
        bool confirmar;
        cin >> confirmar;
        if (confirmar == 1)
	        ctrlUsuario->ConfirmarAltaUsuario();
        else
            ctrlUsuario->CancelarAltaUsuario();
    }
    else {
        cout << "Ingrese el nombre del empleado: " << "\n"<< endl;
        std::string nombre;
        cin >> nombre;
        cout << "Ingrese el email del empleado: " << "\n"<< endl;
        std::string email;
        cin >> email;
        cout << "Ingrese la contraseña del empleado: " << "\n"<< endl;
        std::string password;
        cin >> password;
        ctrlUsuario->IngresarEmpleado(nombre,email,password,esfinger);
        cout << "¿Desea confirmar el alta del Huesped? Si es así ingrese 1, de lo contrario ingrese 0: "<< "\n"<< endl;
        bool confirmar;
        cin >> confirmar;
        if (confirmar == 1)
	        ctrlUsuario->ConfirmarAltaUsuario();
        else
            ctrlUsuario->CancelarAltaUsuario();
    }

    */
}

void altaHostal(){
}

void altaHabitacion(){}

void asignarEmpleadoAHostal(){}

void realizarReserva(){}

void consultarTop3Hostales(){}

void registrarEstadia(){}

void finalizarEstadia(){}

void calificarEstadia(){}

void comentarCalificacion(){}

void consultaUsuario(){}

void consultaHostal(){}

void consultaReserva(){}

void consultaEstadia(){}

void bajaReserva(){}

void modificarFechaSistema(){}

void SuscribirseaNotificaciones(){}

void ConsultaDeNotificaciones(){}

void EliminarSuscripcion(){}

int main(){
    int opcionMenu = 0;
    while (opcionMenu != 21){
        Menu();
        cin >> opcionMenu;
        switch (opcionMenu)
        {case 1: cargarDatosPrueba();
        break;
        case 2: altaUsuario();
        break;
        case 3: altaHostal();
        break;
        case 4: altaHabitacion();
        break;
        case 5: asignarEmpleadoAHostal();
        break;
        case 6: realizarReserva();
        break;
        case 7: consultarTop3Hostales();
        break;
        case 8: registrarEstadia();
        break;
        case 9: finalizarEstadia();
        break;
        case 10: calificarEstadia();
        break;
        case 11: comentarCalificacion();
        break;
        case 12: consultaUsuario();
        break;
        case 13: consultaHostal();
        break;
        case 14: consultaReserva();
        break;
        case 15: consultaEstadia();
        break;
        case 16: bajaReserva();
        break;
        case 17: modificarFechaSistema();
        break;
        case 18: SuscribirseaNotificaciones();
        break;
        case 19: ConsultaDeNotificaciones();
        break;
        case 20: EliminarSuscripcion();
        break;
        case 21: opcionMenu = 21;
        break;
        default:
            break;
        }
    }
    return 0;
}