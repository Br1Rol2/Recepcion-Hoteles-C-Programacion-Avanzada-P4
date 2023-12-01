#ifndef RESPUESTA
#define RESPUESTA
#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"

using namespace std;
class Calificacion;
class Empleado;
class Respuesta : public ICollectible
{
private:
    Calificacion *c;
    string respuesta;
    Empleado *e;

public:
    string getRespuesta();
    Respuesta(Calificacion *, string, Empleado *);
};
#endif
