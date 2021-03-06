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
int opcionMenu;
std::string opcion;

/*void opcionNoValida(){
    cout << "===============================" << endl;
    cout << "==      OPCION INVALIDA      ==" << endl;
    cout << "===============================" << endl;
}*/

void Menu(){
    cout << "=====================================" << endl;
    cout << "            MENÚ PRINCIPAL           " << endl;
    cout << "=====================================" << endl;
    cout << "- Seleccione una opción -" << endl;
    cout << "1  - Cargar datos de prueba" << endl;
    cout << "2  - Alta de Usuario"<< endl;
    cout << "3  - Alta de Hostal"<< endl;
    cout << "4  - Alta de Habitación"<< endl;
    cout << "5  - Asignar Empleado a Hostal"<< endl;
    cout << "6  - Realizar Reserva"<< endl;
    cout << "7  - Consultar top 3 de hostales"<< endl;
    cout << "8  - Registrar Estadía"<< endl;
    cout << "9  - Finalizar Estadía"<< endl;
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
    ctrlUsuario->setTipoUsuario(0);
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
    ctrlUsuario->setTipoUsuario(1);
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
    ctrlHostal->SeleccionarEmpleado(cargo,"barli@mail.com");
    ctrlHostal->ConfirmarAsignacionDeEmpleado(); 
    //Realizo las reservas
    DTFecha in,out;

    in = DTFecha(1,5,2022,14,00);
    out = DTFecha(10,5,2022,10,00);
    ctrlHostal->ingresarDatosReserva("La posada del finger",in,out,0,1);
    ctrlHostal->seleccionarHabitacion(1);
    ctrlHostal->seleccionarHuesped("sofia@mail.com");
    int codigo1 = ctrlHostal->confirmarAltaReserva();

    in = DTFecha(4,1,2001,20,00);
    out = DTFecha(5,1,2001,2,00);
    ctrlHostal->ingresarDatosReserva("El Pony Pisador",in,out,1,4);
    ctrlHostal->seleccionarHabitacion(1);
    ctrlHostal->seleccionarHuesped("frodo@mail.com");
    ctrlHostal->seleccionarAcompaniante("sam@mail.com");
    ctrlHostal->seleccionarAcompaniante("merry@mail.com");
    ctrlHostal->seleccionarAcompaniante("pippin@mail.com");
    int codigo2 = ctrlHostal->confirmarAltaReserva();

    in = DTFecha(7,6,2022,14,00);
    out = DTFecha(30,6,2022,11,00);
    ctrlHostal->ingresarDatosReserva("La posada del finger",in,out,0,1);
    ctrlHostal->seleccionarHabitacion(3);
    ctrlHostal->seleccionarHuesped("sofia@mail.com");
    int codigo3 = ctrlHostal->confirmarAltaReserva();

    in = DTFecha(10,6,2022,14,00);
    out = DTFecha(30,6,2022,11,00);
    ctrlHostal->ingresarDatosReserva("Caverna Lujosa",in,out,0,1);
    ctrlHostal->seleccionarHabitacion(1);
    ctrlHostal->seleccionarHuesped("seba@mail.com");
    int codigo4 = ctrlHostal->confirmarAltaReserva();
   //Estadias
    list<int> reservasNC;
    DTFecha checkin;

    ctrlHostal->actualizarFS(2022,5,1,18,00);
    reservasNC = ctrlHostal->ObtenerReservasNC("La posada del finger","sofia@mail.com");
    Huesped* huesp1 = ctrlUsuario->buscarHuesped("sofia@mail.com");
    ctrlHostal->ReservaNCElegida(codigo1,huesp1);

    ctrlHostal->actualizarFS(2001,1,4,21,00);
    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","frodo@mail.com");
    Huesped* huesp2 = ctrlUsuario->buscarHuesped("frodo@mail.com");
    ctrlHostal->ReservaNCElegida(codigo2,huesp2);

    ctrlHostal->actualizarFS(2001,1,4,21,00);
    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","sam@mail.com");
    Huesped* huesp3 = ctrlUsuario->buscarHuesped("sam@mail.com");
    ctrlHostal->ReservaNCElegida(codigo2,huesp3);
    
    ctrlHostal->actualizarFS(2001,1,4,21,00);
    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","merry@mail.com");
    Huesped* huesp4 = ctrlUsuario->buscarHuesped("merry@mail.com");
    ctrlHostal->ReservaNCElegida(codigo2,huesp4);

    ctrlHostal->actualizarFS(2001,1,4,21,00);
    reservasNC = ctrlHostal->ObtenerReservasNC("El Pony Pisador","pippin@mail.com");
    Huesped* huesp5 = ctrlUsuario->buscarHuesped("pippin@mail.com");
    ctrlHostal->ReservaNCElegida(codigo2,huesp5);

    ctrlHostal->actualizarFS(2022,6,10,18,00);
    reservasNC = ctrlHostal->ObtenerReservasNC("Caverna Lujosa","seba@mail.com");
    Huesped* huesp6 = ctrlUsuario->buscarHuesped("seba@mail.com");
    ctrlHostal->ReservaNCElegida(codigo4,huesp6);

    //Finalizacion de estadias
    bool finalizoEst = false;
    ctrlHostal->actualizarFS(2022,5,10,9,00);
    ctrlHostal->DatosHuesped("La posada del finger", "sofia@mail.com",finalizoEst);
    ctrlHostal->actualizarFS(2001,1,5,2,00);
    ctrlHostal->DatosHuesped("El Pony Pisador", "frodo@mail.com",finalizoEst);
    ctrlHostal->actualizarFS(2022,6,15,10,00);
    ctrlHostal->DatosHuesped("Caverna Lujosa", "seba@mail.com",finalizoEst);
    ctrlHostal->actualizarFS(2022,6,15,10,00);
    
    //calificar estadia
   DTIdEstadia estadia;
    list<DTIdEstadia> est;
    std::string comentario;
    ctrlHostal->actualizarFS(2022,5,11,18,00);
    ctrlHostal->SeleccionarHostal("La posada del finger");
    est = ctrlHostal->ListaEstadiasFinalizadas("sofia@mail.com");
    for (list<DTIdEstadia>::iterator i = est.begin(); i != est.end(); i++){
        if (codigo1 == (*i).getCodigo())
            estadia = (*i);
    }
    ctrlHostal->SeleccionarEstadia(estadia);
    comentario = "Un poco caro para lo que ofrecen.El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo";
    ctrlHostal->ConfirmarCalificacion(comentario, 3);

    ctrlHostal->actualizarFS(2001,1,5,3,00);
    ctrlHostal->SeleccionarHostal("El Pony Pisador");
    est = ctrlHostal->ListaEstadiasFinalizadas("frodo@mail.com");
    for (list<DTIdEstadia>::iterator i = est.begin(); i != est.end(); i++){
        if (codigo2 == (*i).getCodigo())
            estadia = (*i);
    }
    ctrlHostal->SeleccionarEstadia(estadia);
    comentario = "Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.";
    ctrlHostal->ConfirmarCalificacion(comentario, 2);

    ctrlHostal->actualizarFS(2022,6,15,23,00);
    ctrlHostal->SeleccionarHostal("Caverna Lujosa");
    est = ctrlHostal->ListaEstadiasFinalizadas("seba@mail.com");
    for (list<DTIdEstadia>::iterator i = est.begin(); i != est.end(); i++){
        if (codigo4 == (*i).getCodigo())
            estadia = (*i);
    }
    ctrlHostal->SeleccionarEstadia(estadia);
    comentario = "Había pulgas en la habitación. Que lugar más mamarracho!!";
    ctrlHostal->ConfirmarCalificacion(comentario, 1);

    //comentar calificacion
    ctrlHostal->actualizarFS(2001,1,6,15,00);
    list<DTCal> comentaResponder = ctrlHostal->ObtenerComentariosAResponder("barli@mail.com");
    std::string respuesta = "Desapareció y se fue sin pagar.";
    ctrlHostal-> ResponderComentario("frodo@mail.com",codigo2,respuesta);

    cout<< " ¡DATOS CARGADOS CON EXITO!"<<endl;

}

void altaUsuario(){
    IUsuario* ctrlUsuario = fabrica->obtenerControladorUsuario();
    cout << "Ingrese 0 si va a ingresar un Huesped y 1 si va a ingresar un Empleado: "<<endl;
    std::string tipoUser;
    cin >> tipoUser;
    if (tipoUser != "1" && tipoUser != "0")
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    else {
        bool TipoUsuario = (tipoUser == "1");
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
            std::string finger;
            cin >> finger;
            if (finger != "1" && finger != "0")
                throw std::invalid_argument("El dato ingresado no es correcto."); 
            else {
                bool esfinger = (finger == "1"); 
                ctrlUsuario->IngresarHuesped(nombre,email,password,esfinger);
                cout << "Si desea confirmar el alta del usuario ingrese 1, de lo contrario ingrese 0: "<< endl;
                std::string confirmo;
                cin >>confirmo;
                if (confirmo != "1" && confirmo != "0")
                    throw std::invalid_argument("El dato ingresado no es correcto."); 
                else {
                    bool confirmar = (confirmo == "1");
                    if (confirmar == 1){
                        ctrlUsuario->ConfirmarAltaUsuario();
                        cout << "¡HUESPED INGRESADO CON EXITO!"<<endl;
                        cout << endl;
                    }else {
                        ctrlUsuario->CancelarAltaUsuario();
                        cout << "¡HUESPED CANCELADO CON EXITO!"<<endl;
                        cout << endl;
                    }
                }
            }
        }else {
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
            cout << "Si desea confirmar el alta del usuario ingrese 1, de lo contrario ingrese 0: "<< endl;
            int confirmo;
            cin >>confirmo;
            if (confirmo != 1 && confirmo != 0)
                throw std::invalid_argument("El dato ingresado no es correcto."); 
            else {
                bool confirmar = (confirmo == 1);
                if (confirmar){
                    ctrlUsuario->ConfirmarAltaUsuario();
                    cout << "¡EMPLEADO INGRESADO CON EXITO!"<<endl;
                    cout << endl;
                }else {
                    ctrlUsuario->CancelarAltaUsuario();
                    cout << "¡EMPLEADO CANCELADO CON EXITO!"<<endl;
                    cout << endl;
                }
            }
        }
    }
}
void altaHostal(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    string nombre,direccion,telefono;
    cout << "Ingrese el nombre del hostal: "<<endl;
    getline(cin >> ws, nombre);
    cout << "Ingrese la direccion del hostal: "<<endl;
    getline(cin >> ws, direccion);
    cout << "Ingrese el telefono del hostal: "<<endl;
    getline(cin >> ws, telefono);
    ctrlHostal->agregarHostal(nombre,direccion,telefono);
    cout << "¡HOSTAL INGRESADO CON EXITO!"<<endl;
    cout<<endl;
}

void altaHabitacion(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "   - " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    int num;
    cout << "Ingrese el numero de habitación: "<<endl;
    cin>> num;
    float precio;
    cout << "Ingrese el precio de la habitación: "<<endl;
    cin>> precio;
    int capacidad;
    cout << "Ingrese la capacidad de la habitación: "<<endl;
    cin>> capacidad;
    ctrlHostal->asignarHab(nombreHostal,num, precio, capacidad);
    cout << "Ingrese 1 para asignar la habitación o 0 para cancelarla: "<<endl;
    std::string opcion;
    cin >>opcion;
    if (opcion != "1" && opcion != "0")
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    else {
        bool cual = (opcion == "1");
        if (cual){
            ctrlHostal->registrarHab();
            cout << "¡HABITACION ASIGNADA CON EXITO!"<<endl;
            cout << endl;
        } else {
            ctrlHostal->cancelarAltaHabitacion();
            cout << "¡HABITACION CANCELADA CON EXITO!"<<endl;
            cout << endl;
        }
    }
}

void asignarEmpleadoAHostal(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<DTHostalProm> hostalesRegistrados = ctrlHostal->ObtenerHostalesProm();
    cout << "Los hostales registrados en el sistema son:" << endl;
    int j=1;
    for (auto it=hostalesRegistrados.begin();it!=hostalesRegistrados.end();++it){
        cout <<"Hostal "<< j <<":"<<endl;
        cout << "  -Nombre del hostal: " << (*it).getNombre() << endl;
        cout << "  -Direccion del hostal: " << (*it).getDireccion() << endl;
        cout << "  -Calificaciones promedio del hostal: " << (*it).getCalificacionesPromedio() << endl;
        j++;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    list<DTEmpleado> empleadosRegistrados = ctrlHostal->ObtenerEmpleados(nombreHostal);
    if(empleadosRegistrados.empty())
        throw std::invalid_argument("No hay empleados registrados en el sistema sin cargo asignado."); 
    cout << "Los empleados registrados en el sistema sin cargo son:" << endl;
    int k = 1;
    for (auto it=empleadosRegistrados.begin();it!=empleadosRegistrados.end();++it){
        cout <<"Empleado "<<k<<":"<<endl;
        cout << "   -Nombre del empleado: " << (*it).getNombre() << endl;
        cout << "   -Email del empleado: " << (*it).getEmail() << endl;
        k++;
    }
    string mailEmp;
    int cargo;    
    cout << "Ingrese el email del empleado elegido: ";
    getline(cin >> ws, mailEmp);
    cout << "'1' para asignar el cargo Administracion" << endl;
    cout << "'2' para asignar el cargo Limpieza" << endl;
    cout << "'3' para asignar el cargo Recepcion" << endl;
    cout << "'4' para asignar el cargo Infraestructura" << endl;
    cout << "Ingrese el numero del cargo a ejercer por el empleado elegido: "<<endl;
    std::string Cargoemp;
    cin >> Cargoemp;
    if (Cargoemp != "1"&&Cargoemp != "2"&&Cargoemp != "3"&&Cargoemp != "4") {
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    }
    if (Cargoemp == "1")
        cargo = 1;    
    if (Cargoemp == "2")
        cargo = 2;
    if (Cargoemp == "3")
        cargo = 3;
    if (Cargoemp == "4")
        cargo = 4;
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
        default: throw std::invalid_argument("El numero ingresado no es correcto.");
    }    
    ctrlHostal->SeleccionarEmpleado(cargo1,mailEmp);
    cout << "Ingrese 1 para confirmar la asignacion o 0 para cancelarla: "<<endl;
    std::string confirmo;
    cin >>confirmo;
    if (confirmo != "1" && confirmo != "0")
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    else {
        bool opcionIngresada = (confirmo == "1");
        if (opcionIngresada){
            ctrlHostal->ConfirmarAsignacionDeEmpleado();
            cout << "¡ASIGNACION REALIZADA CON EXITO!"<<endl;
            cout << endl;
        } else {
            ctrlHostal->CancelarAsignacionDeEmpleado();
            cout << "¡ASIGNACION CANCELADA CON EXITO!"<<endl;
            cout << endl;
        }
    }
}

void realizarReserva(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<DTHostalProm> hostalesRegistrados = ctrlHostal->ObtenerHostalesProm();
     cout << "Los hostales registrados en el sistema son:" << endl;
    int j=1;
    for (auto it=hostalesRegistrados.begin();it!=hostalesRegistrados.end();++it){
        cout <<"Hostal "<< j <<":"<<endl;
        cout << "  -Nombre del hostal: " << (*it).getNombre() << endl;
        cout << "  -Direccion del hostal: " << (*it).getDireccion() << endl;
        cout << "  -Calificaciones promedio del hostal: " << (*it).getCalificacionesPromedio() << endl;
        j++;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    int dia_in,mes_in,anio_in,hora_in,min_in,dia_out,mes_out,anio_out,hora_out,min_out;
    cout << "Ingrese el dia de entrada: "<<endl;
    cin >> dia_in;
    cout << "Ingrese el mes de entrada: "<<endl;
    cin >> mes_in;
    cout << "Ingrese el año de entrada: "<<endl;
    cin >> anio_in;
    cout << "Ingrese la hora de entrada: "<<endl;
    cin >> hora_in;
    cout << "Ingrese los minutos de entrada: "<<endl;
    cin >> min_in;
    if (dia_in < 1 || dia_in>31 || mes_in<1 || mes_in>12 || hora_in<0 || hora_in>23 || min_in<0 || min_in>59) {
        throw std::invalid_argument("La fecha/hora ingresada no es correcta.");
    }
    DTFecha in = DTFecha(dia_in,mes_in,anio_in,hora_in,min_in);
    cout << "Ingrese el dia de salida: "<<endl;
    cin >> dia_out;
    cout << "Ingrese el mes de salida: "<<endl;
    cin >> mes_out;
    cout << "Ingrese el año de salida: "<<endl;
    cin >> anio_out;
    cout << "Ingrese la hora de salida: "<<endl;
    cin >> hora_out;
    cout << "Ingrese los minutos de salida: "<<endl;
    cin >> min_out;
    if (dia_out < 1 || dia_out>31 || mes_out<1 || mes_out>12 || hora_out<0 || hora_out>23 || min_out<0 || min_out>59) {
        throw std::invalid_argument("La fecha/hora ingresada no es correcta.");
    }
    DTFecha out = DTFecha(dia_out,mes_out,anio_out,hora_out,min_out);
    cout << "Ingrese 1 si la reserva es grupal, y 0 si es individual: "<<endl;
    std::string grupInd;
    cin >>grupInd;
    if (grupInd != "1" && grupInd != "0")
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    else {
        bool grupOind = (grupInd == "1");
        int totalHuesp;
        if (grupOind){
            cout << "Ingrese la cantidad de huespedes que se quedaran con usted (incluyendose): "<<endl;
            cin >> totalHuesp;
        } else {
            totalHuesp=1;
        }
        ctrlHostal->ingresarDatosReserva(nombreHostal,in,out,grupOind,totalHuesp);
        list<int> ColHabDisp = ctrlHostal->obtenerHabitacionesDisponibles(in,out,totalHuesp); //aca controlo q las q devuelvo sean para la capacidad d los huespedes q pidio
        if (!ColHabDisp.empty()){
            cout << "Las habitaciones disponibles en esas fechas son: "<<endl;
            for (auto it=ColHabDisp.begin();it!=ColHabDisp.end();++it){
                cout << "  - "<<*it << endl;
                }
            cout << "Ingrese el numero de la habitacion elegida: "<<endl;
            int numHab;
            cin >> numHab;
            ctrlHostal->seleccionarHabitacion(numHab);
            cout << "Los mail de los huespedes registrados en el sistema son:" <<  endl;
            list<string> mailHuespedes = ctrlHostal->obtenerHuespedesRegistrados();
            for (auto it=mailHuespedes.begin();it!=mailHuespedes.end();++it){
                cout << "  - "<<*it << endl;
            }
            cout << "Ingrese el mail del huesped que realiza la reserva: "<<endl;
            string mailHuesp;
            getline(cin >> ws, mailHuesp);
            ctrlHostal->seleccionarHuesped(mailHuesp);
            if (grupOind){
                for(int i=1;i<totalHuesp;i++){
                    cout << "Ingrese el mail del acompañante " << i << ": "<<endl;
                    string mailAcompaniante;
                    getline(cin >> ws, mailAcompaniante);
                    ctrlHostal->seleccionarAcompaniante(mailAcompaniante);
                }
            }
            cout << "Ingrese 1 para confirmar la reserva o 0 para cancelarla: "<<endl;
            std::string confirmo;
            cin >>confirmo;
            if (confirmo != "1" && confirmo != "0")
                throw std::invalid_argument("El dato ingresado no es correcto."); 
            else {
                bool opcionIngresada = (confirmo == "1");
                if (opcionIngresada){
                    int confirmar = ctrlHostal->confirmarAltaReserva();
                    cout << "¡RESERVA REALIZADA CON EXITO!"<<endl;
                    cout << endl;
                } else {
                    ctrlHostal->cancelarAltaReserva();
                    cout << "¡RESERVA CANCELADA CON EXITO!"<<endl;
                    cout << endl;
                }
            }
        }else 
            throw std::invalid_argument("No hay habitaciones disponibles para esa fecha."); 

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
        cout << i << ". " <<(*it) << endl;
        i++;
        ++it;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
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
    IUsuario *ctrlUsuario = fabrica->obtenerControladorUsuario();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "  - " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    std::string email;
    cout << "Ingrese el email del huesped: "<< endl; 
    cin >> email;
    list<int> reservasNC = ctrlHostal->ObtenerReservasNC(nombreHostal, email); 
    if(reservasNC.empty()){
        throw std::invalid_argument("No existen reservas aptas para registrar la estadia.");
    }
    cout << "Los reservas no canceladas en el sistema son:" << endl;
    for (auto it=reservasNC.begin();it!=reservasNC.end();++it){
        cout << "-" << (*it) << endl;
    }
    int codigo;
    cout << "Ingresar el codigo de la reserva no cancelada elegida:" << endl;
    cin >>codigo;
    Huesped* huesp = ctrlUsuario->buscarHuesped(email);
    ctrlHostal->ReservaNCElegida(codigo,huesp);
    cout << "¡ESTADIA REALIZADA CON EXITO!"<<endl;
    cout << endl;
}

void finalizarEstadia(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    IUsuario *ctrlUsuario = fabrica->obtenerControladorUsuario();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "  - " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    std::string email;
    cout << "Ingrese el email del huesped: "<< endl; 
    getline(cin >> ws, email);
    bool finalizoEst = false;
    ctrlHostal->DatosHuesped(nombreHostal,email,finalizoEst);
    if (!finalizoEst){
    	cout << "NO HAY ESTADIAS PARA FINALIZAR."<<endl;
    } else
    	cout << "¡ESTADIA FINALIZADA CON EXITO!"<<endl;
    cout << endl;
}

void calificarEstadia(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    IUsuario *ctrlUsuario = fabrica->obtenerControladorUsuario();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "  - " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    ctrlHostal->SeleccionarHostal(nombreHostal);
    cout << "Ingrese el mail del huesped: "<<endl;
    string mailHsp;
    getline(cin >> ws, mailHsp);
    list<DTIdEstadia> lista=ctrlHostal->ListaEstadiasFinalizadas(mailHsp);
    if(lista.empty()){
        throw std::invalid_argument("No existen estadias para calificar.");
    }
    cout<< "Las estadias finalizadas son:"<<endl;
    for(auto it=lista.begin();it!=lista.end();it++){
        cout<< "  - Codigo de la reserva:"<< (*it).getCodigo()<<endl;
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
    cout<< "Ingrese puntaje de la calificacion (entero del 1 al 5):"<<endl;
    cin>> Puntaje;
    if (Puntaje > 5)
        throw std::invalid_argument("El puntaje debe ser entre 1 y 5.");
    string comentario;
    cout<< "Ingrese comentario de la calificacion:"<<endl;
    getline(cin >> ws, comentario);
    ctrlHostal->ConfirmarCalificacion(comentario,Puntaje);
    cout << "¡CALIFICACION DE ESTADIA REALIZADA CON EXITO!"<<endl;
    cout << endl;

}

void comentarCalificacion(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    IUsuario *ctrlUsuario = fabrica->obtenerControladorUsuario();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "  - " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    bool existe = false;
    for (auto it = nombres.begin();it != nombres.end(); it++){
        if (*it == nombreHostal)
            existe = true;
    }
    if (!existe)
        throw std::invalid_argument("No existe un hostal con ese nombre."); 
    list<std::string> empleados = ctrlUsuario->empleadosEnHostal(nombreHostal);
    cout << "Los empleados que trabajan en ese hostal son: "<<endl;
    for (auto it = empleados.begin(); it != empleados.end(); it++){
        cout <<"  - "<< *it <<endl;
    }
    cout << "Ingrese el mail de un empleado: "<<endl; 
    string mailEmp;
    getline(cin >> ws, mailEmp);
    bool esta = ctrlUsuario->existeEmp(mailEmp);
    if (!esta) {
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    }
    list<DTCal> comentarios = ctrlHostal->ObtenerComentariosAResponder(mailEmp);
    for (auto it=comentarios.begin();it!=comentarios.end();++it){
        cout << "Comentario del huesped: " << (*it).getComentarioHuesp()<<endl;
        cout << "Mail del huesped: " << (*it).getMailHuesp()<<endl;
        cout << "Codigo de la reserva asociada: " << (*it).getCodigoRes()<<endl;
    }
    cout << "Ingrese el mail del huesped del cual desea responder un comentario: "<<endl; 
    string mailHuesp,respuesta;
    int codigoRes;
    getline(cin >> ws, mailHuesp);
    cout << "Ingrese el codigo de la reserva asociada: "<<endl;
    cin >> codigoRes;
    cout << "Ingrese su respuesta: "<<endl;
    getline(cin >> ws, respuesta);
    ctrlHostal->ResponderComentario(mailHuesp,codigoRes,respuesta);    
    cout << "¡RESPUESTA REALIZADA CON EXITO!"<<endl;
    cout << endl;
}

void consultaUsuario(){
    IUsuario* ctrlUsuario = fabrica->obtenerControladorUsuario();
    set<string> Usuarios = ctrlUsuario->ObtenerUsuarios();
    cout << "Los usuarios registrados en el sistema son: "<<endl;
    for (set<string>::iterator i = Usuarios.begin(); i != Usuarios.end(); i++){
        cout << *i << "\n" <<endl;
    }
    Usuarios.clear();
    cout <<"Si desea consultar la informacion de un huesped ingrese 0, si quiere la de un empleado ingrese 1: "<<endl;
    std::string User;
    cin >>User;
    if (User != "1" && User != "0")
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    else {
        bool tipoUser = (User == "1");
        if (!tipoUser) {
            cout << "Ingrese el email correspondiente al huesped cuya informacion quiere consultar: " <<endl;
            std::string email;
            getline(cin >> ws, email);
            DTHuesped* Huesped = ctrlUsuario->SeleccionarHuesped(email);
            cout << "__Información del huesped seleccionado__"<<endl;
            cout << "  - Nombre: "<< Huesped->getNombre()  <<endl;
            cout << "  - Email: " << Huesped->getMail()  <<endl;
            bool esfing = Huesped->getEsFinger();
            if (esfing)
                cout << "  - Es finger" << endl;
            else    
                cout << "  - No es finger" <<endl;
            delete Huesped;
        }
        else {
            cout << "Ingrese el email correspondiente al empleado cuya informacion quiere consultar: "<<endl;
            std::string email;
            getline(cin >> ws, email);
            DataEmpleado* Empleado = ctrlUsuario->SeleccionarEmpleado2(email);
            cout << "__Información del empleado seleccionado__"<<endl;
            cout << "  - Nombre: "<< Empleado->getNombre()  <<endl;
            cout << "  - Email: " << Empleado->getEmail()  <<endl;
            CargoEmpleado* cargo = Empleado->getCargo();
            switch(*cargo) {
            case 0: cout << "  - El cargo del empleado es: Administracion"<<endl; 
            break;
            case 1: cout << "  - El cargo del empleado es: Limpieza"<<endl; 
            break;
            case 2: cout << "  - El cargo del empleado es: Recepcion"<<endl;
            break;
            case 3: cout << "  - El cargo del empleado es: Infraestructura"<<endl;
            break;
            default:
                break;
            }
            cout << "  - El empleado trabaja en el Hostal: " << Empleado->getHostal() << endl;  
            delete Empleado;
        }
        cout <<endl;
    }
}

void consultaHostal(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "  - " << (*it)<<endl;
    }
    std::string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    DataHostalComp Hst=ctrlHostal->ObtenerHostalComp(nombreHostal);
    cout<< "  - Nombre del hostal:"<< nombreHostal<<endl;
    cout<< "  - Direccion del hostal:"<< Hst.getDireccion()<<endl;
    cout<< "  - Telefono del hostal:"<< Hst.getTelefono()<<endl;
    cout<< "  - Promedio del hostal:"<< Hst.getPromedio()<<endl;
    unsigned int tam;
    if(Hst.getHabitaciones().empty()){
        cout<< "El hostal no tiene habitaciones registradas."<<endl;
    }
    else{
        cout<< "  - Habitaciones del hostal:"<<endl;
        map<int,Habitacion*> habitaciones = Hst.getHabitaciones();
        auto it = habitaciones.begin();
        tam = 1;
        while(tam<= habitaciones.size()){
            cout<< "    - Numero de la habitacion:"<< (*it).second->getNumero()<<endl;
            cout<< "    - Capacidad de la habitacion:"<< (*it).second->getCapacidad()<<endl;
            cout<< "    - Precio de la habitacion :"<< (*it).second->getPrecioNoche()<<endl;
            tam++;
            ++it;
        }
    }
    
    map<int,Reserva*> reservas = Hst.getReservas();
    //cout<< Hst.getReservas().size()<<endl;
    if(reservas.empty()){
        cout<<"El hostal no tiene reservas realizadas."<<endl;
    }
    else{
        tam=1;
        auto it=reservas.begin();
        cout<< "Reservas del hostal:"<<endl;
        while(tam<= reservas.size()){
            cout<< "  - Codigo de la reserva:"<< (*it).second->getCodigo()<<endl;
            cout<< "  - Fecha de entrada de la reserva:"<< (*it).second->getCheckIn().getDia()<<"/"<<(*it).second->getCheckIn().getMes()<<"/"<< (*it).second->getCheckIn().getAnio()<<endl ;
            cout<< "  - Fecha de salida de la reserva:"<< (*it).second->getCheckOut().getDia()<<"/"<<(*it).second->getCheckOut().getMes()<<"/"<<(*it).second->getCheckOut().getAnio()<<endl;
            EstadoReserva estado = (*it).second->getEstado();
            switch(estado){
            case 0: cout << "  - La reserva está abierta"<<endl;
            break;
            case 1: cout << "  - La reserva está cerrada"<<endl;
            break;
            case 2: cout << "  - La reserva está cancelada"<<endl;
            break;
            }
            tam++;
            ++it;
        }
    }
    list<DTCalificacion> comentarios = Hst.getComentarios();
    if(comentarios.empty()){
        cout<<"El hostal no tiene comentarios realizados."<<endl;
    }
    else{
        cout<< "Comentarios del hostal:"<<endl;
        tam=1;
        auto it=comentarios.begin();
        while(tam<= comentarios.size()){
            cout<< "  - Puntaje:"<< (*it).getPuntaje()<<endl;
            cout<< "  - Comentario de huesped:"<< (*it).getComentarioHuesp()<<endl;
            if((*it).getComentarioEmp()!=""){//arreglar esto
                cout<< "  - Comentario de empleado:"<< (*it).getComentarioEmp()<<endl;
            } 
            tam++;
            ++it;              
        }
    }
}

void consultaReserva(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "  - " << (*it)<<endl;
    }
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    list<DTReservaComp*> reservas = ctrlHostal->ObtenerReservasComp(nombreHostal);
    cout<< "_Informacion de las reservas_"<<endl;
    auto it=reservas.begin();
    if(it==reservas.end())
        throw std::invalid_argument("No hay reservas registradas en ese Hostal.");
    else{
    while(it!=reservas.end()){
        DTReservaCompInd* ind = dynamic_cast<DTReservaCompInd*>((*it));
        if(ind!=NULL){
            cout<< "  - Codigo de la reserva: "<< (ind)->getCodigo() << endl;
            cout<< "  - Fecha de entrada de la reserva:"<< (ind)->getCheckIn().getDia() <<"/" <<(ind)->getCheckIn().getMes()<<"/"<<(ind)->getCheckIn().getAnio()  << endl;
            cout<< "  - Fecha de salida de la reserva:"<< (ind)->getCheckOut().getDia() <<"/"<<(ind)->getCheckOut().getMes()<<"/"<<(ind)->getCheckOut().getAnio() << endl ;
            EstadoReserva estado = (ind)->getEstado();
            switch(estado){
            case 0: cout << "  - La reserva está abierta"<<endl;
            break;
            case 1: cout << "  - La reserva está cerrada"<<endl;
            break;
            case 2: cout << "  - La reserva está cancelada"<<endl;
            break;
        }
        cout<< "  - Numero de habitacion :"<< (ind)->getNumHab() << endl;
        }
        else{
            DTReservaCompGrup* ind = dynamic_cast<DTReservaCompGrup*>((*it));
            cout<< "  - Codigo de la reserva: "<< (ind)->getCodigo() << endl;
            cout<< "  - Fecha de entrada de la reserva:"<< (ind)->getCheckIn().getDia() <<"/" <<(ind)->getCheckIn().getMes()<<"/"<<(ind)->getCheckIn().getAnio()  << endl;
            cout<< "  - Fecha de salida de la reserva:"<< (ind)->getCheckOut().getDia() <<"/"<<(ind)->getCheckOut().getMes()<<"/"<<(ind)->getCheckOut().getAnio() << endl ;
            EstadoReserva estado = (ind)->getEstado();
            switch(estado){
            case 0: cout << "  - La reserva está abierta"<<endl;
            break;
            case 1: cout << "  - La reserva está cerrada"<<endl;
            break;
            case 2: cout << "  - La reserva está cancelada"<<endl;
            break;
            }
            cout<< "  - Numero de habitacion :"<< (ind)->getNumHab() << endl;
            set<Huesped*> huespedes = ind->getHuesp();
            cout<< "  - Los huespedes de la reserva son:"<<endl;
            for(auto iter=huespedes.begin();iter!=huespedes.end();iter++){
                cout<< "    - Nombre del huesped: "<< (*iter)->getNombre()<< endl;
                cout<< "    - Email del huesped:"<< (*iter)->getEmail()  << endl;
            }
        }
        it++;
    }
    nombres.clear();
    reservas.clear();
    /*it=reservas.begin();
    while(it!=reservas.end()){
        delete (*it);
        it++;
    }*/

    cout <<endl; 
    }
}

void consultaEstadia(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<string> Hostales = ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son: "<<endl;
    for (set<string>::iterator i = Hostales.begin(); i != Hostales.end(); i++){
        cout << "  - " <<*i  <<endl;
    }
    Hostales.clear();
    cout << "Seleccione uno de esos hostales ingresando su nombre: "<<endl;
    std::string nombreHostal;
    getline(cin >> ws, nombreHostal);
    list<DTIdEstadia> IdEstadia = ctrlHostal->ObtenerDTIdEstadia(nombreHostal);
    if (!IdEstadia.empty()) {
        cout << "Las estadías registradas en el hostal " << nombreHostal << " son: " <<endl;
        int j = 1;
        for (list<DTIdEstadia>::iterator i = IdEstadia.begin(); i != IdEstadia.end(); i++) {
            cout << "Estadia "<< j << ": " << endl;
            cout << "  - Codigo de la reserva asociada a la estadía: " << (*i).getCodigo()  << endl;
            cout << "  - Email del huesped asociado a la estadía: " << (*i).getEmail()  << endl;
            j++;
        }
        cout << "Para conocer la información de una estadia ingrese los siguientes datos: " << endl;
        int Codigo;
        cout << "  - Código de la reserva asociada: " <<endl; cin >> Codigo;
        std::string emailHuesp;
        cout << "  - Email del huesped asociado:" <<endl; 
        getline(cin >> ws, emailHuesp);
        DTIdEstadia estadia;
        bool existe;
        for (list<DTIdEstadia>::iterator i = IdEstadia.begin(); i != IdEstadia.end(); i++){
            std::string email = (*i).getEmail();
            int cod = (*i).getCodigo();
            if (email.compare(emailHuesp)== 0 && Codigo == cod) {
                estadia = *i;
                existe = true;
                break;
            } 
            else 
                existe = false;
        }
        IdEstadia.clear();
        if (!existe) 
            throw std::invalid_argument("Datos ingresados incorrectos."); 
        else {
            DataEstadia* EstSeleccionada = ctrlHostal->ObtenerinfoEstadia(estadia);
            cout << "__Informacion de la estadia__"<<endl;
            int diaIn = EstSeleccionada->getCheckIn().getDia();
            int mesIn = EstSeleccionada->getCheckIn().getMes();
            int anioIn = EstSeleccionada->getCheckIn().getAnio();
            int horaIn = EstSeleccionada->getCheckIn().getHora();
            int minutoIn = EstSeleccionada->getCheckIn().getMinutos();
            cout << "  - Fecha de ingreso: " << diaIn <<"/"<<mesIn<<"/"<<anioIn<<"-"<<horaIn<<":"<<minutoIn<<endl;
            list<DTIdEstadia> estFinalizadas = ctrlHostal->ListaEstadiasFinalizadas(emailHuesp);
            bool estaFinalizada=false;
            for (auto it = estFinalizadas.begin(); it != estFinalizadas.end(); it++){
                std::string email = (*it).getEmail();
                int cod = (*it).getCodigo();
                if (email.compare(emailHuesp)== 0 && Codigo == cod) 
                    estaFinalizada = true;
            } 
            estFinalizadas.clear();
            if (!estaFinalizada)
                cout << "  - La estadia no ha finalizado"<<endl;
            else {
                int diaOut = EstSeleccionada->getCheckOut().getDia();
                int mesOut = EstSeleccionada->getCheckOut().getMes();
                int anioOut = EstSeleccionada->getCheckOut().getAnio();
                int horaOut = EstSeleccionada->getCheckOut().getHora();
                int minutoOut = EstSeleccionada->getCheckOut().getMinutos();
                cout << "  - Fecha de salida: " << diaOut <<"/"<<mesOut<<"/"<<anioOut<<"-"<<horaOut<<":"<<minutoOut<<endl;
            }
            cout << "  - Huesped asociado: " << EstSeleccionada->getHuesped() <<endl;
            cout << "  - Hostal asociado: " << EstSeleccionada->getHostal() <<endl;
            cout << "  - Habitacion asociada: " << EstSeleccionada->getHabitacion() <<endl;
            cout << "  - Codigo de la reserva asociada: "<< EstSeleccionada->getCod()<<endl;
            cout << " Si desea ver la calificacion de la estadía y la respuesta del empleado ingrese 1, sino ingrese 0."<<endl;
            delete EstSeleccionada;
            std::string verCalif;
            cin >>verCalif;
            if (verCalif != "1" && verCalif != "0")
                throw std::invalid_argument("El dato ingresado no es correcto."); 
            else {
                bool VerCalificacion = (verCalif == "1");
                if (VerCalificacion) {
                    DTCalificacion cal = ctrlHostal->MostrarCalificacion();
                    if (!ctrlHostal->ExisteCalif())
                        cout << "La estadía no ha sido calificada."<<endl;
                    else {
                        cout << "  - Calificacion: " <<cal.getPuntaje()<<endl;
                        cout << "  - Comentario del huesped: "<<cal.getComentarioHuesp()<<endl;
                        if (cal.getComentarioEmp() != "")
                            cout << "  - Comentario del empleado: " << cal.getComentarioEmp() <<endl;
                    }
                }
                cout << "Si desea ver la informacion de la reserva asociada ingrese 1, sino ingrese 0."<<endl;
                std::string verRes;
                cin >>verRes;
                if (verRes != "1" && verRes != "0")
                    throw std::invalid_argument("El dato ingresado no es correcto."); 
                else {
                    bool VerInfoReserva = (verRes == "1");
                    if (VerInfoReserva) {
                        DTReserva* res = ctrlHostal->MostrarInfoReserva(nombreHostal, Codigo);
                        cout << "__Informacion de la reserva__"<<endl;
                        cout << "  - Codigo de la reserva" <<res->getCodigo()<<endl;
                        int diaIn = res->getCheckIn().getDia();
                        int mesIn = res->getCheckIn().getMes();
                        int anioIn = res->getCheckIn().getAnio();
                        int horaIn = res->getCheckIn().getHora();
                        int minutoIn = res->getCheckIn().getMinutos();
                        cout << "  - Fecha de realizada: " << diaIn <<"/"<<mesIn<<"/"<<anioIn<<"-"<<horaIn<<":"<<minutoIn<<endl;
                        int diaOut = res->getCheckOut().getDia();
                        int mesOut = res->getCheckOut().getMes();
                        int anioOut = res->getCheckOut().getAnio();
                        int horaOut = res->getCheckOut().getHora();
                        int minutoOut = res->getCheckOut().getMinutos();
                        cout << "  - Fecha de terminada: " << diaOut <<"/"<<mesOut<<"/"<<anioOut<<"-"<<horaOut<<":"<<minutoOut<<endl;
                        EstadoReserva estado = res->getEstado();
                        switch(estado){
                            case 0: cout << "  - La reserva está abierta"<<endl;
                            break;
                            case 1: cout << "  - La reserva está cerrada"<<endl;
                            break;
                            case 2: cout << "  - La reserva está cancelada"<<endl;
                            break;
                        }
                        delete res;
                    }
                    cout <<endl;
                }
            }
        }
    }
    else 
        throw std::invalid_argument("No hay estadias registradas en ese Hostal."); 

}

void bajaReserva(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    set<std::string> nombres= ctrlHostal->ObtenerNombreHostales();
    cout << "Los hostales registrados en el sistema son:" << endl;
    for (auto it=nombres.begin();it!=nombres.end();++it){
        cout << "  - " << (*it)<<endl;
    }
    nombres.clear();
    string nombreHostal;
    cout << "Ingrese el nombre del hostal elegido: "<<endl;
    getline(cin >> ws, nombreHostal);
    ctrlHostal->SeleccionarHostal(nombreHostal);
    list<DTReserva*> Reservas= ctrlHostal->ObtenerReservas(nombreHostal);
    if(Reservas.empty()){
        throw std::invalid_argument("No hay reservas para cancelar");
    }
    cout<< "Las reservas son:"<<endl;
    for(auto it=Reservas.begin();it!=Reservas.end();it++){
        cout<< "  - Codigo de la reserva:"<< (*it)->getCodigo()<<endl;
    }
    for(auto it=Reservas.begin();it!=Reservas.end();it++){
        delete (*it);
    }
    Reservas.clear();
    int codRes;
    cout<< "Ingrese codigo de la reserva elegida:"<<endl;
    cin>> codRes;
    ctrlHostal->SeleccionarReserva(codRes);
    cout << "Ingrese 1 para confirmar la baja o 0 para cancelar "<<endl;
    std::string confirmo;
    cin >>confirmo;
    if (confirmo != "1" && confirmo != "0")
        throw std::invalid_argument("El dato ingresado no es correcto."); 
    else {
        bool conf = (confirmo == "1");
        if(conf){
            ctrlHostal->ConfirmarEliminarReserva();
            
            cout << "¡BAJA DE LA RESERVA REALIZADA CON EXITO!"<<endl;
            cout <<endl;
        }
        else{
            ctrlHostal->CancelarBajaReserva();
            cout <<endl;
        }
    }
}

void modificarFechaSistema(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
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
    if (dia < 1 || dia>31 || mes<1 || mes>12 || hora<0 || hora>23 || minutos<0 || minutos>59) {
        throw std::invalid_argument("La fecha/hora ingresada no es correcta.");
    }
    ctrlHostal->actualizarFS(anio,mes,dia,hora, minutos);
    cout<< "¡ACTUALIZACION DE FECHA Y HORA DEL SISTEMA REALIZADA CON EXITO!"<<endl;
}

void SuscribirseaNotificaciones(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<DTEmpleado> Emp=ctrlHostal->ObtenerEmpleados();
    cout<< "Los email de los empleados son: "<<endl;
    for (auto it=Emp.begin();it!=Emp.end();it++){
        cout<< "  - "<< (*it).getEmail()<<endl;
    }
    string email;
    cout<< "Ingrese el email del empleado elegido:"<<endl;
    getline(cin >> ws, email);
    ctrlHostal->SuscribirEmpleado(email);
     cout<< "¡SE REALIZO LA SUSCRIPCION CON EXITO!"<<endl;
}

void ConsultaDeNotificaciones(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<IObserver*> Emp=ctrlHostal->ObtenerSuscritos();
    if(Emp.begin()==Emp.end()){
		throw std::invalid_argument ("No existen empleados suscritos.");
	}
	else{
        auto it=Emp.begin();
        cout<< "Los email de los empleados suscritos son:"<<endl;
        while (it!=Emp.end()){
            Empleado* ind= dynamic_cast<Empleado*>((*it));
            if(ind!=NULL){
                cout<< "  - "<< (*ind).getEmail()<<endl;
            }
            ++it;   
        }
        /*while (it!=Emp.end()){
            delete (*it);
            ++it;   
        }
        Emp.clear();*/
        string email;
        cout<< "Ingrese el email del empleado elegido:"<<endl;
        getline(cin >> ws, email);
        list<DTCalificacion> cal=ctrlHostal->ObtenerNotificaciones(email);
        if(cal.begin()==cal.end()){
            cout<< "No hay notificaciones nuevas."<<endl;
        }
        else{
            for(auto it=cal.begin();it!=cal.end();it++){
                cout<< "El puntaje de la calificacion es: "<< (*it).getPuntaje()<<endl;
                cout<< "El comentario de la calificacion es: "<< (*it).getComentarioHuesp()<<endl;
             }
        }
        ctrlHostal->EliminarNotificaciones();  
    }
}

void EliminarSuscripcion(){
    IHostal *ctrlHostal = fabrica->obtenerControladorHostal();
    list<IObserver*> Emp=ctrlHostal->ObtenerSuscritos();
    auto it=Emp.begin();
        cout<< "Los email de los empleados suscritos son:"<<endl;
        while (it!=Emp.end()){
            Empleado* ind= dynamic_cast<Empleado*>((*it));
            if(ind!=NULL){
                cout<< "  - "<< (*ind).getEmail()<<endl;
            }
            ++it;   
        }
    string email;
    cout<< "Ingrese el email del empleado elegido:"<<endl;
    getline(cin >> ws, email);
    ctrlHostal->eliminarSuscripcion(email);
    cout<< "¡SE HA ELIMINADO LA SUSCRIPCION CON EXITO!"<<endl;
}

int convertiraEntero(std::string opcion) {
    int opcionMenu;
    if (opcion == "1") {opcionMenu = 1;}
    else if (opcion == "2") {opcionMenu = 2;}
    else if (opcion == "3") {opcionMenu = 3;}
    else if (opcion == "4") {opcionMenu = 4;}
    else if (opcion == "5") {opcionMenu = 5;}
    else if (opcion == "6") {opcionMenu = 6;}
    else if (opcion == "7") {opcionMenu = 7;}
    else if (opcion == "8") {opcionMenu = 8;}
    else if (opcion == "9") {opcionMenu = 9;}
    else if (opcion == "10") {opcionMenu = 10;}
    else if (opcion == "11") {opcionMenu = 11;}
    else if (opcion == "12") {opcionMenu = 12;}
    else if (opcion == "13") {opcionMenu = 13;}
    else if (opcion == "14") {opcionMenu = 14;}
    else if (opcion == "15") {opcionMenu = 15;}
    else if (opcion == "16") {opcionMenu = 16;}
    else if (opcion == "17") {opcionMenu = 17;}
    else if (opcion == "18") {opcionMenu = 18;}
    else if (opcion == "19") {opcionMenu = 19;}
    else if (opcion == "20") {opcionMenu = 20;}
    else if (opcion == "21") {opcionMenu = 21;}
    else 
        throw std::invalid_argument("Dato ingresado incorrecto.");
    return opcionMenu;
}  

int main(){
    while (opcionMenu != 21){
        try {
        Menu();
        cin >>opcion;
        opcionMenu = convertiraEntero(opcion);        
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
    catch (const std::invalid_argument& e) {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }
    }
    return 0;
}

