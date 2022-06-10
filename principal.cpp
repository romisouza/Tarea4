//#include "include/clases/Huesped.h"
//#include "include/sistema/ControladorUsuario.h"
#include "include/sistema/ControladorHostal.h"
//#include "include/datatypes/DTCal.h"
//#include "include/clases/Empleado.h"

#include <string>
#include <iostream>
using namespace std;

int main(){
   /* ControladorUsuario *cont = ControladorUsuario::getInstance();
    std::string nombre;
    std::string email;
    std::string pass;
    bool esfing;
    CargoEmpleado cargo;
    cin >> nombre;
    cin >> email;
    cin >> pass;
    cin >> esfing;
    cont->IngresarHuesped(nombre,email,pass,esfing);
    cin >> nombre;
    cin >> email;
    cin >> pass;
    //cin >> cargo;
    cargo = Infraestructura;
    cont->IngresarEmpleado(nombre,email,pass,cargo);*/
    ControladorHostal *crtl = ControladorHostal::getInstance();
    crtl->agregarHostal("hola","holi",29156480);

return 0;
}