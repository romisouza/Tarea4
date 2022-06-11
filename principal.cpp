//#include "include/clases/Huesped.h"
#include "include/sistema/ControladorUsuario.h"
//#include "include/sistema/ControladorHostal.h"
//#include "include/datatypes/DTCal.h"
//#include "include/clases/Empleado.h"

#include <string>
#include <iostream>
using namespace std;

int main(){
    try{
        ControladorUsuario *cont = ControladorUsuario::getInstance();
        std::string nombre1,email1,pass1,nombre2,email2,pass2;
        bool esfing1,esfing2; 
        CargoEmpleado carg1 = Administracion;
        CargoEmpleado carg2 = Limpieza;
        CargoEmpleado *cargo1 = &carg1;
        CargoEmpleado *cargo2 = &carg2;
        cout << "nombre";cin >> nombre1;
        cout << "email";cin >> email1;
        cout << "pass";cin >> pass1;
        cont->IngresarEmpleado(nombre1,email1,pass1,cargo1);
        cont->CancelarAltaUsuario();
        cout << cont->getNombreIngresado();
        }catch (const std::invalid_argument& e) {
            std::cout<<"Error: "<<e.what()<<std::endl;
    }
    return 0;
    //cont->IngresarEmpleado(nombre,email,pass,cargo);
    //ControladorHostal *crtl = ControladorHostal::getInstance();
    //crtl->agregarHostal("hola","holi",29156480);
    /*DTFecha A = DTFecha(1,5,2001,15,23);
    DTFecha B = DTFecha(1,5,2001,15,24);
    bool prueba = A.compararFecha(A,B);
    cout << prueba;*/
}