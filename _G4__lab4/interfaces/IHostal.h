#ifndef IHOSTAL
#define IHOSTAL
#include <iostream>
#include <stdlib.h>
#include <set>
#include "../datatypes/dataHuesped.h"
#include "../datatypes/dataEmpleado.h"
#include "../datatypes/dataEstadia.h"
#include "../datatypes/dataHostal.h"
#include "../datatypes/tipoEmpleado.h"
#include "../datatypes/dataPromedio.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../datatypes/dataReserva.h"
#include "../datatypes/dataTime.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../clases/estructuras/Hostal.h"

using namespace std;
class IHostal { // interfaz
protected:
    IHostal(){
    }
public:
    //virtual std::set<string *>ListarHuespedes() = 0;
    virtual void confirmarAltaHabitacion(int numero, int capacidad, float Hprecio) = 0;
    virtual void confirmarAltaHostal(string nombre,string direccion, int telefono) = 0;
    virtual void confirmarBajaReserva(int numeroReserva) = 0;
    virtual void confirmarReserva(dataTime fecha,dataTime fecha2, bool esGrupal) = 0;
    //virtual void buscoHostalparaHabitacion(string nombre) = 0;
    //virtual bool CrearNuevoHostal(const string nombre, const string direccion, int telefono) = 0;
    virtual dataPromedio infoHostal(const string nombre) = 0;
    virtual set<dataEstadia> ListarEstadia(string nombre) = 0; // SET DATAESTADIA
    virtual IDictionary * ListarHabitacionesDisponibles(const string nombre, const dataTime fechaInicio, const dataTime fechaFin, bool incluirReservadas) = 0; // SET NRO HABITACION
    virtual IDictionary * listarHostales() = 0;
   // virtual set<string*> * listarEmpleados()=0;
   // virtual void confirmarAsignacionEmpleadoHostal(string email,string cargo,string nombreH) = 0;
    virtual bool existeHostal(string nombre) = 0;
    virtual void listarNoEmpladosHostal(const string nombre) = 0;//set<dataEmpleado>
    virtual IDictionary * listarReservasHostal(const string nombre) = 0; //set<dataReserva>
    //virtual IDictionary * listarTop3() = 0;//set<dataPromedio>
     virtual dataPromedio * listarTop3() = 0;//set<dataPromedio>
    virtual dataCalificacion MuestraCalificacion() = 0;
    virtual dataReserva MuestraR() = 0;
    virtual void SeleccionEstadia(string nombreH, int numero, int codigoR,int codigoE) = 0;
    virtual bool SeleccionarHabitacionReserva(int numeroHab) = 0;
    virtual void seleccionarHostal(const string nombre) = 0;
    virtual IDictionary * SeleccionarHostal(const string nombre) = 0;//set<dataReserva>
    virtual void verDetalles(const string nombre) = 0;//set<dataPromedio>
    virtual void modificarFecha(dataTime fecha) = 0;
    virtual dataTime getTiempo() = 0;
};
#endif
