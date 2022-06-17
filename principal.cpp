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

void cargarDatosPrueba(){
    IUsuario* ctrlUsuario = fabrica->obtenerControladorUsuario();
    IHostal* ctrlHostal = fabrica->obtenerControladorHostal();
    //Ingreso los huespedes al sistema
    ctrlUsuario->IngresarHuesped("Sofia","sofia@mail.com","123",1);
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarHuesped("Frodo","frodo@mail.com","123",1);
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarHuesped("Sam","sam@mail.com","123",0);
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarHuesped("Merry","merry@mail.com","123",0);
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarHuesped("Pippin","pippin@mail.com","123",0);
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarHuesped("Seba","seba@mail.com","123",1);
    ctrlUsuario->ConfirmarAltaUsuario();
    //Ingreso los empleados al sistema
    ctrlUsuario->IngresarEmpleado("Emilia","emilia@mail.com","123");
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarEmpleado("Leonardo","leo@mail.com","123");
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarEmpleado("Alina","alina@mail.com","123");
    ctrlUsuario->ConfirmarAltaUsuario();
    ctrlUsuario->IngresarEmpleado("Barliman","barli@mail.com","123");
    ctrlUsuario->ConfirmarAltaUsuario();
    //Ingreso los hostales al sistema
    ctrlHostal->agregarHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");
    ctrlHostal->agregarHostal("Mochileros", "Rambla Costanera 333, Rocha", "42579512");
    ctrlHostal->agregarHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
    ctrlHostal->agregarHostal("Altos de Fing", "Av del Toro 1424", "099892992");
    ctrlHostal->agregarHostal("Caverna Lujosa", "Amaya 2515", "233233235");
    //Ingreso las habitaciones 
    ctrlHostal->asignarHab("La posada del finger",1,40,2);
    ctrlHostal->registrarHab();
    ctrlHostal->asignarHab("La posada del finger",2,10,7);
    ctrlHostal->registrarHab();
    ctrlHostal->asignarHab("La posada del finger",3,30,3);
    ctrlHostal->registrarHab();
    ctrlHostal->asignarHab("La posada del finger",4,5,12);
    ctrlHostal->registrarHab();
    ctrlHostal->asignarHab("Caverna Lujosa",1,3,2);
    ctrlHostal->registrarHab();
    ctrlHostal->asignarHab("El Pony Pisador",1,9,5);
    ctrlHostal->registrarHab();
    //Asigno los empleados a los hostales
    list<DTEmpleado> HostalSeleccionado;
    CargoEmpleado* cargo;
    HostalSeleccionado = ctrlHostal->ObtenerEmpleados("La posada del finger");
    cargo= new CargoEmpleado(Recepcion);
    ctrlHostal->SeleccionarEmpleado(cargo,"emilia@mail.com");
    ctrlHostal->ConfirmarAsignacionDeEmpleado();
    HostalSeleccionado = ctrlHostal->ObtenerEmpleados("Mochileros");
    cargo= new CargoEmpleado(Recepcion);
    ctrlHostal->SeleccionarEmpleado(cargo,"leo@mail.com");
    ctrlHostal->ConfirmarAsignacionDeEmpleado();
    HostalSeleccionado = ctrlHostal->ObtenerEmpleados("Mochileros");
    cargo= new CargoEmpleado(Administracion);
    ctrlHostal->SeleccionarEmpleado(cargo,"alina@mail.com");
    ctrlHostal->ConfirmarAsignacionDeEmpleado(); 
    HostalSeleccionado = ctrlHostal->ObtenerEmpleados("El Pony Pisador");
    cargo= new CargoEmpleado(Recepcion);
    ctrlHostal->SeleccionarEmpleado(cargo,"alina@mail.com");
    ctrlHostal->ConfirmarAsignacionDeEmpleado(); 
    //Realizo las reservas
    DTFecha in,out;
    in = DTFecha(1,5,2022,14,00);
     out = DTFecha(10,5,2022,10,00);
    ctrlHostal->ingresarDatosReserva("La posada del finger",in,out,0,1);
    ctrlHostal->seleccionarHabitacion(1);
    ctrlHostal->seleccionarHuesped("sofia@mail.com");
    ctrlHostal->confirmarAltaReserva();
    in = DTFecha(4,1,2001,20,00);
    out = DTFecha(5,1,2001,2,00);
    ctrlHostal->ingresarDatosReserva("El Pony Pisador",in,out,1,4);
    ctrlHostal->seleccionarHabitacion(1);
    ctrlHostal->seleccionarHuesped("frodo@mail.com");
    ctrlHostal->seleccionarAcompaniante("sam@mail.com");
    ctrlHostal->seleccionarAcompaniante("merry@mail.com");
    ctrlHostal->seleccionarAcompaniante("pippin@mail.com");
    ctrlHostal->confirmarAltaReserva();
    in = DTFecha(7,6,2022,14,00);
    out = DTFecha(30,6,2022,11,00);
    ctrlHostal->ingresarDatosReserva("La posada del finger",in,out,0,1);
    ctrlHostal->seleccionarHabitacion(3);
    ctrlHostal->seleccionarHuesped("sofia@mail.com");
    ctrlHostal->confirmarAltaReserva();
    in = DTFecha(10,6,2022,14,00);
    out = DTFecha(30,6,2022,11,00);
    ctrlHostal->ingresarDatosReserva("Caverna Lujosa",in,out,0,1);
    ctrlHostal->seleccionarHabitacion(1);
    ctrlHostal->seleccionarHuesped("seba@mail.com");
    ctrlHostal->confirmarAltaReserva();
    //Estadias
    set<DTReserva*> reservasNC;
    DTFecha checkin;

    reservasNC = ctrlHostal->ObtenerReservasNC("La posada del finger","sofi@mail.com",0);
    int codigo1;
    auto it1=reservasNC.begin();
    checkin =DTFecha(1,5,2022,18,00);
    while ((codigo1!=0) && (it1!=reservasNC.end())){
        if(((*it1)->getCheckIn().compararFecha((*it1)->getCheckIn(),checkin)) && ((*it1)->getCheckOut().compararFecha(checkin,(*it1)->getCheckOut()))){
                codigo1=(*it1)->getCodigo();
        }
        ++it1;
    }
    ctrlHostal->ReservaNCElegida(codigo1);

    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","frodo@mail.com");
    int codigo2;
    auto it2=reservasNC.begin();
    checkin=DTFecha(4,1,2001,21,00);
    while ((codigo2!=0) && (it2!=reservasNC.end())){
        if(((*it2)->getCheckIn().compararFecha((*it2)->getCheckIn(),checkin)) && ((*it2)->getCheckOut().compararFecha(checkin,(*it2)->getCheckOut()))){
                codigo2=(*it2)->getCodigo();
        }
        ++it2;
    }
    ctrlHostal->ReservaNCElegida(codigo2);

    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","sam@mail.com");
    int codigo3;
    auto it3=reservasNC.begin();
    checkin=DTFecha(4,1,2001,21,00);
    while ((codigo3!=0) && (it3!=reservasNC.end())){
        if(((*it3)->getCheckIn().compararFecha((*it3)->getCheckIn(),checkin)) && ((*it3)->getCheckOut().compararFecha(checkin,(*it3)->getCheckOut()))){
                codigo3=(*it3)->getCodigo();
        }
        ++it3;
    }
    ctrlHostal->ReservaNCElegida(codigo3);

    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","merry@mail.com");
    int codigo4;
    auto it4=reservasNC.begin();
    checkin=DTFecha(4,1,2001,21,00);
    while ((codigo4!=0) && (it4!=reservasNC.end())){
        if(((*it4)->getCheckIn().compararFecha((*it4)->getCheckIn(),checkin)) && ((*it4)->getCheckOut().compararFecha(checkin,(*it4)->getCheckOut()))){
                codigo4=(*it4)->getCodigo();
        }
        ++it4;
    }
    ctrlHostal->ReservaNCElegida(codigo4);

    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","pippin@mail.com");
    int codigo5;
    auto it5=reservasNC.begin();
    checkin=DTFecha(4,1,2001,21,00);
    while ((codigo5!=0) && (it5!=reservasNC.end())){
        if(((*it5)->getCheckIn().compararFecha((*it5)->getCheckIn(),checkin)) && ((*it5)->getCheckOut().compararFecha(checkin,(*it5)->getCheckOut()))){
                codigo5=(*it5)->getCodigo();
        }
        ++it5;
    }
    ctrlHostal->ReservaNCElegida(codigo5);

    reservasNC = ctrlHostal->ObtenerReservasNC("Caverna Lujosa","seba@mail.com");
    int codigo6;
    auto it6=reservasNC.begin();
    checkin=DTFecha(7,6,2022,18,00);
    while ((codigo6!=0) && (it6!=reservasNC.end())){
        if(((*it6)->getCheckIn().compararFecha((*it6)->getCheckIn(),checkin)) && ((*it6)->getCheckOut().compararFecha(checkin,(*it6)->getCheckOut()))){
                codigo6=(*it6)->getCodigo();
        }
        ++it6;
    }
    ctrlHostal->ReservaNCElegida(codigo6);

    //Finalizacion de estadias
    ctrlHostal->DatosHuesped("La posada del finger", "sofia@mail.com");
    ctrlHostal->DatosHuesped("El Pony Pisador", "frodo@mail.com");
    ctrlHostal->DatosHuesped("Caverna Lujosa", "seba@mail.com");
    //calificar estadia

}

void altaUsuario(){
    IUsuario* ctrlUsuario = fabrica->obtenerControladorUsuario();
    cout << "Ingrese 0 si va a ingresar un Huesped y 1 si va a ingresar un Empleado: ";
    bool TipoUsuario;
    cin >> TipoUsuario;
    ctrlUsuario->setTipoUsuario(TipoUsuario);
    if (TipoUsuario == 0) {
        cout << "Ingrese el nombre del huesped: " << endl;
        std::string nombre;
        getline(cin >> ws, nombre);
        cout << "Ingrese el email del huesped: " << endl;
        std::string email;
        getline(cin >> ws, email);
        cout << "Ingrese la contraseña del huesped: " << endl;
        std::string password;
        getline(cin >> ws, password);
        cout << "Ingrese 1 si el huesped es finger y 0 en caso contrario: " << endl;
        bool esfinger;
        cin >> esfinger; 
        ctrlUsuario->IngresarHuesped(nombre,email,password,esfinger);
        cout << "¿Desea confirmar el alta del Huesped? Si es así ingrese 1, de lo contrario ingrese 0: "<< endl;
        bool confirmar;
        cin >> confirmar;
        if (confirmar == 1){
	        ctrlUsuario->ConfirmarAltaUsuario();
            cout << "Huesped ingresado con exito."<<endl;
        }else {
            ctrlUsuario->CancelarAltaUsuario();
            cout << "Huesped cancelado con exito."<<endl;
        }
    }
    else {
        cout << "Ingrese el nombre del empleado: " <<endl;
        std::string nombre;
        getline(cin >> ws, nombre);
        cout << "Ingrese el email del empleado: " << endl;
        std::string email;
        getline(cin >> ws, email);
        cout << "Ingrese la contraseña del empleado: " << endl;
        std::string password;
        getline(cin >> ws, password);
        ctrlUsuario->IngresarEmpleado(nombre,email,password);
        cout << "¿Desea confirmar el alta del Empleado? Si es así ingrese 1, de lo contrario ingrese 0: "<< endl;
        bool confirmar;
        cin >> confirmar;
        if (confirmar == 1){
	        ctrlUsuario->ConfirmarAltaUsuario();
            cout << "Empleado ingresado con exito."<<endl;
        }else {
            ctrlUsuario->CancelarAltaUsuario();
            cout << "Empleado cancelado con exito."<<endl;
        }
    }
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

void altaHabitacion(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "Nombre del hostal: " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    int num;
    cout << "Ingrese el numero de habitación: "<<endl;
    cin>> num;
    float precio;
    cout << "Ingrese el precio de dicha habitación: "<<endl;
    cin>> precio;
    int capacidad;
    cout << "Ingrese la capacidad de dicha habitación: "<<endl;
    cin>> capacidad;
    //muestro algo antes de preguntar si confirma o cancela?
    ctrlHostal->asignarHab(nombreHostal,num, precio, capacidad);
    cout << "Ingrese 1 para asignar la habitación o 0 para cancelarla: ";
    bool cual;
    cin >> cual;
    if (cual==1){
        ctrlHostal->registrarHab();
        cout << "Habitación asignada con exito.";
    } else {
        ctrlHostal->cancelarAltaHabitacion();
        cout << "Habitación no asignada.";
    }
}

void asignarEmpleadoAHostal(){
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
    list<DTEmpleado> empleadosRegistrados = ctrlHostal->ObtenerEmpleados(nombreHostal);
    cout << "Los empleados registrados en el sistema sin cargo son:" << endl;
    for (auto it=empleadosRegistrados.begin();it!=empleadosRegistrados.end();++it){
        cout << "Nombre del empleado: " << (*it).getNombre() << endl;
        cout << "Email del empleado: " << (*it).getEmail() << endl;
    }
    string mailEmp;
    int cargo;    
    cout << "Ingrese el email del empleado elegido: ";
    getline(cin >> ws, mailEmp);
    cout << "'1' para asignar el cargo Administracion" << endl;
    cout << "'2' para asignar el cargo Limpieza" << endl;
    cout << "'3' para asignar el cargo Recepcion" << endl;
    cout << "'4' para asignar el cargo Infraestructura" << endl;
    cout << "Ingrese el numero del cargo a ejercer por el empleado elegido: ";
    cin >> cargo;
    CargoEmpleado* cargo1;
        switch(cargo){
        case 1: cargo1= new CargoEmpleado(Administracion);
        break;
        case 2: cargo1= new CargoEmpleado(Limpieza);
        break;
        case 3: cargo1= new CargoEmpleado(Recepcion);;
        break;
        case 4: cargo1= new CargoEmpleado(Infraestructura);
        break;
        default: throw std::invalid_argument("El numero ingresado no es correcto, ingrese nuevamente: ");
    }    
    ctrlHostal->SeleccionarEmpleado(cargo1,mailEmp);
    cout << "Ingrese 1 para confirmar la asignacion o 0 para cancelarla: ";
    bool opcionIngresada;
    cin >> opcionIngresada;
    if (opcionIngresada==1){
        ctrlHostal->ConfirmarAsignacionDeEmpleado();
        cout << "Asignacion realizada con exito.";
    } else {
        ctrlHostal->CancelarAsignacionDeEmpleado();
        cout << "Asignacion cancelada con exito.";
    }

}

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
    list<int> ColHabDisp = ctrlHostal->obtenerHabitacionesDisponibles(in,out,totalHuesp); //aca controlo q las q devuelvo sean para la capacidad d los huespedes q pidio
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
    ctrlHostal->seleccionarHuesped(mailHuesp);
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

void consultarTop3Hostales(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<std::string> ranking;
    ranking = ctrlHostal->ConsultarTop3Hostal();
    cout << "Los hostales registrados en el sistema con mayor promedio de puntaje son:" << endl;
    int i=1;
    auto it=ranking.begin();
    while(it != ranking.end()){
        cout << i << "." <<(*it) << endl;
        i++;
        ++it;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: ";
    getline(cin >> ws, nombreHostal);
    list<DTCalificacion> empleados = ctrlHostal->ObtenerCalificaciones(nombreHostal);
    cout << "Calificaciones y comentarios del hostal:" << endl;
    for (auto it=empleados.begin();it!=empleados.end();++it){
        cout << "Puntaje: " << (*it).getPuntaje() << endl;
        cout << "Comentario huesped: " << (*it).getComentarioHuesp() << endl;
        if((*it).getComentarioEmp()!=""){
          cout << "Comentario empleado: " << (*it).getComentarioEmp() << endl;  
        }
    }
    
}

void registrarEstadia(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "Nombre del hostal: " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    std::string email;
    cout << "Ingrese el email del huesped: "<< endl;
    cin >> email;
    set<DTReserva*> reservasNC = ctrlHostal->ObtenerReservasNC(nombreHostal, email); //deevolver solo el codigo
    cout << "Los reservas no canceladas en el sistema son:" << endl;
    auto it=reservasNC.begin();
    for (auto it=reservasNC.begin();it!=reservasNC.end();++it){
        DTReservaIndividual* ind = dynamic_cast<DTReservaIndividual*>((*it));
        if(ind!=NULL){
            cout << (ind)->getCodigo() << endl;
        }else{
               DTReservaGrupal* ind = dynamic_cast<DTReservaGrupal*>((*it));
        cout << (ind)->getCodigo() << endl; //ver que mas mostrar
        }
    }
    int codigo;
    cout << "Ingresar el codigo de la reserva no cancelada elegida:" << endl;
    cin >>codigo;
    ctrlHostal->ReservaNCElegida(codigo);
}

void finalizarEstadia(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "Nombre del hostal: " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    std::string email;
    cout << "Ingrese el email del huesped: "<< endl;
    cin >> email;
    ctrlHostal->DatosHuesped(nombreHostal, email);
}

void calificarEstadia(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "Nombre del hostal: " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    cout << "Ingrese el mail del huesped: "<<endl;
    string mailHsp;
    getline(cin >> ws, mailHsp);
    list<DTIdEstadia> lista=ctrlHostal->ListaEstadiasFinalizadas(mailHsp);
    if(lista.empty()){
        throw std::invalid_argument("No existen estadias finalizadas");
    }
    cout<< "Las estadias finalizadas son:"<<endl;
    for(auto it=lista.begin();it!=lista.end();it++){
        cout<< "El codigo de la reserva es:"<< (*it).getCodigo()<<endl;
    }
    int codRes;
    cout<< "Ingrese codigo de la reserva elegida:"<<endl;
    cin>> codRes;
    auto it=lista.begin();
    while((*it).getCodigo()!=codRes){
        it++;
    }
    ctrlHostal->SeleccionarEstadia((*it));
    int Puntaje;
    cout<< "Ingrese puntaje de la calificacion:"<<endl;
    cin>> Puntaje;
    string comentario;
    cout<< "Igrese comentario de la calificacion:"<<endl;
    getline(cin >> ws, comentario);
    ctrlHostal->ConfirmarCalificacion(comentario,Puntaje);

}

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

void consultaUsuario(){
    IUsuario* ctrlUsuario = fabrica->obtenerControladorUsuario();
    set<string> Usuarios = ctrlUsuario->ObtenerUsuarios();
    cout << "Los usuarios registrados en el sistema son: "<<endl;
    for (set<string>::iterator i = Usuarios.begin(); i != Usuarios.end(); i++){
        cout << *i << "\n" <<endl;
    }
    cout <<"Si desea consultar la informacion de un huesped ingrese 0, si quiere la informacion de un empleado ingrese 1: "<<endl;
    bool tipoUser;
    cin >> tipoUser;
    if (!tipoUser) {
        cout << "Ingrese el email correspondiente al huesped cuya informacion quiere consultar: " <<endl;
        std::string email;
        getline(cin >> ws, email);
        DTHuesped* Huesped = ctrlUsuario->SeleccionarHuesped(email);
        cout << "__Información del huesped seleccionado__"<<endl;
        cout << "Nombre: "<< Huesped->getNombre()  <<endl;
        cout << "Email: " << Huesped->getMail()  <<endl;
        bool esfing = Huesped->getEsFinger();
        if (esfing)
            cout << "Es finger" << endl;
        else    
            cout << "No es finger" <<endl;
    }
    else {
        cout << "Ingrese el email correspondiente al empleado cuya informacion quiere consultar: "<<endl;
        std::string email;
        getline(cin >> ws, email);
        DataEmpleado* Empleado = ctrlUsuario->SeleccionarEmpleado2(email);
        cout << "__Información del empleado seleccionado__"<<endl;
        cout << "Nombre: "<< Empleado->getNombre()  <<endl;
        cout << "Email: " << Empleado->getEmail()  <<endl;
        CargoEmpleado* cargo = Empleado->getCargo();
    	switch(*cargo) {
        case 0: cout << "El cargo del empleado es: Administracion"<<endl; 
        break;
        case 1: cout << "El cargo del empleado es: Limpieza"<<endl; 
        break;
        case 2: cout << "El cargo del empleado es: Recepcion"<<endl;
        break;
        case 3: cout << "El cargo del empleado es: Infraestructura"<<endl;
        break;
        default:
            break;
        }
        cout << "El empleado trabaja en el Hostal: " << Empleado->getHostal() << endl;  
    }

}

void consultaHostal(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "Nombre del hostal: " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    DataHostalComp Hst=ctrlHostal->ObtenerHostalComp(nombreHostal);
    cout<< "Nombre del hostal:"<< Hst.getNombre()<<endl;
    cout<< "Direccion del hostal:"<< Hst.getDireccion()<<endl;
    cout<< "Telefono del hostal:"<< Hst.getTelefono()<<endl;
    cout<< "Promedio del hostal:"<< Hst.getNombre()<<endl;
    cout<< "Habitaciones del hostal:"<<endl;
    for(auto it=Hst.getHabitaciones().begin();it!=Hst.getHabitaciones().end();it++){
        cout<< "Numero de la habitacion:"<< (*it).second->getNumero()<<endl;
        cout<< "Capacidad de la habitacion:"<< (*it).second->getCapacidad()<<endl;
        cout<< "Precio de la habitacion :"<< (*it).second->getPrecioNoche()<<endl;
    }
    cout<< "Reservas del hostal:";
    for(auto it=Hst.getReservas().begin();it!=Hst.getReservas().end();it++){
        cout<< "Codigo de la reserva:"<< (*it).second->getCodigo()<<endl;
        cout<< "Fecha de entrada de la reserva:"<< (*it).second->getCheckIn().getDia()<<"/"<<(*it).second->getCheckIn().getMes()<<"/"<< (*it).second->getCheckIn().getAnio()<<endl ;
        cout<< "Fecha de salida de la reserva:"<< (*it).second->getCheckOut().getDia()<<"/"<<(*it).second->getCheckOut().getMes()<<"/"<<(*it).second->getCheckOut().getAnio();
        cout<< "Estado de la reserva:"<< (*it).second->getEstado()<<endl;
    }
    cout<< "Comentarios del hostal:"<<endl;
    for(auto it=Hst.getComentarios().begin();it!=Hst.getComentarios().end();it++){
        cout<< "Puntaje:"<< (*it).getPuntaje()<<endl;
        cout<< "Comentario de huesped:"<< (*it).getComentarioHuesp()<<endl;
        if((*it).getComentarioHuesp()==""){
            cout<< "Comentario de huesped:"<< (*it).getComentarioHuesp()<<endl;
        }   
    }
}

void consultaReserva(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "Nombre del hostal: " << (*it);
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: ";
    getline(cin >> ws, nombreHostal);
    list<DTReservaComp*> reservas = ctrlHostal->ObtenerReservasComp(nombreHostal);
    cout<< "Informacion de las reservas :";
    auto it=reservas.begin();
    while(it!=reservas.end()){
        DTReservaCompInd* ind = dynamic_cast<DTReservaCompInd*>((*it));
        if(ind!=NULL){
        cout<< "Codigo de la reserva: "<< (ind)->getCodigo() << endl;
        cout<< "Fecha de entrada de la reserva:"<< (ind)->getCheckIn().getDia() <<"/" <<(ind)->getCheckIn().getMes()<<"/"<<(ind)->getCheckIn().getAnio()  << endl;
        cout<< "Fecha de salida de la reserva:"<< (ind)->getCheckOut().getDia() <<"/"<<(ind)->getCheckOut().getMes()<<"/"<<(ind)->getCheckOut().getAnio() << endl ;
        cout<< "Estado de la reserva :"<< (ind)->getEstado() << endl;
        cout<< "Numero de habitacion :"<< (ind)->getNumHab() << endl;
        }
        else{
            DTReservaCompGrup* ind = dynamic_cast<DTReservaCompGrup*>((*it));
            cout<< "Codigo de la reserva: "<< (ind)->getCodigo() << endl;
            cout<< "Fecha de entrada de la reserva:"<< (ind)->getCheckIn().getDia() <<"/" <<(ind)->getCheckIn().getMes()<<"/"<<(ind)->getCheckIn().getAnio()  << endl;
            cout<< "Fecha de salida de la reserva:"<< (ind)->getCheckOut().getDia() <<"/"<<(ind)->getCheckOut().getMes()<<"/"<<(ind)->getCheckOut().getAnio() << endl ;
            cout<< "Estado de la reserva :"<< (ind)->getEstado() << endl;
            cout<< "Numero de habitacion :"<< (ind)->getNumHab() << endl;
            set<Huesped*> huespedes = ind->getHuesp();
            cout<< "Los huespedes de la reserva son:"<<endl;
            for(auto iter=huespedes.begin();iter!=huespedes.end();iter++){
                cout<< "Nombre del huesped: "<< (*iter)->getNombre()<< endl;
                cout<< "Email del huesped:"<< (*iter)->getEmail()  << endl;
            }
        }
        it++;
    }
}

void consultaEstadia(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<string> Hostales = ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son: "<<endl;
    for (set<string>::iterator i = Hostales.begin(); i != Hostales.end(); i++){
        cout << *i << "\n" <<endl;
    }
    cout << "Por favor seleccione uno de esos hostales ingresando su nombre: "<<endl;
    std::string nombreHostal;
    getline(cin >> ws, nombreHostal);
    list<DTIdEstadia> IdEstadia = ctrlHostal->ObtenerDTIdEstadia(nombreHostal);
    cout << "Las estadías registradas en el hostal " << nombreHostal << " son: " <<endl;
    int j = 1;
    for (list<DTIdEstadia>::iterator i = IdEstadia.begin(); i != IdEstadia.end(); i++) {
        cout << "Estadia "<< j << ": " << endl;
        cout << "Codigo de la reserva asociada a la estadía: " << (*i).getCodigo()  << endl;
        cout << "Email del huesped asociado a la estadía: " << (*i).getEmail()  << endl;
        j++;
    }
    cout << "Para conocer la información de una estadia ingrese los siguientes datos: " << endl;
    int Codigo;
    cout << "Código de la reserva asociada: " <<endl; cin >> Codigo;
    std::string emailHuesp;
    cout << "Email del huesped asociado:" <<endl; 
    getline(cin >> ws, emailHuesp);
    DTIdEstadia estadia;
    for (list<DTIdEstadia>::iterator i = IdEstadia.begin(); i != IdEstadia.end(); i++){
        std::string email = (*i).getEmail();
        int cod = (*i).getCodigo();
        if (email.compare(emailHuesp)== 0 && Codigo == cod)
            estadia = *i;
    }
    DataEstadia* EstSeleccionada = ctrlHostal->ObtenerinfoEstadia(estadia);
    cout << "__Informacion de la estadia__"<<endl;
    int diaIn = EstSeleccionada->getCheckIn().getDia();
    int mesIn = EstSeleccionada->getCheckIn().getMes();
    int anioIn = EstSeleccionada->getCheckIn().getAnio();
    int horaIn = EstSeleccionada->getCheckIn().getHora();
    int minutoIn = EstSeleccionada->getCheckIn().getMinutos();
    cout << "Fecha de ingreso: " << diaIn <<"/"<<mesIn<<"/"<<anioIn<<"-"<<horaIn<<":"<<minutoIn<<endl;
    int diaOut = EstSeleccionada->getCheckOut().getDia();
    int mesOut = EstSeleccionada->getCheckOut().getMes();
    int anioOut = EstSeleccionada->getCheckOut().getAnio();
    int horaOut = EstSeleccionada->getCheckOut().getHora();
    int minutoOut = EstSeleccionada->getCheckOut().getMinutos();
    cout << "Fecha de salida: " << diaOut <<"/"<<mesOut<<"/"<<anioOut<<"-"<<horaOut<<":"<<minutoOut<<endl;
    cout << "Huesped asociado: " << EstSeleccionada->getHuesped() <<endl;
    cout << "Hostal asociado: " << EstSeleccionada->getHostal() <<endl;
    cout << "Habitacion asociada: " << EstSeleccionada->getHabitacion() <<endl;
    cout << "Codigo de la reserva asociada: "<< EstSeleccionada->getCod()<<endl;
    cout << "¿Desea ver la calificacion de la estadía y la respuesta del empleado? Ingrese 1 si lo desea y 0 en caso contrario."<<endl;
    bool VerCalificacion;
    cin >> VerCalificacion;
    if (VerCalificacion) {
        DTCalificacion cal = ctrlHostal->MostrarCalificacion();
        cout << "Calificacion: " <<cal.getPuntaje()<<endl;
        cout << "Comentario del empleado: " << cal.getComentarioEmp() <<endl;
    }
    cout << "¿Desea ver la informacion de la reserva asociada? Ingrese 1 si lo desea y 0 en caso contrario."<<endl;
    bool VerInfoReserva;
    cin >> VerInfoReserva;
    if (VerInfoReserva) {
        DTReserva* res = ctrlHostal->MostrarInfoReserva(nombreHostal, Codigo);
        cout << "__Informacion de la reserva__"<<endl;
        cout << "Codigo de la reserva" <<res->getCodigo()<<endl;
        int diaIn = res->getCheckIn().getDia();
        int mesIn = res->getCheckIn().getMes();
        int anioIn = res->getCheckIn().getAnio();
        int horaIn = res->getCheckIn().getHora();
        int minutoIn = res->getCheckIn().getMinutos();
        cout << "Fecha de realizada: " << diaIn <<"/"<<mesIn<<"/"<<anioIn<<"-"<<horaIn<<":"<<minutoIn<<endl;
        int diaOut = res->getCheckOut().getDia();
        int mesOut = res->getCheckOut().getMes();
        int anioOut = res->getCheckOut().getAnio();
        int horaOut = res->getCheckOut().getHora();
        int minutoOut = res->getCheckOut().getMinutos();
        cout << "Fecha de terminada: " << diaOut <<"/"<<mesOut<<"/"<<anioOut<<"-"<<horaOut<<":"<<minutoOut<<endl;
        cout << "Estado de la reserva: " << res->getEstado() <<endl;
    }
}

void bajaReserva(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "Nombre del hostal: " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    list<DTReserva*> Reservas= ctrlHostal->ObtenerReservas(nombreHostal);
    cout<< "Las reservas son:"<<endl;
    for(auto it=Reservas.begin();it!=Reservas.end();it++){
        cout<< "El codigo de la reserva es:"<< (*it)->getCodigo()<<endl;
    }
    int codRes;
    cout<< "Ingrese codigo de la reserva elegida:"<<endl;
    cin>> codRes;
    ctrlHostal->SeleccionarReserva(codRes);
    cout << "Ingrese 1 para confirmar la baja o 0 para cancelar "<<endl;
    bool conf;
    cin>> conf;
    if(conf){
        ctrlHostal->ConfirmarEliminarReserva();
    }
    else{
        ctrlHostal->CancelarBajaReserva();
    }
}

void modificarFechaSistema(){
    SingletonFechaHora *FH = SingletonFechaHora::getInstance();
    int anio, mes, dia, hora, minutos;
    cout<< "Ingresar año:"<<endl;
    cin>> anio;
    cout<< "Ingresar mes:"<<endl;
    cin>> mes;
    cout<< "Ingresar dia:"<<endl;
    cin>> dia;
    cout<< "Ingresar hora:"<<endl;
    cin>> hora;
    cout<< "Ingresar minutos:"<<endl;
    cin >> minutos;
    FH->actualizarFechaSistema(anio,mes,dia,hora, minutos);
}

void SuscribirseaNotificaciones(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<DTEmpleado> Emp=ctrlHostal->ObtenerEmpleados();
    cout<< "Los email de los empleados son:"<<endl;
    for (auto it=Emp.begin();it!=Emp.end();it++){
        cout<< (*it).getEmail()<<endl;
    }
    string email;
    cout<< "Ingrese el email del empleado elegido:"<<endl;
    getline(cin >> ws, email);
    ctrlHostal->SuscribirEmpleado(email);
}

void ConsultaDeNotificaciones(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<DTEmpleado> Emp=ctrlHostal->ObtenerEmpleados();
    cout<< "Los email de los empleados son:"<<endl;
    for (auto it=Emp.begin();it!=Emp.end();it++){
        cout<< (*it).getEmail()<<endl;
    }
    string email;
    cout<< "Ingrese el email del empleado elegido:"<<endl;
    getline(cin >> ws, email);
    list<DTCalificacion> cal=ctrlHostal->ObtenerNotificaciones(email);
    for(auto it=cal.begin();it!=cal.end();it++){
        cout<< "El puntaje de la calificacion es:"<< (*it).getPuntaje()<<endl;
        cout<< "El comentario de la calificacion es:"<< (*it).getComentarioHuesp()<<endl;
    }
    ctrlHostal->EliminarNotificaciones();
}

void EliminarSuscripcion(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<DTEmpleado> Emp=ctrlHostal->ObtenerEmpleados();
    cout<< "Los email de los empleados son:"<<endl;
    for (auto it=Emp.begin();it!=Emp.end();it++){
        cout<< (*it).getEmail()<<endl;
    }
    string email;
    cout<< "Ingrese el email del empleado elegido:"<<endl;
    getline(cin >> ws, email);
    ctrlHostal->eliminarSuscripcion(email);
}

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
