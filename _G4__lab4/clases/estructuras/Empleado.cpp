#include "Empleado.h"
#include "Hostal.h"
#include "Usuario.h"
#include "../../datatypes/tipoEmpleado.h"
#include "../../datatypes/dataEmpleado.h"
using namespace std;

Empleado::Empleado(string _nombre, string _email, string _password, tipoEmpleado _tipo) : Usuario(_nombre, _email, _password)
{
    tipo = _tipo;
}

dataEmpleado Empleado::devolverDatos()
{
    // Implementación de devolverDatos
    std::string elCargo;
    switch (this->tipo)
    {
    case tipoEmpleado::administracion:
        elCargo = "administracion";
        break;
    case tipoEmpleado::recepcion:
        elCargo = "recepcion";
        break;
    case tipoEmpleado::limpieza:
        elCargo = "limpieza";
        break;
    case tipoEmpleado::infraestructura:
        elCargo = "infraestructura";
        break;
    }
    dataEmpleado salida = dataEmpleado(this->getName(), this->getEmail(), this->getPassword(), elCargo);
    return salida;
}

set<dataCalificacion> Empleado::listarComentariosHostal()
{
    // Implementación de listarComentariosHostal
    set<dataCalificacion> comentarios;
    comentarios = trabajaEn->listarComentariosHostal();
    return comentarios;
}

void Empleado::setCargo(tipoEmpleado _tipo)
{
    tipo = _tipo;
}

tipoEmpleado Empleado::getCargo()
{
    return tipo;
}

Hostal *Empleado::getHostal()
{
    return trabajaEn;
}

void Empleado::setHostal(Hostal *trabajaEn)
{
    this->trabajaEn = trabajaEn; // agarra la pala pibe
}

// EMPLEADOKEY
