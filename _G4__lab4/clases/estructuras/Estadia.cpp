#include "Estadia.h"
#include "Habitacion.h"
#include <iostream>
#include "../../datatypes/dataTime.h"
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/dataReserva.h"
#include "../../datatypes/dataEstadia.h"
#include "Hostal.h"
#include "../../controladores/CTRLHostal.h"
#include "../../ICollection/Integer.h"
#include <ctime>
#include <iostream>
using namespace std;

int Estadia::cantidad = 0;

Estadia::Estadia(Huesped *h, Reserva *r, string promo)
{
    huesped = h;
    reserva = r;
    this->promo = promo;
    this->checkIn = CTRLHostal::getInstance()->getTiempo();
    codigo = cantidad;
    cantidad++;
    h->addEstadia(new Integer(codigo), this);
}

void Estadia::calificarEstadia(int calificacion, string comentario, Huesped *h)
{
    if (this->calificacion != NULL)
    {
        cout << "Estadia ya calificada, se modificara la calificacion";
        delete this->calificacion;
    }
    this->calificacion = new Calificacion(calificacion, comentario, h, this, CTRLHostal::getInstance()->getTiempo());
}
dataEstadia Estadia::devolverDatos()
{
    // dataEstadia(int _codReserva,string _nombreHostal,string _emailHuesped,int _nroHabitacion,dataTime _checkin, dataTime _checkout,bool _promo,int _cantConsumo, int _codigoEstadia){
    string nombreH = reserva->getHabitacion()->getUbicacion()->getNombre();
    return dataEstadia(reserva->getCodigo(), nombreH, huesped->getEmail(), reserva->getHabitacion()->getNumero(), checkIn, checkOut, promo, codigo);
}

void Estadia::finalizar()
{
    checkOut = CTRLHostal::getInstance()->getTiempo();
}

bool Estadia::finalizoEstadia()
{
    return !(checkOut.empty());
}

Calificacion *Estadia::getCalificacion()
{
    return calificacion;
}

string Estadia::getComentario()
{
    if (calificacion)
    {
        if (calificacion->getRespuesta() == NULL)
        {
            return calificacion->getComentario();
        }
    }

    return "";
}

Reserva *Estadia::getReserva()
{
    return reserva;
}

void Estadia::ingresarRespuesta(string respuesta, Empleado *e)
{
    calificacion->ingresarRespuesta(respuesta, e);
}

void Estadia::setCheckIn(dataTime checkIn)
{
    this->checkIn = reserva->getCheckIn();
}

dataTime Estadia::getCheckIn()
{
    return checkIn;
}

void Estadia::setCheckOut(dataTime checkOut)
{
    this->checkOut = reserva->getCheckOut();
}

dataTime Estadia::getCheckOut()
{
    return checkOut;
}

void Estadia::setPromo(string promo)
{
    this->promo = reserva->getPromedioCalificaciones();
}

string Estadia::getPromo()
{
    return promo;
}

void Estadia::setCodigo(int codigo)
{
    this->codigo = reserva->getCodigo();
}

int Estadia::getCodigo()
{
    return codigo;
}

void Estadia::setFechaActual()
{
    time_t tiempoActual = time(0);
    tm *tiempoLocal = localtime(&tiempoActual);
    this->checkOut.anio = tiempoLocal->tm_year + 1900; // Añade 1900 al año
    this->checkOut.mes = tiempoLocal->tm_mon + 1;      // Los meses comienzan desde 0
    this->checkOut.dia = tiempoLocal->tm_mday;
    this->checkOut.hora = tiempoLocal->tm_hour;
}
Estadia::~Estadia()
{
    huesped->eliminarEstadia(codigo);
    delete calificacion;
}