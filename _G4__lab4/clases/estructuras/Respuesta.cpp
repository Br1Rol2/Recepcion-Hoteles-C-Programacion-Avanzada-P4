#include <iostream>
#include "Respuesta.h"
#include "Calificacion.h"
#include "Empleado.h"
using namespace std;

Respuesta::Respuesta(Calificacion * _c, string _respuesta,Empleado * emp){
    c = _c;
    respuesta = _respuesta;
    e = emp;

}
string Respuesta::getRespuesta(){
    return respuesta;
}
