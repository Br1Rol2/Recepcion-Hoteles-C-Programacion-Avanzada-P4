#ifndef ESTADIA
#define ESTADIA
#include <iostream>
#include "../../datatypes/dataTime.h"
#include "../../datatypes/dataPromedio.h"
#include "../../datatypes/dataReserva.h"
#include "../../datatypes/dataEstadia.h"
#include "Calificacion.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "Reserva.h"

using namespace std;

class Huesped;

class Estadia : public ICollectible{
    private:
        static int cantidad;
        dataTime checkIn;
        dataTime checkOut;
        string promo;
        int codigo;
        Reserva * reserva;
        Huesped * huesped;
        Calificacion * calificacion;
    public:

        Estadia(Huesped * h, Reserva * r, string promo);
        void calificarEstadia(int calificacion,string comentario, Huesped *h);
        dataEstadia devolverDatos();
        void finalizar();
        bool finalizoEstadia();
        Calificacion * getCalificacion();
        string getComentario();
        Reserva * getReserva();
        void ingresarRespuesta(string, Empleado *);
        void setCheckIn( dataTime checkIn);
        dataTime getCheckIn() ;
        void setCheckOut( dataTime checkOut);
        dataTime getCheckOut() ;
        void setPromo( string promo);
        string getPromo() ;
        void setCodigo(int codigo);
        int getCodigo();
        void setFechaActual(); 
        ~Estadia();

};
#endif