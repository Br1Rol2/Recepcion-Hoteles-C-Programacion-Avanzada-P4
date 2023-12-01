#ifndef DATACALIFICACION
#define DATACALIFICACION
#include "dataTime.h"
#include <iostream>
#include <string.h>
using namespace std;
class dataCalificacion
{

public:
    int calificacion;
    dataTime fecha;
    string comentario;
    string huesped;
    int codEstadia;

    dataCalificacion()
    {
    }
    dataCalificacion(int _calificacion, dataTime _fecha, string _comentario)
    {
        calificacion = _calificacion;
        fecha = _fecha;
        comentario = _comentario;
    }

    // builder parametrizado para acceso rapido
    dataCalificacion(int _calificacion, int anio, int mes, int dia, int hora, string _comentario)
    {
        calificacion = _calificacion;
        fecha = dataTime(anio, mes, dia, hora);
        comentario = _comentario;
    }

    // getters
    int getCalificacion() const
    {
        return calificacion;
    }
    dataTime getFecha() const
    {
        return fecha;
    }
    string getComentario() const
    {
        return comentario;
    }

    // setters
    void setCalificacion(int _calificacion)
    {
        calificacion = _calificacion;
    }
    void setFecha(dataTime _fecha)
    {
        fecha = _fecha;
    }
    void setComentario(string _comentario)
    {
        comentario = _comentario;
    }
    // setter paramatrizado para cambio rapido de fecha
    void setFecha(int anio, int mes, int dia, int hora)
    {
        fecha = dataTime(anio, mes, dia, hora);
    }
    friend bool operator<(const dataCalificacion &lhs, const dataCalificacion &rhs)
    {
        // Comparación basada en algún criterio, por ejemplo, por código de reserva
        return lhs.calificacion < rhs.calificacion;
    }
};
#endif