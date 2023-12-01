#include "Calificacion.h"
#include <iostream>
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/dataCalificacion.h"
#include "../../datatypes/dataTime.h"
#include "Respuesta.h"
#include "Huesped.h"
#include "Estadia.h"
using namespace std;

dataCalificacion Calificacion::devolverDatos()
{
    dataCalificacion datos;
    datos.setCalificacion(calificacion);
    datos.setComentario(comentario);
    datos.setFecha(fecha);
    datos.huesped = huesped->getEmail();
    datos.codEstadia = estadia->getCodigo();
    return datos;
}

/* dataCalificacion Calificacion::getCalificacion() {
    dataCalificacion datos;
    datos.setCalificacion(calificacion);
    datos.setComentario (comentario);
    datos.setFecha(fecha);
    return datos;
} */
Respuesta *Calificacion::getRespuesta()
{
    return respuesta;
}
string Calificacion::getComentario()
{
    return comentario;
}

int Calificacion::getCalificacion()
{
    return calificacion;
}

void Calificacion::setComentario(string comentario)
{
    this->comentario = comentario;
}

void Calificacion::setCalifica(int calificacion)
{
    this->calificacion = calificacion;
}

void Calificacion::ingresarRespuesta(string respuesta, Empleado *e)
{
    this->respuesta = new Respuesta(this, respuesta, e);
}

Calificacion::Calificacion(int cal, string comm, Huesped *h, Estadia *e, dataTime f)
{
    calificacion = cal;
    comentario = comm;
    huesped = h;
    estadia = e;
    fecha = f;
}