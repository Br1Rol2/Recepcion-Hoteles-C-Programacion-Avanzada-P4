#include "Habitacion.h"
#include "Hostal.h"
#include "../../datatypes/dataTime.h"
#include "../../datatypes/dataReserva.h"
#include "../../datatypes/dataHabitacion.h"
#include "../../ICollection/Integer.h"
#include "Huesped.h"
#include "Estadia.h"
#include "Reserva.h"
#include <iostream>

using namespace std;

Habitacion::Habitacion(int _numero, int _capacidad, float _Hprecio)
{
    reservas = new OrderedDictionary();
    numero = _numero;
    capacidad = _capacidad;
    Hprecio = _Hprecio;
}

Estadia *Habitacion::buscarEstadia(int codigoR, int codigoE)
{
    for (IIterator *it = reservas->getIterator(); it->hasCurrent(); it->next())
    {
        Reserva *r;
        r = (Reserva *)it->getCurrent();
        if (r->getCodigo() == codigoR)
        {
            return r->buscarEstadia(codigoE);
        }
    }
    return NULL;
}
void Habitacion::crearReserva(dataTime checkIn, dataTime checkOut, bool esGrupal, IDictionary *huesped)
{
    Reserva *r;
    if (esGrupal)
    {
        r = new ReservaGrupal(checkIn, checkOut, estadoReserva::abierta, huesped);
    }
    else
    {
        Huesped * hu = (Huesped *)huesped->getIterator()->getCurrent();
        r = new ReservaIndividual(checkIn, checkOut, estadoReserva::abierta, hu);
        //IKey * k = new Integer(r->getCodigo());
        //hu->agregarReserva(k,r);
    }
    r->setHabitacion(this);
    reservas->add(new Integer(r->getCodigo()), r);
}

set<dataEstadia> Habitacion::devolverEstadias()
{
    set<dataEstadia> estadias;
    for (IIterator *it = reservas->getIterator(); it->hasCurrent(); it->next())
    {

        Reserva *r;
        r = (Reserva *)it->getCurrent();

        for (IIterator *it2 = r->getEstadias()->getIterator(); it2->hasCurrent(); it2->next())
        {
            Estadia *e;
            e = (Estadia *)it2->getCurrent();
            estadias.insert(e->devolverDatos());
        }
    }
    return estadias;
}

bool Habitacion::eliminarReserva(int codR)
{
    IKey *k = new Integer(codR);
    Reserva *r = (Reserva *)reservas->find(k);
    if (r)
    {
        reservas->remove(k);
        delete r;
        return true;
    }
    else
        return false;
}

bool Habitacion::estaDisponible(dataTime checkIn, dataTime checkOut)
{
    Reserva *r;
    if (reservas == NULL)
        return true;
    for (IIterator *it = reservas->getIterator(); it->hasCurrent(); it->next())
    {
        r = (Reserva *)it->getCurrent();

        dataTime reservaCheckIn = r->getCheckIn();
        dataTime reservaCheckOut = r->getCheckOut();
        // Comprobar si las fechas de la reserva se superponen
        if (checkIn <= reservaCheckOut && reservaCheckIn <= checkOut)
        {
            return false; // Las fechas se superponen, la habitación no está disponible
        }
    }
    return true;
}


float Habitacion::getPromedioCalificaciones()
{
    int contar = 0;
    int total = 0;
    float promedio = 0;
    float calificacion;
    Reserva *r;
    IIterator *it;
    it = reservas->getIterator();
    while (it->hasCurrent())
    {

        r = dynamic_cast<Reserva *>(it->getCurrent());
        calificacion = r->getPromedioCalificaciones();
        if (calificacion != -1)
        {
            total = total + calificacion;
            contar++;
        }
        it->next();
    }
    if (contar == 0)
    {
        promedio = -1;
    }
    else{
        promedio = total / contar;
        }
    return promedio;
}

IDictionary *Habitacion::getReservas()
{
    return reservas;
}

set<dataCalificacion> Habitacion::listarComentariosHostal()
{
    // Implementación de listarComentariosHostal
    set<dataCalificacion> comentario;
    set<dataCalificacion> comReserva;
    Integer *reservaKey;
    for (IIterator *it = reservas->getIterator(); it->hasCurrent(); it->next())
    {
        Reserva *r = (Reserva *)it->getCurrent();
        comReserva = r->listarComentariosHostal();
        comentario.insert(comReserva.begin(), comReserva.end());
    }
    return comentario;
}

void Habitacion::setNumero(int numero)
{
    this->numero = numero;
}

int Habitacion::getNumero() const
{
    return numero;
}

void Habitacion::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

int Habitacion::getCapacidad() const
{
    return capacidad;
}

void Habitacion::setHPrecio(float hPrecio)
{
    this->Hprecio = hPrecio;
}

float Habitacion::getHPrecio() const
{
    return Hprecio;
}

void Habitacion::setUbicacion(Hostal *ubicacion)
{
    this->ubicacion = ubicacion;
}

Hostal *Habitacion::getUbicacion() const
{
    return ubicacion;
}
