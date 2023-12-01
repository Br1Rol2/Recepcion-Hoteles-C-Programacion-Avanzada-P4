#include "Reserva.h"

#include "../../datatypes/dataTime.h"
#include "../../datatypes/dataReserva.h"
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/estadoReserva.h"
#include "../../ICollection/String.h"
#include "Habitacion.h"
#include "Estadia.h"
#include "Hostal.h"
#include "../../ICollection/Integer.h"
#include "../../ICollection/collections/List.h"
#include "../../controladores/CTRLHostal.h"
#include <iostream>
using namespace std;

int Reserva::cantidad = 0;
Estadia *Reserva::buscarEstadia(int codigo)
{
    for (IIterator *it = estadias->getIterator(); it->hasCurrent(); it->next())
    {
        Estadia *e = (Estadia *)it->getCurrent();
        if (e->getCodigo() == codigo)
            return e;
    }
    return NULL;
}
Reserva::Reserva(dataTime checkIn, dataTime checkOut, estadoReserva estado)
{
    estadias = new OrderedDictionary();
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    codigo = cantidad;
    cantidad++;
}

dataTime Reserva::getCheckIn()
{
    return checkIn;
}
dataTime Reserva::getCheckOut()
{
    return checkOut;
}

void Reserva::setHabitacion(Habitacion *h)
{
    habitacion = h;
}

dataReserva Reserva::devolverDatos()
{
    std::set<string> emails;
    string email;
    dataReserva dr;
    if (typeid(*this) == typeid(ReservaIndividual))
    {
        ReservaIndividual *reservaIndividual = static_cast<ReservaIndividual *>(this);
        Huesped *huesped = reservaIndividual->getHuesped();
        if (huesped != NULL)
        {
            email = huesped->getEmail();
            emails.insert(email);
        }
    }
    else
    {
        IDictionary *huespedes;
        huespedes = ((ReservaGrupal *)(this))->getHuespedes();
        emails.clear();
        for (IIterator *it = huespedes->getIterator(); it->hasCurrent(); it->next())
        {
            email = (((Huesped *)(it->getCurrent()))->getEmail());
            emails.insert(email);
        }
    }
    dr = dataReserva(codigo, habitacion->getUbicacion()->getNombre(), emails, habitacion->getNumero(), checkIn, checkOut);
    return dr;
}

float Reserva::getPromedioCalificaciones()
{
    float promedio;
    int contador = 0;
    int acumulador = 0;
    for (IIterator *it = estadias->getIterator(); it->hasCurrent(); it->next())
    {
        Estadia *e = dynamic_cast<Estadia *>(it->getCurrent());
        Calificacion *c = e->getCalificacion();
        if (c != NULL)
        {
            acumulador = acumulador + c->getCalificacion();
            contador++;
        }
    }
    if (contador == 0)
    {
        promedio = -1;
    }
    else
    {
        promedio = acumulador / contador;
    }
    return promedio;
}

set<dataCalificacion> Reserva::listarComentariosHostal()
{
    set<dataCalificacion> comentarios;
    for (IIterator *it = estadias->getIterator(); it->hasCurrent(); it->next())
    {
        Estadia *e = (Estadia *)it->getCurrent();
        Calificacion *c = e->getCalificacion();
        if (c)
        {
            dataCalificacion cal = c->devolverDatos();
            comentarios.insert(cal);
        }
    }
    return comentarios;
}

int Reserva::getCodigo()
{
    return codigo;
}
void Reserva::registrarEstadia(Huesped *huesped)
{
    CTRLHostal *ch = CTRLHostal::getInstance();
    dataTime fechaSistema = ch->getTiempo();

    if (checkIn.dia == fechaSistema.dia && checkIn.mes == fechaSistema.mes && checkIn.anio == fechaSistema.anio)
    {
        Estadia *nuevaE = new Estadia(huesped, this, "");
        Integer *codE = new Integer(nuevaE->getCodigo());
        estadias->add(codE, nuevaE);
        if (typeid(*this) == typeid(ReservaIndividual))
        {
            ReservaIndividual *ri = (ReservaIndividual *)this;
            ri->setEstadia(nuevaE);
        }
    }
    else
    {
        cout << "La fecha del sistema es distinta a la del CheckIn" << endl;
    }
}
void ReservaIndividual::setEstadia(Estadia *e)
{
    estadia = e;
}

IDictionary *Reserva::getEstadias()
{
    return estadias;
}
IDictionary *ReservaGrupal::getHuespedes()
{
    return huespedes;
}

Huesped *ReservaIndividual::getHuesped()
{
    return huesped;
}

Habitacion *Reserva::getHabitacion()
{
    return habitacion;
}

ReservaIndividual::ReservaIndividual(dataTime checkIn, dataTime checkOut, estadoReserva estado, Huesped *huesped) : Reserva(checkIn, checkOut, estado)
{
    this->huesped = huesped;
    Integer *codKey = new Integer(codigo);
    huesped->agregarReserva(codKey, this);
}
ReservaGrupal::ReservaGrupal(dataTime checkIn, dataTime checkOut, estadoReserva estado, IDictionary *huespedes) : Reserva(checkIn, checkOut, estado)
{
    this->huespedes = huespedes;
    Integer *codKey = new Integer(codigo);
    for (IIterator *it = huespedes->getIterator(); it->hasCurrent(); it->next())
    {
        Huesped *h = (Huesped *)it->getCurrent();
        h->agregarReserva(codKey, this);
    }
}

void Reserva::aumentarCantidad()
{
    cantidad = cantidad + 1;
}

int Reserva::getCantidad()
{
    return cantidad;
}

estadoReserva Reserva::getEstado()
{
    return estado;
}

Reserva::~Reserva()
{

    for (IIterator *it = estadias->getIterator(); it->hasCurrent(); it->next())
    {
        Estadia *e = (Estadia *)it->getCurrent();
        delete e;
    }
    delete estadias;
}
ReservaIndividual::~ReservaIndividual()
{
    IKey *cod = new Integer(codigo);
    huesped->eliminarReserva(cod);
}
ReservaGrupal::~ReservaGrupal()
{
    for (IIterator *it = huespedes->getIterator(); it->hasCurrent(); it->next())
    {
        Huesped *h = (Huesped *)it->getCurrent();
        IKey *cod = new Integer(codigo);
        h->eliminarReserva(cod);
    }
}