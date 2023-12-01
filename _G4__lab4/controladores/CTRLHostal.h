#ifndef CTRLHOSTAL
#define CTRLHOSTAL
#include "../interfaces/IHostal.h"
using namespace std;
class CTRLHostal : public IHostal {
private:
    Habitacion * habitacion;
    IDictionary * hostales; 
    static CTRLHostal * instance;
    Hostal * h;
    string nombre;
    string direccion;
    string telefono;
    dataTime checkIn,checkOut;
    Estadia * estadia;
    int Hprecio;
    int hab;
    int numero;
    string capacidad;
    dataTime tiempo = dataTime(2002,7,22,15);
    CTRLHostal();
public:
    static CTRLHostal * getInstance();
    Hostal * buscarHostal(string nombre);
    void confirmarAltaHabitacion(int numero, int capacidad, float Hprecio);
    bool existeHostal(string nombre);
    void confirmarAltaHostal(string nombre,string direccion,int telefono);
    void confirmarBajaReserva(int numeroReserva);
    void confirmarReserva(dataTime fecha,dataTime fecha2, bool esGrupal);
    //void buscoHostalparaHabitacion(string nombre);
    //bool CrearNuevoHostal(const string nombre, const string direccion, int telefono);
    dataPromedio infoHostal(const string nombre);
    //!IDictionary * ingresarEstadiaHuesped(const string nombre, const string apellido); // SET(DATARESERVA)
    set<dataEstadia> ListarEstadia(string nombre); // SET DATAESTADIA
    IDictionary * ListarHabitacionesDisponibles(const string nombre, const dataTime fechaInicio, const dataTime fechaFin, bool incluirReservadas); // SET NRO HABITACION
    IDictionary * listarHostales();
    void listarNoEmpladosHostal(const string nombre);//set<dataEmpleado>
    IDictionary * listarReservasHostal(const string nombre); //set<dataReserva>
    //IDictionary * listarTop3();//set<dataPromedio>
    dataPromedio * listarTop3();
    dataCalificacion MuestraCalificacion();
    dataReserva MuestraR();
    void SeleccionEstadia(string nombreH, int numero, int codigoR, int codigoE);
    bool SeleccionarHabitacionReserva(int numeroHab);
    void seleccionarHostal(const string nombre);
    IDictionary * SeleccionarHostal(const string nombre);//set<dataReserva>
    void verDetalles(const string nombre);//set<dataPromedio>
    void modificarFecha(dataTime fecha);
    dataTime getTiempo();
    virtual ~CTRLHostal();
};
#endif
