#ifndef CALIFICACION
#define CALIFICACION
#include <string>
#include <ctime>
#include <iostream>
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/dataCalificacion.h"
#include "Respuesta.h"
using namespace std;
class Estadia;
class Huesped;

class Calificacion {
private:
    int calificacion;
    Respuesta * respuesta;
    Huesped * huesped;
    Estadia * estadia;
    string comentario;
    dataTime fecha;
public:
    Calificacion(int,string,Huesped*,Estadia*,dataTime);
    dataCalificacion devolverDatos();
    string getComentario();
    int getCalificacion();
    void setComentario(string comentario);
    void setCalifica(int calificacion);
    void ingresarRespuesta(string respuesta,Empleado * e);
    Respuesta * getRespuesta();
    ~Calificacion(){
        delete respuesta;
    }
};
#endif

