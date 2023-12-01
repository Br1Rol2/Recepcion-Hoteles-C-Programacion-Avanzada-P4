#include "Hostal.h"
#include "Empleado.h"
#include "Huesped.h"
#include "Usuario.h"

#include <iostream>
#include "../../datatypes/dataEstadia.h"
#include "../../datatypes/dataHabitacion.h"
#include "Reserva.h"
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/dataHostal.h"
#include "../../datatypes/dataReserva.h"
#include "../../ICollection/Integer.h"

#include "../../ICollection/String.h"

using namespace std;

void Hostal::asignarEmpleado(IKey *k, Empleado *empleado)
{

    empleados->add(k, empleado);
    empleado->setHostal(this);
}

IDictionary *Hostal::getEmpleados()
{
    return empleados;
}

Hostal::Hostal(string _nombre, string _direccion, int _telefono)
{
    habitaciones = new OrderedDictionary();
    empleados = new OrderedDictionary();
    nombre = _nombre;
    direccion = _direccion;
    telefono = _telefono;
}

Estadia *Hostal::buscarEstadia(int numeroH, int codigoR, int codigoE)
{
    Habitacion *h = (Habitacion *)habitaciones->find(new Integer(numeroH));
    return h->buscarEstadia(codigoR, codigoE);
}

Habitacion *Hostal::buscarHabitacion(int nroHabitacion)
{

    Integer *nroK = new Integer(nroHabitacion);
    return (Habitacion *)habitaciones->find(nroK);
}

void Hostal::crearHabitacion(int numero, int capacidad, float Hprecio)
{
    OrderedKey *numKey = new Integer(numero);
    Habitacion *nuevo = new Habitacion(numero, capacidad, Hprecio);

    habitaciones->add(numKey, nuevo);
    nuevo->setUbicacion(this);
}

dataPromedio Hostal::devolverDatosPromedio()
{

    // Implementación de devolverDatosPromedio
    Habitacion *hab;

    int contar = 0;
    int total = 0;
    float promedio = 0;
    int calificacion;
    IIterator *it;
    it = habitaciones->getIterator();
    while (it->hasCurrent())
    {
        hab = dynamic_cast<Habitacion *>(it->getCurrent());
        calificacion = hab->getPromedioCalificaciones();

        if (calificacion != -1)
        {
            total = total + calificacion;
            contar++;
        }
        it->next();
    }
    if (habitaciones->isEmpty() || contar == 0)
    {
        promedio = -1;
    }
    else
    {
        promedio = total / contar;
    }
    return dataPromedio(devolverDatos(), promedio);
}

set<dataEstadia> Hostal::devolverEstadias()
{
    set<dataEstadia> dataEs;
    for (IIterator *it = habitaciones->getIterator(); it->hasCurrent(); it->next())
    {
        Habitacion *h = (Habitacion *)it->getCurrent();
        set<dataEstadia> estsH = h->devolverEstadias();
        dataEs.insert(estsH.begin(), estsH.end());
    }
    return dataEs;
}

IDictionary *Hostal::getHabitaciones()
{
    return habitaciones;
}

string Hostal::devolverNombre()
{
    return this->getNombre();
}

IDictionary *Hostal::devolverReservas()
{
    IDictionary *rHos = new OrderedDictionary(); // todas las reseras de las habitaciones
    IDictionary *rHab = new OrderedDictionary(); // getReserva() de cada habitacion
    Habitacion *h;
    Reserva *r;
    dataReserva *dR;
    for (IIterator *it = habitaciones->getIterator(); it->hasCurrent(); it->next())
    {
        h = (Habitacion *)it->getCurrent();
        rHab = h->getReservas();

        for (IIterator *it2 = rHab->getIterator(); it2->hasCurrent(); it2->next())
        {
            r = (Reserva *)it2->getCurrent();
            dataReserva d = r->devolverDatos();
            cout << endl
                 << d;
            dR = &d;
            rHos->add(new Integer(r->getCodigo()), dR);
        }
    }
    return rHos;
}

void Hostal::eliminarReserva(int codR)
{
    bool elimino = false;
    for (IIterator *it = habitaciones->getIterator(); it->hasCurrent(); it->next())
    {
        Habitacion *h = (Habitacion *)it->getCurrent();
        elimino = h->eliminarReserva(codR);
        if (elimino)
            return;
    }
    cout<<"No existe esa reserva";
}

IDictionary *Hostal::getHabitacionesDisponibles(dataTime checkIn, dataTime checkOut)
{
    IDictionary *disponibles = new OrderedDictionary();
    bool disp;
    Integer *habKey;
    for (IIterator *it = habitaciones->getIterator(); it->hasCurrent(); it->next())
    {
        Habitacion *h = (Habitacion *)it->getCurrent();
        disp = h->estaDisponible(checkIn, checkOut);
        if (disp)
        {
            habKey = new Integer(h->getNumero());
            disponibles->add(habKey, h);
        }
    }
    return disponibles;
}



set<dataCalificacion> Hostal::listarComentariosHostal()
{
    set<dataCalificacion> comentario;
    set<dataCalificacion> commHabitacion;
    Integer *habKey;
    for (IIterator *it = habitaciones->getIterator(); it->hasCurrent(); it->next())
    {
        Habitacion *h = (Habitacion *)it->getCurrent();

        commHabitacion = h->listarComentariosHostal();
        comentario.insert(commHabitacion.begin(), commHabitacion.end());
    }
    return comentario;
}
// Implementación de los getters y setters

void Hostal::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Hostal::getNombre()
{
    return nombre;
}

void Hostal::setDireccion(string direccion)
{
    this->direccion = direccion;
}

string Hostal::getDireccion()
{
    return direccion;
}

void Hostal::setTelefono(int telefono)
{
    this->telefono = telefono;
}

int Hostal::getTelefono()
{
    return telefono;
}

dataHostal Hostal::devolverDatos()
{
    dataHostal infoHostal = dataHostal(nombre, direccion, telefono);
    return infoHostal;
}
