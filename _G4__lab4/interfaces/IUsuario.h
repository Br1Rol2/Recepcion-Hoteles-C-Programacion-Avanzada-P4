#ifndef IUSUARIO
#define IUSUARIO

#include <iostream>
#include "../datatypes/dataHuesped.h"
#include "../datatypes/dataEmpleado.h"
#include "../datatypes/dataEstadia.h"
#include "../datatypes/dataReserva.h"
#include "../datatypes/dataCalificacion.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/ICollection.h"

#include "../clases/estructuras/Empleado.h"
#include "../clases/estructuras/Huesped.h"
#include "../clases/estructuras/Usuario.h"

using namespace std;

class IUsuario
{ // interfaz
protected:
    IUsuario() {}

public:
    virtual bool listarEstadias(string email,string nombre) = 0;
    virtual std::set<string *> listarEmpleados() = 0;
    virtual std::set<dataCalificacion> listarComentarios(string mail) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void finalizarEstadia(int) = 0;
    virtual void ingresarRespuesta(string, string, string, int) = 0;
    // virtual ICollection * listarComentarios(string) = 0;
    // virtual ICollection * listarEstadiasFinalizadas(string,string) = 0;
    virtual std::set<string *> ListarHuespedes() = 0;
    // virtual IDictionary * listarUsuarios() = 0;

    virtual bool existeEmpleado(string email) = 0;
    virtual bool existeHuesped(string email) = 0;
    virtual dataHuesped mostraHuesped() = 0;
    virtual dataEmpleado mostrarEmpleado() = 0;
    virtual bool registrarEmpleado(string, string, string, tipoEmpleado) = 0;
    virtual bool registrarHuesped(string, string, string, bool) = 0;
    virtual void seleccionarHuesped(string) = 0;
    virtual void seleccionarReserva(int, string) = 0;
    virtual void seleccionarUsuario(string) = 0;
    virtual std::set<string *> listarUsuarios() = 0;
    virtual set<dataEstadia> ListarEstadiasFinalizadas(string mail, string nombre) = 0;
    virtual void calificarEstadia(string mail, int codigo, int calificacion, const string comentario) = 0;
    virtual void mostrarDatos() = 0;
    virtual IDictionary *ListarReservasHuesped(string,string) = 0;
    virtual void confirmarAsignacionEmpleadoHostal(string email, string cargo, string nombreH) = 0;
    virtual bool existeUsuario(string nombre) = 0;
    virtual bool seleccionEstadia(string email, int codE) = 0;
    virtual dataReserva mostrarReserva() = 0;
    virtual dataCalificacion mostrarCalificacion() = 0;
};

#endif
