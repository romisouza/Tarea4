#include "../../include/clases/Huesped.h"
#include "../../include/sistema/ControladorUsuario.h"
#include "../../include/clases/Huesped.h"
#include "../../include/datatypes/DTCal.h"
#include "../../include/clases/Empleado.h"

#include <string>
#include <iostream>
using namespace std;

ControladorUsuario cont = ControladorUsuario();
int main(){
    string nombre;
    string email;
    string pass;
    bool esfing;
    CargoEmpleado cargo;
    cin >> nombre;
    cin >> email;
    cin >> pass;
    cin >> esfing;
    cont.IngresarHuesped(nombre,email,pass,esfing);
    cin >> nombre;
    cin >> email;
    cin >> pass;
    cin >> cargo;
    cont.IngresarEmpleado(nombre,email,pass,cargo);
return 0;
}