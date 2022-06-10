#ifndef IUSUARIO
#define IUSUARIO
#include <iostream>
#include <string>
#include "../../include/clases/Empleado.h"
#include "../../include/clases/Hostal.h"
#include"../../include/datatypes/DTCal.h"
#include"../../include/datatypes/DTHuesped.h"
#include"../../include/datatypes/DataEmpleado.h"
#include"../../include/datatypes/DTEmpleado.h"

class IUsuario {
    public:
        IUsuario();
        ~IUsuario();
        virtual set<DTCal> ObtenerComentariosAResponder(string)=0;
        virtual set<string> obtenerHuespedes()=0;
        virtual void seleccionar(string)=0;
        virtual void IngresarHuesped(string, string, string, bool)=0;
        virtual void IngresarEmpleado(string, string, string, CargoEmpleado)=0;
        virtual void ConfirmarAltaUsuario()=0;
        virtual void CancelarAltaUsuario()=0;
        virtual set<string> ObtenerUsuarios()=0;
        virtual DTHuesped SeleccionarHuesped(string)=0;
        virtual DataEmpleado SeleccionarEmpleado(string)=0;
        virtual set<DTEmpleado> getEmpleados(Hostal)=0;
        virtual Empleado SeleccionarEmpleado(CargoEmpleado, string)=0;
        virtual void AsginarCargoAEmpleado()=0;
        virtual void BuscarHuesped(string)=0;
};

#endif