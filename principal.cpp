//#include "include/clases/Huesped.h"
#include "include/sistema/ControladorUsuario.h"
//#include "include/datatypes/DTHuesped.h"
#include "include/datatypes/DataEmpleado.h"
#include "include/sistema/ControladorHostal.h"
//#include "include/datatypes/DTCal.h"
//#include "include/clases/Empleado.h"

#include <string>
#include <iostream>
using namespace std;

int main(){
    //ALTA DE USUARIO
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
   /* ControladorUsuario *cont = ControladorUsuario::getInstance();   
    std::string n1,n2,n3,n4,e1,e2,e3,e4,p1,p2,p3,p4;
    int tel;
    cout << "nombre emp 1";cin >> n3;
    cout << "email emp 1";cin >> e3;
    cout << "pass emp 1";cin >> p3;
    cont->IngresarEmpleado(n3,e3,p3);
    cont->setTipoUsuario(1);
    cont->ConfirmarAltaUsuario();
    ControladorHostal *ctrl = ControladorHostal::getInstance();
    cout<<"ingrese nombre hostal: ";cin>>n1;
    cout<<"ingrese direccion hostal ";cin>>n2;
    cout<<"ingrese numero de telefono: "; cin>>tel;
    ctrl->agregarHostal(n1,n2,tel);
    CargoEmpleado carg1 = Administracion;
    CargoEmpleado *cargo1 = &carg1;
    list<DTEmpleado> lista = ctrl->ObtenerEmpleados(n1);
    ctrl->SeleccionarEmpleado(cargo1,e3);
    ctrl->ConfirmarAsignacionDeEmpleado();
*/
std::string n1, n2;
int tel;
ControladorHostal *ctrl = ControladorHostal::getInstance();
    cout<<"ingrese nombre hostal: ";cin>>n1;
    cout<<"ingrese direccion hostal ";cin>>n2;
    cout<<"ingrese numero de telefono: "; cin>>tel;
    ctrl->agregarHostal(n1,n2,tel);
//ctrl->ObtenerNombreHostales();
    return 0;
}