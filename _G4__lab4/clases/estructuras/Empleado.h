#ifndef EMPLEADO
#define EMPLEADO
#include "Usuario.h"
#include "../../datatypes/tipoEmpleado.h"
#include "../../datatypes/dataEmpleado.h"
#include "../../datatypes/dataCalificacion.h"
#include "../../ICollection/interfaces/IKey.h"
#include <set>

class Hostal;
class Empleado : public Usuario
{
private:
    Hostal *trabajaEn;
    tipoEmpleado tipo;

public:
    Empleado(string _nombre, string _email, string _password, tipoEmpleado _tipo);
    dataEmpleado devolverDatos();
    set<dataCalificacion> listarComentariosHostal();
    void setCargo(tipoEmpleado tipo);
    tipoEmpleado getCargo();
    Hostal *getHostal();
    void setHostal(Hostal *trabajaEn);
};
#endif
