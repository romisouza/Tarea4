//#include "include/clases/Huesped.h"
#include "include/sistema/ControladorUsuario.h"
//#include "include/datatypes/DTHuesped.h"
#include "include/datatypes/DataEmpleado.h"
#include "include/sistema/ControladorHostal.h"
//#include "include/datatypes/DTCal.h"
//#include "include/clases/Empleado.h"

#include <list>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main(){
    //ALTA DE USUARIO
   /* std::string n1, n2, nombre;
	int tel;
	ControladorHostal *ctrl = ControladorHostal::getInstance();
	ControladorUsuario *cont = ControladorUsuario ::getInstance();
	cont->IngresarHuesped("pedro","@p","kk",1);
	cont->ConfirmarAltaUsuario();
    cout<<"ingrese nombre hostal: ";cin >> n1;
    cout<<"ingrese direccion hostal ";cin >> n2;
    cout<<"ingrese numero de telefono: "; cin>>tel;
    ctrl->agregarHostal(n1,n2,tel);
    ctrl->asignarHab(n1,32,2500,1);
    ctrl->registrarHab();
    DTFecha in = DTFecha(14,6,2022,15,00);
    DTFecha out = DTFecha(17,6,2022,12,30);
    ctrl->ingresarDatosReserva(n1,in,out,0,1);
    ctrl->seleccionarHabitacion(32);
    ctrl->seleccionarHuesped("@p");
    ctrl->confirmarAltaReserva();*/
    //try{
        /*bool esfing1,esfing2; 
        CargoEmpleado carg1 = Administracion;
        CargoEmpleado carg2 = Limpieza;
        CargoEmpleado *cargo1 = &carg1;
        CargoEmpleado *cargo2 = &carg2;
        /*cout << "nombre huesped 1";cin >> n1;
        cout << "email huesped 1";cin >> e1;
        cout << "pass huesped 1";cin >> p1;
        cout << "ESFINGER? 1"; cin >> esfing1;
        cont->IngresarHuesped(n1,e1,p1,esfing1);
        cont->ConfirmarAltaUsuario();
        cout << "nombre huesped 2";cin >> n2;
        cout << "email huesped 2";cin >> e2;
        cout << "pass huesped 2";cin >> p2;
        cout << "ESFINGER? 2"; cin >> esfing2;
        cont->IngresarHuesped(n2,e2,p2,esfing2);
        cont->ConfirmarAltaUsuario();
        cout << "nombre emp 1";cin >> n3;
        cout << "email emp 1";cin >> e3;
        cout << "pass emp 1";cin >> p3;
        cont->IngresarEmpleado(n3,e3,p3,cargo1);
        cont->ConfirmarAltaUsuario();
        cout << "nombre emp 2";cin >> n4;
        cout << "email emp 2";cin >> e4;
        cout << "pass emp 2";cin >> p4;
        cont->IngresarEmpleado(n4,e4,p4,cargo2);
        cont->ConfirmarAltaUsuario();
        set<string> x = cont->ObtenerUsuarios();
        for( set<std::string>::iterator i= x.begin(); i != x.end(); i++){
       		cout << *i <<"\n";
    	}
    	std::string em;
    	cout << "email del huesp" << "\n"; cin >> em;
    	DataEmpleado* y = cont->SeleccionarEmpleado2(em);
    	cout << y->getNombre()<< "\n";
    	cout << y->getEmail()<< "\n";
    	CargoEmpleado* car = y->getCargo();
    	if (*car == 0)
    		cout << "Administracion"<<"\n"; 
    	else if (*car == 1)
    		cout << "Limpieza"<<"\n"; 
    		else if (*car == 2)
    			cout << "Recepcion"<<"\n"; 
    		else if (*car == 3)
    				cout << "Infraestructura"<<"\n"; 
    	//Hostal * hos = y->getHostal();
        //cout << *hos; 
    	//cout << y->getHostal() << "\n";

        //}catch (const std::invalid_argument& e) {
          //  std::cout<<"Error: "<<e.what()<<std::endl;
    	//}*/

//ASIGNAR EMPLEADO A HOSTAL
/*   
   ControladorUsuario *cont = ControladorUsuario::getInstance();   
    std::string n1,n2,n3,n4,e1,e2,e3,e4,p1,p2,p3,p4;
    int tel;
    cout << "nombre emp 1";cin >> n3;
    cout << "email emp 1";cin >> e3;
    cout << "pass emp 1";cin >> p3;
    cont->IngresarEmpleado(n3,e3,p3);
    cont->setTipoUsuario(1);
    cont->ConfirmarAltaUsuario();
    cout << "nombre emp 2";cin >> p1;
    cout << "email emp 2";cin >> p2;
    cout << "pass emp 2";cin >> p4;
    cont->IngresarEmpleado(p1,p2,p4);
    cont->setTipoUsuario(1);
    cont->ConfirmarAltaUsuario();
    ControladorHostal *ctrl = ControladorHostal::getInstance();
    cout<<"ingrese nombre hostal: ";cin>>n1;
    cout<<"ingrese direccion hostal ";cin>>n2;
    cout<<"ingrese numero de telefono: "; cin>>tel;
    ctrl->agregarHostal(n1,n2,tel);
    CargoEmpleado carg1 = Administracion;
    CargoEmpleado *cargo1 = &carg1;
    CargoEmpleado carg2 = Recepcion;
    CargoEmpleado *cargo2 = &carg2;
    list<DTEmpleado> lista = ctrl->ObtenerEmpleados(n1);
    ctrl->SeleccionarEmpleado(cargo1,e3);
    ctrl->ConfirmarAsignacionDeEmpleado();
    lista = ctrl->ObtenerEmpleados(n1);
    ctrl->SeleccionarEmpleado(cargo2,p2);
    ctrl->ConfirmarAsignacionDeEmpleado();

std::string n1, n2, nombre;
int tel, numero, capacidad;
float precio;
ControladorHostal *ctrl = ControladorHostal::getInstance();
    cout<<"ingrese nombre hostal: ";getline(cin,n1,'\n');
    cout<<"ingrese direccion hostal ";getline(cin,n2,'\n');
    cout<<"ingrese numero de telefono: "; cin>>tel;
    ctrl->agregarHostal(n1,n2,tel);
    ctrl->SeleccionarHostal(n1);
    
    
    
    /*set<string> x = ctrl->ObtenerNombreHostales();
        for( set<std::string>::iterator i= x.begin(); i != x.end(); i++){
       		cout << *i <<"\n";
    	}
    cout<<"ingrese hostal elegido: ";cin>>nombre;
    cout<<"ingrese numero de hab ";cin>>numero;
    cout<<"ingrese precio hab: "; cin>>precio;
    cout<<"ingrese capacidad hab: "; cin>>capacidad;
    ctrl->asignarHab(nombre, numero, precio, capacidad);
    ctrl->registrarHab(); */

    //CONSULTA RESERVA
    //ControladorHostal *ctrl = ControladorHostal::getInstance();

    //REALIZAR RESERVA
  /*  ControladorUsuario *cont = ControladorUsuario::getInstance();  
ControladorHostal *ctrl = ControladorHostal::getInstance();
cont->setTipoUsuario(1);
cont->IngresarEmpleado("carlitos","@carlos","holaaa123");
cont->ConfirmarAltaUsuario();
cont->setTipoUsuario(0);
cont->IngresarHuesped("ade","@ade","hola123",1);
cont->ConfirmarAltaUsuario();
cont->IngresarHuesped("didi","didi@gmail.com","holis123",1);
cont->ConfirmarAltaUsuario();
cont->IngresarHuesped("estela","estelis@hotmail.com","holis",0);
cont->ConfirmarAltaUsuario();
ctrl->agregarHostal("hostal morro","avenida brasil 1899",42158747);
ctrl->asignarHab("hostal morro",101,102.3,2);
ctrl->registrarHab();
ctrl->asignarHab("hostal morro",201,202.3,1);
ctrl->registrarHab();
//asignarempleadoahostal
list<DTEmpleado> empleados = ctrl->ObtenerEmpleados("hostal morro");
/*cout << empleados.size();

for (auto i=empleados.begin();i!=empleados.end();++i){
    cout << (*i).getNombre();
}*
/
CargoEmpleado carg1 = Administracion;
CargoEmpleado *cargo1 = &carg1;
ctrl->SeleccionarEmpleado(cargo1,"@carlos");
ctrl->ConfirmarAsignacionDeEmpleado();

DTFecha in = DTFecha(14,6,2022,15,00);
DTFecha out = DTFecha(17,6,2022,12,30);
ctrl->ingresarDatosReserva("hostal morro",in,out,0,1);
list<int> habitaciones = ctrl->obtenerHabitacionesDisponibles(in,out);
for (auto i=habitaciones.begin();i!=habitaciones.end();++i){
    cout << (*i);
}
ctrl->seleccionarHabitacion(201);
list<std::string> emailHuespedes = ctrl->obtenerHuespedesRegistrados();
for (auto i=emailHuespedes.begin();i!=emailHuespedes.end();++i){
    cout << (*i);
}
ctrl->seleccionarHuesped("estelis@hotmail.com");
ctrl->confirmarAltaReserva();
set<DTReserva*> reservasNC = ctrl->ObtenerReservasNC("hostal morro","estelis@hotmail.com",0);
ctrl->ReservaNCElegida(101);
ctrl->DatosHuesped("hostal morro","estelis@hotmail.com");
ctrl->SeleccionarHostal("hostal morro");
list<DTIdEstadia> estfinalizadas = ctrl->ListaEstadiasFinalizadas("estelis@hotmail.com");
DTIdEstadia estadiaselecc;
for (auto it=estfinalizadas.begin();it!=estfinalizadas.end();++it){
  //  cout << (*it).getCodigo();
    //cout << (*it).getEmail();
    estadiaselecc = DTIdEstadia((*it).getCodigo(),(*it).getEmail());
}
ctrl->SeleccionarEstadia(estadiaselecc);
ctrl->ConfirmarCalificacion("el hostal fue muy lindo",1);
list<DTCal> comentariosaresponder = ctrl->ObtenerComentariosAResponder("@carlos");

for (auto it=comentariosaresponder.begin();it!=comentariosaresponder.end();++it){
  cout << (*it).getComentarioHuesp();
}
ctrl->ResponderComentario("estelis@hotmail.com",101,"gracias x dejar una reseña saludos");*/
std::string n1, n2, nombre;
	int tel;
	ControladorHostal *ctrl = ControladorHostal::getInstance();
	ControladorUsuario *cont = ControladorUsuario ::getInstance();
    cont->setTipoUsuario(0);
	cont->IngresarHuesped("pedro","@p","kk",1);
	cont->ConfirmarAltaUsuario();
    ctrl->agregarHostal("hostal morro","avenida brasil 1899",42158747);
    cout <<"Hostal registrado \n";
    ctrl->asignarHab("hostal morro",101,102.3,2);
    ctrl->registrarHab();
    DTFecha in = DTFecha(14,6,2022,15,00);
    DTFecha out = DTFecha(17,6,2022,12,30);
    ctrl->ingresarDatosReserva("hostal morro",in,out,0,1);
    ctrl->seleccionarHabitacion(101);
    ctrl->seleccionarHuesped("@p");
    ctrl->confirmarAltaReserva();
    //Hago estadia
    set<DTReserva*> res = ctrl->ObtenerReservasNC("hostal morro","@p",0);
    for (set<DTReserva*>::iterator i = res.begin(); i != res.end(); i++){
        cout << "CODIGO" <<(*i)->getCodigo()<<"\n";
        cout << "DIA ENTRADA"<<((*i)->getCheckIn()).getDia()<<"\n";
        cout << "MES ENTRADA"<<((*i)->getCheckIn()).getMes()<<"\n";
        cout << "ANIO ENTRADA"<<((*i)->getCheckIn()).getAnio()<<"\n";
        cout << "HORA ENTRADA"<<((*i)->getCheckIn()).getHora()<<"\n";
        cout << "MINUTO ENTRADA"<<((*i)->getCheckIn()).getMinutos()<<"\n";
        cout << "DIA SALIDA"<<((*i)->getCheckOut()).getDia()<<"\n";
        cout << "MES SALIDA"<<((*i)->getCheckOut()).getMes()<<"\n";
        cout << "ANIO SALIDA"<<((*i)->getCheckOut()).getAnio()<<"\n";
        cout << "HORA SALIDA"<<((*i)->getCheckOut()).getHora()<<"\n";
        cout << "MINUTO SALIDA"<<((*i)->getCheckOut()).getMinutos()<<"\n";
        cout << "ESTADO" <<((*i)->getEstado())<<"\n";
    }
    int codigo;
    cout << "Seleccione la reserva: \n"; cin >>codigo;
    ctrl->ReservaNCElegida(codigo);
    set<string> host = ctrl->ObtenerNombreHostales();
    for (set<string>::iterator i = host.begin(); i != host.end(); i++){
		cout << (*i) <<"\n";
	}
    std::string nom = "hostal morro";
    //cout << "selecccione el hostal: \n" ; cin >> nom;
    //cout<<nom;
    list<DTIdEstadia> est = ctrl->ObtenerDTIdEstadia(nom);
    cout<< "ESTADIAS ASOCIADAS A ESE HOSTAL";
    for (list<DTIdEstadia>::iterator i = est.begin(); i != est.end(); i++){
        cout << "CODIGO" << (*i).getCodigo() << "\n";
        cout << "EMAIL" << (*i).getEmail() << "\n";
    }
return 0;
}