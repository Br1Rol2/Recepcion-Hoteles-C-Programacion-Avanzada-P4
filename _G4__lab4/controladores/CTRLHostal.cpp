#include "CTRLHostal.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/List.h"
#include "../clases/estructuras/Hostal.h"
// #include "../clases/estructuras/Habitacion.h"
#include "../ICollection/interfaces/IIterator.h"
#include "../clases/estructuras/Estadia.h"
#include "../ICollection/String.h"
#include "CTRLUsuario.h"
#include <string>

using namespace std;

CTRLHostal::CTRLHostal() : IHostal()
{
    this->hostales = new OrderedDictionary();
}

CTRLHostal *CTRLHostal::instance = nullptr;

CTRLHostal *CTRLHostal::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CTRLHostal();
    }
    return instance;
}

bool CTRLHostal::existeHostal(string nombre)
{
    IKey * k = new String(nombre);
    bool m;
    m = hostales->member(k);
    delete k;
    return m;
}

void CTRLHostal::confirmarAltaHabitacion(int numero, int capacidad, float Hprecio)
{

    if (h == NULL)
    {
        cout << "No existe este hostal" << endl;
        return;
    }
    if (h->buscarHabitacion(numero) == NULL)
    {
        this->numero = numero;
        this->capacidad = capacidad;
        this->Hprecio = Hprecio;

        h->crearHabitacion(numero, capacidad, Hprecio);
    }
    else
    {
        cout << "Habitacion ya registrada" << endl;
    }
}

void CTRLHostal::confirmarAltaHostal(string nombre, string direccion, int telefono)
{
    OrderedKey *nameKey = new String(nombre);
    ICollectible *encontro = hostales->find(nameKey);
    if (encontro == NULL)
    {
        Hostal *nuevo = new Hostal(nombre, direccion, telefono);
        hostales->add(nameKey, nuevo);
    }
    else
    {
        cout << "Hostal ya registrado" << endl;
        delete nameKey;
    }
}

void CTRLHostal::confirmarBajaReserva(int numeroReserva)
{
    h->eliminarReserva(numeroReserva);
}

void CTRLHostal::confirmarReserva(dataTime checkIn, dataTime checkOut, bool esGrupal)
{
    IDictionary *huespedes = CTRLUsuario::getInstance()->huespReserva;
    habitacion->crearReserva(checkIn, checkOut, esGrupal, huespedes);
    CTRLUsuario::getInstance()->huespReserva = NULL;
}

dataPromedio CTRLHostal::infoHostal(const string nombre)
{
    String *k = new String(nombre);
    h = (Hostal *)hostales->find(k);
    delete k;
    return h->devolverDatosPromedio();
}

dataTime CTRLHostal::getTiempo()
{
    return tiempo;
}
set<dataEstadia> CTRLHostal::ListarEstadia(string nombre)
{
    set<dataEstadia> estadias;

    String *k = new String(nombre);
    Hostal *h = dynamic_cast<Hostal *>(hostales->find(k));
    if (h != nullptr)
    {
        estadias = h->devolverEstadias();
    }
    delete k;
    return estadias;
}

IDictionary *CTRLHostal::ListarHabitacionesDisponibles(const string nombre, const dataTime fechaInicio, const dataTime fechaFin, bool incluirReservadas)
{
    this->checkIn = fechaInicio;
    this->checkOut = fechaFin;
    String *hkey = new String(nombre);
    h = (Hostal *)hostales->find(hkey);

    IDictionary *habDisp = h->getHabitacionesDisponibles(fechaInicio, fechaFin);
    delete hkey;
    return habDisp;
}

IDictionary *CTRLHostal::listarHostales()
{
    if (hostales->isEmpty())
    {
        cout << "No hay hostales registrados." << endl;
        return NULL;
    }
    IDictionary *nombres = new OrderedDictionary();
    IIterator *it;
    it = hostales->getIterator();
    while (it->hasCurrent())
    {
        string nombre = dynamic_cast<Hostal *>(it->getCurrent())->getNombre();

        String *clave = new String(nombre);
        nombres->add(clave, clave);
        cout << nombre << endl;
        it->next();
    }
    return nombres;
}

void CTRLHostal::listarNoEmpladosHostal(const string nombre)
{
    IKey *hkey = new String(nombre);
    h = (Hostal *)hostales->find(hkey);
    delete hkey;

} // set<dataEmpleado>
IDictionary *CTRLHostal::listarReservasHostal(const string nombre)
{
    IDictionary *r = new OrderedDictionary();

    IKey *k = new String(nombre);
    h = (Hostal *)hostales->find(k);
    r = h->devolverReservas();
    delete k;
    return r;
}

dataPromedio *CTRLHostal::listarTop3()
{
    dataPromedio *top3 = new dataPromedio[3];

    for (int i = 0; i < 3; i++)
    {
        top3[i].promedio = -10;
    }

    if (hostales->isEmpty())
    {
        cout << "No hay hostales registrados." << endl;
        return NULL;
    }
    IIterator *it;
    it = hostales->getIterator();
    while (it->hasCurrent())
    {
        Hostal *ho = dynamic_cast<Hostal *>(it->getCurrent());
        dataPromedio promedio = ho->devolverDatosPromedio();

        if (promedio.promedio >= top3[0].promedio)
        {
            top3[2] = top3[1];
            top3[1] = top3[0];
            top3[0] = promedio;
        }
        else if (promedio.promedio >= top3[1].promedio)
        {

            top3[2] = top3[1];
            top3[1] = promedio;
        }
        else if (promedio.promedio >= top3[2].promedio)
        {
            top3[2] = promedio;
        }
        it->next();
    }
    for (int i = 0; i < 3; i++)
    {
        cout << top3[i].infoHostal;
        cout << "Promedio: ";
        if (top3[i].promedio == -1)
        {
            cout << "S/N";
        }
        else
            cout << top3[i].promedio;
        cout << endl
             << endl;
    }
    return top3;
}

dataCalificacion CTRLHostal::MuestraCalificacion()
{
    Calificacion *c = estadia->getCalificacion();
    return c->devolverDatos();
}
dataReserva CTRLHostal::MuestraR()
{
    Reserva *r = estadia->getReserva();
    return r->devolverDatos();
}
void CTRLHostal::SeleccionEstadia(string nombreH, int numero, int codigoR, int codigoE)
{
    IKey *k = new String(nombreH);
    h = (Hostal *)hostales->find(k);
    delete k;
}

bool CTRLHostal::SeleccionarHabitacionReserva(int numeroHab)
{
    habitacion = h->buscarHabitacion(numeroHab);
    if (habitacion == NULL)
    {
        cout << "Habitacion no existente";
        return false;
    }
    if (habitacion->estaDisponible(checkIn, checkOut))
    {
        return true;
    }
    else
    {
        cout << "La habitacion seleccionada no esta disponible en esa fecha";
    }
    return false;
}

Hostal *CTRLHostal::buscarHostal(string nombre)
{

    OrderedKey *k = new String(nombre);
    h = (Hostal *)hostales->find(k);
    delete k;
    return h;
}

void CTRLHostal::seleccionarHostal(const string nombre)
{
    OrderedKey *k = new String(nombre);
    h = (Hostal *)hostales->find(k);
    delete k;
}

IDictionary *CTRLHostal::SeleccionarHostal(const string nombre)
{
    OrderedKey *k = new String(nombre);
    h = (Hostal *)hostales->find(k);
    delete k;
    return h->devolverReservas();
} // set<dataReserva>
void CTRLHostal::verDetalles(const string nombre)
{
    OrderedKey * k = new String(nombre);
    Hostal *Ho = (Hostal *)hostales->find(k);
    cout << Ho->getNombre() << endl;
    cout << Ho->getTelefono() << endl;
    cout << Ho->getDireccion() << endl;
    delete k;
}
void CTRLHostal::modificarFecha(dataTime _fecha)
{
    tiempo = _fecha;
}
CTRLHostal ::~CTRLHostal() {}
