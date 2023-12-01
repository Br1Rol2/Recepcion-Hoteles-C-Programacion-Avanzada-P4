#ifndef HABITACION
#define HABITACION
#include <set>
#include "../../datatypes/dataTime.h"
#include "../../datatypes/dataReserva.h"
#include "../../datatypes/dataHabitacion.h"
#include "../../datatypes/dataEstadia.h"
#include "../../datatypes/dataPromedio.h"
#include "Huesped.h"
#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/interfaces/IIterator.h"

class Hostal;
class Habitacion : public ICollectible
{
private:
    int numero;
    int capacidad;
    float Hprecio;
    Hostal *ubicacion;
    IDictionary *reservas;

public:
    Habitacion(int numero, int capacidad, float Hprecio);
    Estadia *buscarEstadia(int, int);
    void crearReserva(dataTime, dataTime, bool, IDictionary *);
    set<dataEstadia> devolverEstadias();
    bool eliminarReserva(int);
    bool estaDisponible(dataTime, dataTime);
    float getPromedioCalificaciones();
    IDictionary *getReservas();
    set<dataCalificacion> listarComentariosHostal();
    void setNumero(int numero);
    int getNumero() const;
    void setCapacidad(int capacidad);
    int getCapacidad() const;
    void setHPrecio(float Hprecio);
    float getHPrecio() const;
    void setUbicacion(Hostal *ubicacion);
    Hostal *getUbicacion() const;
};
#endif