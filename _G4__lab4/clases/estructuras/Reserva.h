// Este Archivo define la toda la estructura para reservas grupales y individuales por igual
#ifndef RESERVA
#define RESERVA
#include "Huesped.h"

#include "../../datatypes/dataTime.h"
#include "../../datatypes/dataReserva.h"
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/estadoReserva.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/IDictionary.h"
using namespace std;
class Habitacion;
class Estadia;
class Reserva : public ICollectible
{
protected:
    static int cantidad;
    int codigo;
    dataTime checkIn;
    dataTime checkOut;
    estadoReserva estado;
    Habitacion *habitacion;
    IDictionary *estadias;
    float costo;

public:
    Estadia *buscarEstadia(int codigo);
    void setHabitacion(Habitacion *);
    Reserva(dataTime, dataTime, estadoReserva);
    static void aumentarCantidad();
    static int getCantidad();
    dataReserva devolverDatos();
    float getPromedioCalificaciones();
    set<dataCalificacion> listarComentariosHostal();
    void registrarEstadia(Huesped *);
    dataTime getCheckIn();
    dataTime getCheckOut();
    estadoReserva getEstado();
    Habitacion *getHabitacion();
    IDictionary *getEstadias();
    virtual ~Reserva();
    int getCodigo();
};

class ReservaGrupal : public Reserva
{
private:
    IDictionary *huespedes;
    IDictionary *estadias;

public:
    IDictionary *getHuespedes();
    ReservaGrupal(dataTime checkIn, dataTime checkOut, estadoReserva estado, IDictionary *huespedes);
    ~ReservaGrupal();
};

class ReservaIndividual : public Reserva
{
private:
    Huesped *huesped;
    Estadia *estadia;

public:
    Huesped *getHuesped();
    ReservaIndividual(dataTime checkIn, dataTime checkOut, estadoReserva estado, Huesped *huesped);
    void setEstadia(Estadia *e);
    ~ReservaIndividual();
};
#endif