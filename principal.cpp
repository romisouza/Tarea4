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
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    string nombre,direccion,telefono;
    cout << "Ingrese el nombre del hostal: ";
    getline(cin >> ws, nombre);
    cout << "Ingrese la direccion del hostal: ";
    getline(cin >> ws, direccion);
    cout << "Ingrese el telefono del hostal: ";
    getline(cin >> ws, telefono);
    ctrlHostal->agregarHostal(nombre,direccion,telefono);
}

void altaHabitacion(){}

void asignarEmpleadoAHostal(){}

void realizarReserva(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<DTHostalProm> hostalesRegistrados = ctrlHostal->ObtenerHostalesProm();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=hostalesRegistrados.begin();it!=hostalesRegistrados.end();++it){
        cout << "Nombre del hostal: " << (*it).getNombre() << endl;
        cout << "Direccion del hostal: " << (*it).getDireccion() << endl;
        cout << "Calificaciones promedio del hostal: " << (*it).getCalificacionesPromedio() << endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: ";
    getline(cin >> ws, nombreHostal);
    int dia_in,mes_in,anio_in,hora_in,min_in,dia_out,mes_out,anio_out,hora_out,min_out;
    cout << "Ingrese el dia de entrada: ";
    cin >> dia_in;
    cout << "Ingrese el mes de entrada: ";
    cin >> mes_in;
    cout << "Ingrese el año de entrada: ";
    cin >> anio_in;
    cout << "Ingrese la hora de entrada: ";
    cin >> hora_in;
    cout << "Ingrese los minutos de entrada: ";
    cin >> min_in;
    if (dia_in < 1 || dia_in>31 || mes_in<1 || mes_in>12 || hora_in<1 || hora_in>24 || min_in<0 || min_in>59) {
        throw std::invalid_argument("La fecha/hora ingresada no es correcta.");
    }
    DTFecha in = DTFecha(dia_in,mes_in,anio_in,hora_in,min_in);
    cout << "Ingrese el dia de salida: ";
    cin >> dia_out;
    cout << "Ingrese el mes de salida: ";
    cin >> mes_out;
    cout << "Ingrese el año de salida: ";
    cin >> anio_out;
    cout << "Ingrese la hora de salida: ";
    cin >> hora_out;
    cout << "Ingrese los minutos de salida: ";
    cin >> min_out;
    if (dia_out < 1 || dia_out>31 || mes_out<1 || mes_out>12 || hora_out<1 || hora_out>24 || min_out<0 || min_out>59) {
        throw std::invalid_argument("La fecha/hora ingresada no es correcta.");
    }
    DTFecha out = DTFecha(dia_out,mes_out,anio_out,hora_out,min_out);
    bool grupOind;
    cout << "Ingrese 1 si la reserva es grupal, y 0 si es individual: ";
    cin >> grupOind;
    int totalHuesp;
    if (grupOind==1){
        cout << "Ingrese la cantidad de huespedes que se quedaran con usted (incluyendose): ";
        cin >> totalHuesp;
    } else {
        totalHuesp=1;
    }
    ctrlHostal->ingresarDatosReserva(nombreHostal,in,out,grupOind,totalHuesp);
    cout << "Las habitaciones disponibles en esas fechas son: ";
    list<int> ColHabDisp = ctrlHostal->obtenerHabitacionesDisponibles(in,out); //aca controlo q las q devuelvo sean para la capacidad d los huespedes q pidio
    for (auto it=ColHabDisp.begin();it!=ColHabDisp.end();++it){
        cout << *it << endl;
        }
    cout << "Ingrese el numero de la habitacion elegida: ";
    int numHab;
    cin >> numHab;
    ctrlHostal->seleccionarHabitacion(numHab);
    cout << "Los mail de los huespedes registrados en el sistema son:" <<  endl;
    list<string> mailHuespedes = ctrlHostal->obtenerHuespedesRegistrados();
    for (auto it=mailHuespedes.begin();it!=mailHuespedes.end();++it){
        cout << *it << endl;
    }
    cout << "Ingrese el mail del huesped que realiza la reserva: ";
    string mailHuesp;
    getline(cin >> ws, mailHuesp);
    if (grupOind == 1){
        for(int i=1;i<totalHuesp;i++){
            cout << "Ingrese el mail del acompañante " << i << ": ";
            string mailAcompaniante;
            getline(cin >> ws, mailAcompaniante);
            ctrlHostal->seleccionarAcompaniante(mailAcompaniante);
        }
    }
    cout << "Ingrese 1 para confirmar la reserva o 0 para cancelarla: ";
    bool opcionIngresada;
    cin >> opcionIngresada;
    if (opcionIngresada==1){
        ctrlHostal->confirmarAltaReserva();
        cout << "Reserva realizada con exito.";
    } else {
        ctrlHostal->cancelarAltaReserva();
        cout << "Reserva cancelada con exito.";
    }
}

void consultarTop3Hostales(){}

void registrarEstadia(){}

void finalizarEstadia(){}

void calificarEstadia(){}

void comentarCalificacion(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    cout << "Ingrese el mail de un empleado: ";
    string mailEmp;
    getline(cin >> ws, mailEmp);
    list<DTCal> comentarios = ctrlHostal->ObtenerComentariosAResponder(mailEmp);
    for (auto it=comentarios.begin();it!=comentarios.end();++it){
        cout << "Comentario del huesped: " << (*it).getComentarioHuesp();
        cout << "Mail del huesped: " << (*it).getMailHuesp();
        cout << "Codigo de la reserva asociada: " << (*it).getCodigoRes();
    }
    cout << "Ingrese el mail del huesped del cual desea responder un comentario: ";
    string mailHuesp,respuesta;
    int codigoRes;
    getline(cin >> ws, mailHuesp);
    cout << "Ingrese el codigo de la reserva asociada: ";
    cin >> codigoRes;
    cout << "Ingrese su respuesta: ";
    getline(cin >> ws, respuesta);
    ctrlHostal->ResponderComentario(mailHuesp,codigoRes,respuesta);
    cout << "Respuesta cargada con exito.";
}

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