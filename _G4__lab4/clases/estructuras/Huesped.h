#ifndef HUESPED_H
#define HUESPED_H
#include "Usuario.h"
#include "../../datatypes/dataTime.h"
#include "../../datatypes/dataHuesped.h"
#include "../../datatypes/dataEstadia.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "Empleado.h"
#include <set>

class Estadia;
class Reserva;

class Huesped : public Usuario{
    private:
    bool esTecnoPacker;
    IDictionary * reservas;
    IDictionary * estadias;
    public:
        Estadia * getEstadia(int);
        void addEstadia(IKey * k,Estadia*e);
        Huesped(string _nombre, string _email, string _password,bool _esTecnoPacker);
        void eliminarReserva(IKey *);
        dataHuesped devolverDatos();
        bool listarEstadias(string nombre);
        void eliminarEstadia(int estadia);
        void finalizarEstadia(int codigo);
        void calificarEstadia(int codigo,int calificacion, string comentario);
        void ingresarRespuesta(string respuesta,Empleado *,int codigo);
        dataEstadia* listarEstadiasFinalizadas(dataTime checkIn,dataTime checkOut);
        void registrarEstadia(int codigo);
        void agregarReserva( IKey * key, Reserva * r);
        bool getEsTecnoPacker();
        void setEsTecnoPacker(bool _esTecnoPacker);
        IDictionary * getEstadia();
        set <dataEstadia> devolverEstadiasF(string nombre);
        IDictionary * getReservas();
};
#endif