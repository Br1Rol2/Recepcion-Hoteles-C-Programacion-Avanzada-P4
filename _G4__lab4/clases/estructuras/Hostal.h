#ifndef HOSTAL
#define HOSTAL
#include <iostream>
#include <cstdlib>
#include <set>
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/OrderedKey.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../datatypes/dataEstadia.h"
#include "../../datatypes/dataHabitacion.h"
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/dataHostal.h"
#include "../../datatypes/dataReserva.h"
#include "../../datatypes/dataHabitacion.h"
#include "Empleado.h"
#include "Huesped.h"
#include "Usuario.h"
#include "Habitacion.h"

class Hostal : public ICollectible
{
private:
    string nombre;
    string direccion;
    int telefono;
    IDictionary *habitaciones;
    IDictionary *empleados;

public:
    IDictionary *getEmpleados();
    Hostal(string nombre, string direccion, int telefono);
    void setTelefono(int telefono);
    int getTelefono();
    void setNombre(string nombre);
    string getNombre();
    void setDireccion(string direccion);
    string getDireccion();
    void asignarEmpleado(IKey *, Empleado *);
    Estadia *buscarEstadia(int, int, int);
    Habitacion *buscarHabitacion(int nroHabitacion);
    void crearHabitacion(int, int, float);
    dataPromedio devolverDatosPromedio();
    set<dataEstadia> devolverEstadias();
    string devolverNombre();
    IDictionary *devolverReservas();
    void eliminarReserva(int);
    IDictionary *getHabitacionesDisponibles(dataTime, dataTime);
    dataHostal devolverDatos();
    IDictionary *getHabitaciones();
    set<dataCalificacion> listarComentariosHostal();
};

#endif