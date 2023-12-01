#ifndef DATAPROMEDIO
#define DATAPROMEDIO
#include "dataHostal.h"
#include "dataConsumo.h"
#include "dataCalificacion.h"
#include "dataHabitacion.h"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class dataPromedio
{
public:
    float promedio;
    dataHostal infoHostal;/* 
    dataConsumo consumoH;
    dataCalificacion * calificaciones;
    dataHabitacion infoHabitacion; */
    dataPromedio(dataHostal _infoHostal, float promedio)
    {
        infoHostal = _infoHostal;
        this->promedio = promedio;
    }
    dataPromedio() {}
};
#endif