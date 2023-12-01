#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include "Fabrica.h"
#include "ICollection/String.h"
#include <limits>

using namespace std;
bool comparar(dataTime fecha, dataTime fecha2);
bool operator<=(const dataTime &dt1, const dataTime &dt2)
{
    if (dt1.anio < dt2.anio)
    {
        return true;
    }
    else if (dt1.anio > dt2.anio)
    {
        return false;
    }
    else
    {
        if (dt1.mes < dt2.mes)
        {
            return true;
        }
        else if (dt1.mes > dt2.mes)
        {
            return false;
        }
        else
        {
            if (dt1.dia < dt2.dia)
            {
                return true;
            }
            else if (dt1.dia > dt2.dia)
            {
                return false;
            }
            else
            {
                if (dt1.hora <= dt2.hora)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const dataTime &dt)
{
    os << std::setfill('0');
    os << std::setw(2) << dt.hora << "h "
       << std::setw(2) << dt.dia << "-"
       << std::setw(2) << dt.mes << "-"
       << std::setw(2) << dt.anio;

    return os;
}
void ingresarNum(int &num)
{
    while (true)
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "(DEBE INGRESAR SOLO NUMEROS): ";
        }
        else
        {
            cin.clear();
            cin.ignore();
            return;
        }
    }
}

void ingresarNumfloat(float &num)
{
    while (true)
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "(DEBE INGRESAR SOLO NUMEROS): ";
        }
        else
        {
            cin.clear();
            cin.ignore();
            return;
        }
    }
}

bool confirmar()
{
    char confirma = '0';
    while (confirma != 'S' && confirma != 's' && confirma != 'N' && confirma != 'n')
    {
        cout << "(S/N): ";
        cin >> confirma;
        if (confirma == 'S' || confirma == 's')
        {
            cin.clear();
            cin.ignore();
            return true;
        }
    }
    cin.clear();
    cin.ignore();
    return false;
}

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char const *argv[])
{
    bool datosCargados = false;
    IHostal *h;
    dataTime fecha;
    dataTime fecha2;
    IUsuario *u;
    Fabrica *fab;
    string desicion;
    // string *auxMail;
    std::set<string *> emails;
    dataCalificacion c;
    std::set<dataCalificacion> comentarios;
    set<string> emailsReserva;
    std::set<string *>::iterator it;
    bool encontro;
    int codigoE, codigoR;
    // char *nombreChar;
    int opcion;
    string email;
    int numero, capacidad;
    float Hprecio;
    string nombre, direccion, mail, cargo, password;
    int telefono;
    set<dataEstadia> ests;
    // dataEstadia seleccionE;
    // String *nombrekey;
    bool existe;
    IDictionary *reservasHostal;
    // dataReserva * auxReserva;
    dataPromedio dataP;

    u = fab->getIUsuario();
    h = fab->getIHostal();

    do
    {
        cout << "____________________________________\n";
        cout << "|_______________MENU_______________|\n";
        cout << "|   1.  Alta de Usuario            |\n";
        cout << "|   2.  Alta de Hostal             |\n";
        cout << "|   3.  Alta de Habitación         |\n";
        cout << "|   4.  Asignar empleado a hostal  |\n";
        cout << "|   5.  Realizar Reserva           |\n";
        cout << "|   6.  Consultar top 3 de hostales|\n";
        cout << "|   7.  Registrar estadía          |\n";
        cout << "|   8.  Finalizar Estadía          |\n";
        cout << "|   9.  Calificar estadía          |\n";
        cout << "|   10. Comentar calificación      |\n";
        cout << "|   11. Consulta de Usuario        |\n";
        cout << "|   12. Consulta de Hostal         |\n";
        cout << "|   13. Consulta de Reserva        |\n";
        cout << "|   14. Consulta de Estadía        |\n";
        cout << "|   15. Baja de reserva            |\n";
        cout << "|   16. Modificar Fecha del Sistema|\n";
        cout << "|   17. Salir                      |\n";
        if (!datosCargados)
            cout << "|   18. Cargar datos de prueba     |\n";
        cout << "------------------------------------" << endl;
        cout << "Ingresar numero de opcion: ";
        ingresarNum(opcion);

        switch (opcion)
        {
        case 1:
            // Agrega aquí el código para realizar la alta de usuario
            cout << "Ingrese el email.\n";
            // cin>>mail;
            getline(cin, mail);
            if (u->existeUsuario(mail))
            {
                cout << "Usuario ya registrado";
                break;
            }
            cout << "Ingrese el password.\n";
            // cin>>password;
            getline(cin, password);

            cout << "Ingrese el nombre.\n";
            // cin>>nombre;
            getline(cin, nombre);

            cout << "Desea registrar un huesped o un empleado? Escriba huesped o empleado: " << endl;
            do
            {
                getline(cin, desicion);
                if (desicion == "huesped")
                {
                    encontro = u->registrarHuesped(mail, nombre, password, true);
                    if (!encontro)
                        u->confirmarAltaUsuario();
                }
                else if (desicion == "empleado")
                {
                    encontro = u->registrarEmpleado(mail, nombre, password, tipoEmpleado::administracion);
                    if (!encontro)
                        u->confirmarAltaUsuario();
                }
                else
                    cout << "Opcion invalida, vuelva a ingresar" << endl;
            } while (desicion != "huesped" && desicion != "empleado");
            break;
        case 2:
            system("clear");
            cout << "Ha seleccionado Alta de Hostal.\n";
            // Agrega aquí el código para realizar la alta de hostal
            cout << "Ingrese el nombre: ";
            getline(cin, nombre);

            if (h->existeHostal(nombre))
            {
                cout << "Hostal existente";
                break;
            }
            cout << "Ingrese la direccion: ";
            getline(cin, direccion);

            cout << "Ingrese el telefono: ";
            ingresarNum(telefono);
            h->confirmarAltaHostal(nombre, direccion, telefono);

            break;
        case 3:
            system("clear");
            cout << "Ha seleccionado Alta de Habitación.\n";
            // Agrega aquí el código para realizar la alta de habitación
            cout << "   Hostales: " << endl;
            h->listarHostales();
            cout << "Ingrese el nombre del Hostal: ";
            getline(cin, nombre);
            if (!(h->existeHostal(nombre)))
            {
                cout << "Hostal no existente";
                break;
            }
            h->seleccionarHostal(nombre);
            cout << "Ingrese numero de la habitacion: " << endl;
            ingresarNum(numero);

            cout << "Ingrese capacidad: " << endl;
            ingresarNum(capacidad);
            cout << "Ingrese precio" << endl;
            ingresarNumfloat(Hprecio);
            h->confirmarAltaHabitacion(numero, capacidad, Hprecio);

            break;
        case 4:
            cout << "Ha seleccionado Asignar empleado a hostal.\n";
            cout << "    Hostales:" << endl;
            if (!(h->listarHostales()))
            {
                break;
            }

            cout << "Ingrese el nombre del hostal: ";
            getline(cin, nombre);
            if (!(h->existeHostal(nombre)))
            {
                cout << "Hostal no existente";
                break;
            }
            cout << "    Empleados:" << endl;
            u->listarEmpleados();
            cout << "Ingrese el email.\n";
            getline(cin, mail);
            if (!(u->existeUsuario(mail)))
            {
                cout << "Usuario no registrado";
                break;
            }
            cout << "Ingrese el cargo por numero.\n";
            cout << "-1. Administracion: " << endl;
            cout << "-2. Infraestructura: " << endl;
            cout << "-3. Limpieza: " << endl;
            cout << "-4. Recepcion: " << endl;
            do
            {
                cout << "Ingrese el numero: ";
                ingresarNum(telefono); // USO TELEFONO COMO CARGO POR QUE NECESITABA UN INT
                if ((!(telefono > 0 || telefono <= 4)))
                {
                    cout << "Cargo invalido.";
                }
            } while (!(telefono > 0 || telefono <= 4));
            switch (telefono)
            {
            case 1:
                cargo = "administracion";
                break;
            case 2:
                cargo = "infraestructura";
                break;
            case 3:
                cargo = "limpieza";
                break;
            case 4:
                cargo = "recepcion";
                break;
            default:
                break;
            }
            u->confirmarAsignacionEmpleadoHostal(mail, cargo, nombre);

            break;
        case 5:
            cout << "Ha seleccionado Realizar Reserva.\n";
            cout << "    Hostales:" << endl;
            if (h->listarHostales() != NULL)
            {
                cout << "Ingrese el nombre del Hostal: ";
                getline(cin, nombre);
                if (!(h->existeHostal(nombre)))
                {
                    cout << "Hostal no registrado";
                    break;
                }

                cout << "Ingrese el CheckIn" << endl;
                cout << "Ingresar hora: ";
                ingresarNum(fecha.hora);

                cout << "Ingresar dia: ";
                ingresarNum(fecha.dia);

                cout << "Ingresar mes: ";
                ingresarNum(fecha.mes);

                cout << "Ingresar año: ";
                ingresarNum(fecha.anio);

                if (comparar(fecha, h->getTiempo()))
                {
                    cout << "No se pueden hacer reservas en una fecha anterior a la del sistema" << endl;
                    break;
                }

                cout << "Ingrese el CheckOut" << endl;
                cout << "Ingresar hora: ";
                ingresarNum(fecha2.hora);

                cout << "Ingresar dia: ";
                ingresarNum(fecha2.dia);

                cout << "Ingresar mes: ";
                ingresarNum(fecha2.mes);

                cout << "Ingresar año: ";
                ingresarNum(fecha2.anio);

                if (!comparar(fecha, fecha2))
                {
                    cout << "La fecha de checkOut es menor a la fecha del checkIn" << endl;
                    break;
                }
                cout << "Es grupal?";
                existe = confirmar();
                IDictionary *habDisp = h->ListarHabitacionesDisponibles(nombre, fecha, fecha2, existe);
                cout << " Habitaciones disponibles:" << endl;
                for (IIterator *it = habDisp->getIterator(); it->hasCurrent(); it->next())
                {
                    Habitacion *hab = (Habitacion *)it->getCurrent();
                    cout << hab->getNumero() << endl;
                }
                if (!(habDisp->isEmpty()))
                {

                    cout << "Ingrese el nro de la habitacion: ";
                    ingresarNum(numero);
                    if (h->SeleccionarHabitacionReserva(numero))
                    {
                        if (u->ListarHuespedes().empty())
                        {
                            break;
                        }
                        cout << "Ingrese el email del huesped: ";
                        getline(cin, mail);
                        if (!u->existeHuesped(mail))
                        {
                            cout << "No existe huesped con este email" << endl;
                            break;
                        }
                        else
                        {
                            emailsReserva.insert(mail);
                            u->seleccionarHuesped(mail);
                        }
                        if (existe)
                        {
                            encontro = true;
                            while (encontro)
                            { // IR AGREGANDO HUESPEDES
                                cout << "Desea agregar mas huespedes?: ";
                                encontro = confirmar();
                                if (encontro)
                                {
                                    cout << "Ingrese el email del huesped: ";
                                    getline(cin, mail);
                                    if (!u->existeHuesped(mail))
                                    {
                                        cout << "No existe hueped con este email" << endl;
                                        break;
                                    }
                                    else
                                    {
                                        emailsReserva.insert(mail);
                                        u->seleccionarHuesped(mail);
                                    }
                                }
                            }
                        }

                        cout << "Confirmar reserva? ";
                        encontro = confirmar();
                        if (encontro)
                        {
                            h->confirmarReserva(fecha, fecha2, existe);
                        }
                    }
                }
                else
                {
                    cout << "No hay habitaciones disponibles" << endl;
                }
            }
            break;
        case 6:
            cout << "Ha seleccionado Consultar top 3 de hostales.\n";
            h->listarTop3();
            break;
        case 7:
            cout << "Ha seleccionado Registrar estadía.\n";
            cout << "    Hostales:" << endl;
            if (h->listarHostales() != NULL)
            {

                cout << "Ingrese el nombre del hostal: ";
                getline(cin, nombre);
                if (h->existeHostal(nombre))
                {
                    u->ListarHuespedes();
                    cout << "Ingrese el email del Huesped: ";
                    getline(cin, mail);
                    if (u->existeUsuario(mail))
                    {

                        IDictionary *reservas = u->ListarReservasHuesped(mail, nombre);

                        if (reservas && !(reservas->isEmpty()))
                        {
                            cout << "Ingrese el codigo de la reserva: ";
                            ingresarNum(codigoR);
                            u->seleccionarReserva(codigoR, mail);
                        }
                        else
                        {
                            cout << "No hay reservas";
                        }
                    }
                    else
                    {
                        cout << "Huesped no registrado" << endl;
                    }
                }
                else
                    cout << "Hostal no registrado";
            }
            break;
        case 8:
            cout << "Ha seleccionado Finalizar Estadía.\n";
            cout << "    Hostales:" << endl;
            if (h->listarHostales() != NULL)
            {

                cout << "Ingrese el Hostal: ";
                getline(cin, nombre);

                if (!(h->existeHostal(nombre)))
                {
                    cout << "Hostal no existente";
                    break;
                }

                cout << "Huespedes registrados: " << endl;
                u->ListarHuespedes();

                cout << "Ingrese el Huesped: ";
                getline(cin, mail);
                if (u->existeUsuario(mail))
                {
                    if (u->listarEstadias(mail, nombre))
                    {

                        cout << "Ingrese el Codigo estadia: ";
                        ingresarNum(codigoE);
                        u->finalizarEstadia(codigoE);
                    }
                    else
                        cout << "No hay estadias para ese usuario en ese hostal";
                }
            }

            break;
        case 9:
            cout << "Ha seleccionado Calificar estadía.\n";

            cout << "    Hostales:" << endl;
            h->listarHostales();
            cout << "Ingrese el nombre del hostal: ";
            getline(cin, nombre);
            if (!(h->existeHostal(nombre)))
            {
                cout << "Hostal no existente";
                break;
            }

            u->ListarHuespedes();
            cout << "Ingrese el mail del Huesped: ";
            getline(cin, mail);
            if (!(u->existeHuesped(mail)))
            {
                cout << "No existe huesped con este email" << endl;
                break;
            }
            if (u->ListarEstadiasFinalizadas(mail, nombre).empty())
            {
                cout << "No hay estadias finalizadas para ese huesped"<<endl;
                break;
            }
            cout << "Ingrese el codigo de la estadia: ";
            ingresarNum(codigoE);
            cout << "Ingrese el comentario: ";
            getline(cin, cargo);

            do
            {
                cout << "Califique del 1 al 5:  ";
                ingresarNum(numero);
            } while (numero > 5 || numero < 1);
            u->calificarEstadia(mail, codigoE, numero, cargo);

            break;
        case 10:
            cout << "Ha seleccionado Comentar calificación.\n";

            if (u->listarEmpleados().empty())
            {
                break;
            }
            cout << "Ingrese el email del empleado: ";
            getline(cin, email);
            if (u->existeEmpleado(email))
            {

                comentarios = u->listarComentarios(email);
                if (comentarios.empty())
                {
                    cout << "No hay calificaciones" << endl;
                    break;
                }
                for (const auto &calificacion : comentarios)
                {
                    cout << endl;
                    // Acceder a los datos de cada objeto dataEstadia y mostrarlos
                    cout << "Código de estadia: " << calificacion.codEstadia << endl;
                    cout << "Calificación: " << calificacion.calificacion << endl;
                    cout << "Comentario: " << calificacion.comentario << endl;
                    cout << "Huésped: " << calificacion.huesped << endl;
                    cout << "Fecha: " << calificacion.fecha << endl;
                    // ... mostrar el resto de los datos
                    cout << endl; // Espacio en blanco entre cada estadia
                }
                cout << "Ingrese el codigo de la estadia: ";
                ingresarNum(codigoE);
                encontro = false;
                for (const auto &calificacion : comentarios)
                {
                    if (calificacion.codEstadia == codigoE)
                    {
                        encontro = true;
                        cout << "Ingrese la respuesta: ";
                        getline(cin, cargo);
                        u->ingresarRespuesta(cargo, calificacion.huesped, email, codigoE);
                        break;
                    }
                }
                if (!encontro)
                    cout << "No se encontro la estadia";
            }

            break;
        case 11:
            cout << "Ha seleccionado Consulta de Usuario.\n";
            // Agrega aquí el código para consultar un usuario
            emails = u->listarUsuarios();
            /* for (it = emails.begin(); it != emails.end(); ++it)
            {
                auxMail = dynamic_cast<string *>(*it);
                cout << "Usuario " << &auxMail << endl;
            } */
            if (emails.begin() != emails.end())
            {
                cout << endl
                     << "Escriba el mail del que desea consultar. ";
                getline(cin, mail);

                u->seleccionarUsuario(mail);
                u->mostrarDatos();
            }
            break;
        case 12:
            cout << "Ha seleccionado Consulta de Hostal.\n";
            cout << "    Hostales:" << endl;
            if (!(h->listarHostales()))
            {
                break;
            }
            cout << "Ingrese el nombre del hostal: ";
            getline(cin, nombre);
            if (!(h->existeHostal(nombre)))
            {
                cout << "Hostal no existente";
                break;
            }
            dataP = h->infoHostal(nombre);
            cout << dataP.infoHostal;
            cout << "Promedio: ";
            if (dataP.promedio == -1)
            {
                cout << "S/N";
            }
            else
                cout << dataP.promedio;
            break;
        case 13:
            cout << "Ha seleccionado Consulta de Reserva.\n    Hostales:" << endl;
            if (h->listarHostales())
            {
                cout << "Ingrese el nombre del hostal: ";
                getline(cin, nombre);
                if (h->existeHostal(nombre))
                {
                    reservasHostal = h->SeleccionarHostal(nombre);
                    if (reservasHostal->isEmpty())
                    {
                        cout << "No hay reservas para ese hostal";
                    }
                }
                else
                {
                    cout << "Hostal no registrado";
                }
            }
            break;
        case 14:
            cout << "Ha seleccionado Consulta de Estadía.\n";
            // Agrega aquí el código para consultar una estadía

            existe = 0;
            cout << "    Hostales" << endl;
            if (h->listarHostales() == NULL)
            {
                break;
            }
            cout << "Ingrese el nombre del hostal: ";
            getline(cin, nombre);
            if (!(h->existeHostal(nombre)))
            {
                cout << "Hostal no registrado";
                break;
            }
            ests = h->ListarEstadia(nombre);
            if (ests.empty())
            {
                cout << "No hay estadias" << endl;
                break;
            }
            cout << "    Estadias: " << endl;
            for (const auto &estadia : ests)
            {

                cout << "Código de estadia: " << estadia.codigoEstadia << endl;
                cout << "Código de reserva: " << estadia.codReserva << endl;
                cout << "Nombre del hostal: " << estadia.nombreHostal << endl;
                cout << "Email del huésped: " << estadia.emailHuesped << endl;
                cout << "Número de habitación: " << estadia.nroHabitacion << endl;
                cout << "CheckIn: " << estadia.checkIn << endl;
                cout << "CheckOut: " << estadia.checkOut << endl;
                cout << "Promo: " << estadia.promo << endl;
                cout << endl;
            }

            cout << "Ingrese el codigo de la estadia: ";
            ingresarNum(codigoE);
            encontro = false;
            for (const auto &estadia : ests)
            {
                if (estadia.codigoEstadia == codigoE)
                {
                    u->seleccionEstadia(estadia.emailHuesped, codigoE);
                    encontro = true;
                    break;
                }
            }
            if (!encontro)
            {
                cout << "No se encontro esa estadia";
                break;
            }
            cout << "Quieres ver la calificacion?";
            existe = confirmar();
            if (existe)
            {
                c = u->mostrarCalificacion();
                if (c.comentario.empty() && c.fecha.empty())
                {
                    cout << "No ha sido calificada";
                }
                else
                {

                    cout << "Calificacion: " << c.calificacion << endl;
                    cout << "Comentario: " << c.comentario << endl;
                    cout << "Fecha: " << c.fecha << endl;
                }
                cout << endl;
            }
            cout << "Quieres ver la reserva?";
            existe = confirmar();
            if (existe)
            {
                dataReserva dr = u->mostrarReserva();
                cout << dr;
            }
            break;
        case 15:
            cout << "Ha seleccionado Baja de reserva." << endl;

            cout << "    Hostales" << endl;
            if (!(h->listarHostales()))
            {
                break;
            }

            cout << "Ingrese nombre del hostal:" << endl;
            getline(cin, nombre);
            if (h->existeHostal(nombre))
            {
                reservasHostal = h->SeleccionarHostal(nombre);
                if (!reservasHostal->isEmpty())
                {
                    cout << "Ingrese codigo de la reserva:";
                    ingresarNum(numero);
                    h->confirmarBajaReserva(numero);
                    delete reservasHostal;
                }
                else
                {
                    cout << "No hay reservas para ese Hostal" << endl;
                    break;
                }
            }
            else
            {
                cout << "Hostal no registrado";
            }

            break;
        case 16:
            cout << "Ha seleccionado Modificar Fecha del Sistema.\n";

            cout << "Ingresar hora: ";
            ingresarNum(fecha.hora);

            cout << "Ingresar dia: ";
            ingresarNum(fecha.dia);

            cout << "Ingresar mes: ";
            ingresarNum(fecha.mes);

            cout << "Ingresar año: ";
            ingresarNum(fecha.anio);
            h->modificarFecha(fecha);
            break;

            break;
        case 17:
            cout << "Adios!";
            break;
        case 18:

            //  empleados
            if (!datosCargados)
            {
                cout << "Cargando datos de prueba...\n";
                encontro = u->registrarEmpleado("emilia@mail.com", "Emilia", "123", tipoEmpleado::recepcion);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarEmpleado("leo@mail.com", "Leonardo", "123", tipoEmpleado::recepcion);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarEmpleado("alina@mail.com", "Aliana", "123", tipoEmpleado::administracion);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarEmpleado("barli@mail.com", "Barliman", "123", tipoEmpleado::recepcion);
                if (!encontro)
                    u->confirmarAltaUsuario();

                /* Sofia sofia@mail.com 123 Sí
                   Frodo frodo@mail.com 123 Sí
                   Sam sam@mail.com 123 No
                   Merry merry@mail.com 123 No
                   Pippin pippin@mail.com 123 No
                   Seba seba@mail.com 123 Sí*/

                encontro = u->registrarHuesped("sofia@mail.com", "Sofia", "123", true);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarHuesped("frodo@mail.com", "Frodo", "123", true);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarHuesped("sam@mail.com", "Sam", "123", false);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarHuesped("merry@mail.com", "Merry", "123", false);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarHuesped("pippin@mail.com", "Pippin", "123", false);
                if (!encontro)
                    u->confirmarAltaUsuario();

                encontro = u->registrarHuesped("seba@mail.com", "Seba", "123", true);
                if (!encontro)
                    u->confirmarAltaUsuario();

                /*
                HO1 La posada del finger Av de la playa 123, Maldonado 099111111
                HO2 Mochileros Rambla Costanera 333, Rocha 42579512
                HO3 El Pony Pisador Bree (preguntar por Gandalf) 000
                HO4 Altos de Fing Av del Toro 1424 099892992
                HO5 Caverna Lujosa Amaya 2515 233233235*/
                h->confirmarAltaHostal("La posada del finger", "Av de la playa", 99111111);
                h->confirmarAltaHostal("Mochileros", "Rambla Costanera 333, Rocha", 42579512);
                h->confirmarAltaHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", 000);
                h->confirmarAltaHostal("Altos de Fing", "Av del Toro", 99892992);
                h->confirmarAltaHostal("Caverna Lujosa", "Amaya 2515", 233233235);

                /*
                Habitaciones
                    Ref Hostel Número Precio Capacidad
                    HA1 HO1 1 $40 2
                    HA2 HO1 2 $10 7
                    HA3 HO1 3 $30 3
                    HA4 HO1 4 $5 12
                    HA5 HO5 1 $3 2
                    HA6 HO3 1 $9 5
                */
                h->seleccionarHostal("La posada del finger");
                h->confirmarAltaHabitacion(1, 2, 40);
                h->confirmarAltaHabitacion(2, 7, 10);
                h->confirmarAltaHabitacion(3, 3, 30);
                h->confirmarAltaHabitacion(4, 12, 5);

                h->seleccionarHostal("Caverna Lujosa");
                h->confirmarAltaHabitacion(1, 2, 3);

                h->seleccionarHostal("El Pony Pisador");
                h->confirmarAltaHabitacion(1, 5, 9);

                /*
            E1  HO1 Recepción
            E2 HO2 Recepción
            E3 HO2 Administración
            E4 HO3 Recepción
        */
                u->confirmarAsignacionEmpleadoHostal("emilia@mail.com", "recepcion", "La posada del finger");
                u->confirmarAsignacionEmpleadoHostal("leo@mail.com", "recepcion", "Mochileros");
                u->confirmarAsignacionEmpleadoHostal("alina@mail.com", "administracion", "Mochileros");
                u->confirmarAsignacionEmpleadoHostal("barli@mail.com", "recepcion", "El Pony Pisador");

                /*
                Reservas
                Ref      Hostel      Habitación      Tipo            Check in            Check out           Huespedes
                R1       HO1         HA1             Individual      01/05/22 - 2pm      10/05/22 - 10am     H1
                R2       HO3         HA6             Grupal          04/01/01 - 8pm      05/01/01 - 2am      H2,H3,H4,H5
                R3       HO1         HA3             Individual      7/06/22 - 2pm       30/06/22 - 11am     H1
                R4       HO5         HA5             Individual      10/06/22 - 2pm      30/06/22 - 11am     H6
                */
                h->ListarHabitacionesDisponibles("La posada del finger", dataTime(22, 5, 1, 14), dataTime(22, 5, 10, 10), false);
                h->SeleccionarHabitacionReserva(1);
                u->seleccionarHuesped("sofia@mail.com");
                h->confirmarReserva(dataTime(22, 5, 1, 14), dataTime(22, 5, 10, 10), false);

                h->ListarHabitacionesDisponibles("El Pony Pisador", dataTime(1, 1, 4, 20), dataTime(1, 1, 5, 2), true);
                h->SeleccionarHabitacionReserva(1);
                u->seleccionarHuesped("frodo@mail.com");
                u->seleccionarHuesped("sam@mail.com");
                u->seleccionarHuesped("merry@mail.com");
                u->seleccionarHuesped("pippin@mail.com");
                h->confirmarReserva(dataTime(1, 1, 4, 20), dataTime(1, 1, 5, 2), true);

                h->ListarHabitacionesDisponibles("La posada del finger", dataTime(22, 6, 7, 14), dataTime(22, 6, 30, 11), false);
                h->SeleccionarHabitacionReserva(3);
                u->seleccionarHuesped("sofia@mail.com");
                h->confirmarReserva(dataTime(22, 6, 7, 14), dataTime(22, 6, 30, 11), false);

                h->ListarHabitacionesDisponibles("Caverna Lujosa", dataTime(22, 6, 10, 14), dataTime(22, 6, 30, 11), false);
                h->SeleccionarHabitacionReserva(1);
                u->seleccionarHuesped("seba@mail.com");
                h->confirmarReserva(dataTime(22, 6, 10, 14), dataTime(22, 6, 30, 11), false);

                /*Estadías
                Ref Reserva Huesped     Check in
                ES1     R1      H1      01/05/22 - 6pm
                ES2     R2      H2      04/01/01 - 9pm
                ES3     R2      H3      04/01/01 - 9pm
                ES4     R2      H4      04/01/01 - 9pm
                ES5     R2      H5      04/01/01 - 9pm
                ES6     R4      H6      07/06/22 - 6pm*/

                /*               Sofia sofia@mail.com 123 Sí
                                 Frodo frodo@mail.com 123 Sí
                                 Sam sam@mail.com 123 No
                                 Merry merry@mail.com 123 No
                                 Pippin pippin@mail.com 123 No
                                 Seba seba@mail.com 123 Sí*/

                h->modificarFecha(dataTime(22, 5, 1, 14));
                u->seleccionarReserva(0, "sofia@mail.com");

                h->modificarFecha(dataTime(1, 1, 4, 20));
                u->seleccionarReserva(1, "frodo@mail.com");
                u->seleccionarReserva(1, "sam@mail.com");
                u->seleccionarReserva(1, "merry@mail.com");
                u->seleccionarReserva(1, "pippin@mail.com");

                h->modificarFecha(dataTime(22, 6, 10, 18));
                u->seleccionarReserva(3, "seba@mail.com");

                /*  Finalización de estadías
                    Estadía Huesped Check out
                    ES1 H1 10/05/22 - 9am
                    ES2 H2 05/01/01 - 2am
                    ES6 H6 15/06/22 - 10pm*/
                /*               Sofia sofia@mail.com 123 Sí
                                 Frodo frodo@mail.com 123 Sí
                                 Sam sam@mail.com 123 No
                                 Merry merry@mail.com 123 No
                                 Pippin pippin@mail.com 123 No
                                 Seba seba@mail.com 123 Sí*/
                /*
                HO1 La posada del finger Av de la playa 123, Maldonado 099111111
                HO2 Mochileros Rambla Costanera 333, Rocha 42579512
                HO3 El Pony Pisador Bree (preguntar por Gandalf) 000
                HO4 Altos de Fing Av del Toro 1424 099892992
                HO5 Caverna Lujosa Amaya 2515 233233235*/
                h->modificarFecha(dataTime(22, 5, 10, 9));
                u->seleccionEstadia("sofia@mail.com", 0);
                u->finalizarEstadia(0);

                h->modificarFecha(dataTime(1, 1, 5, 2));
                u->seleccionEstadia("frodo@mail.com", 1);
                u->finalizarEstadia(1);

                h->modificarFecha(dataTime(22, 6, 15, 22));
                u->seleccionEstadia("seba@mail.com", 5);
                u->finalizarEstadia(5);

                /*Calificar estadía
                Ref     Estadía     Huesped Comentario                              Calificación    Fecha
                C1      ES1         H1      Un poco caro para lo que ofrecen.       3               11/05/22 - 6pm
                                            El famoso gimnasio era una
                                            caminadora (que hacía tremendo
                                            ruido) y 2 pesas, la piscina parecía
                                            el lago del Parque Rodó y el
                                            desayuno eran 2 tostadas con
                                            mermelada. Internet se pasaba
                                            cayendo. No vuelvo.

                C2      ES2         H2      Se pone peligroso de noche, no          2                05/01/01 - 3am
                                            recomiendo. Además no hay caja
                                            fuerte para guardar anillos.

                C3      ES6         H6      Había pulgas en la habitación.          1                15/06/22 - 11pm
                                            Que lugar más mamarracho!!
                                                                                                                */

                u->calificarEstadia("sofia@mail.com", 0, 3, "Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.");
                u->calificarEstadia("frodo@mail.com", 1, 2, "Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.");
                u->calificarEstadia("seba@mail.com", 5, 1, "Había pulgas en la habitación. Que lugar más mamarracho!!");

                /*                Comentar calificación
                                Calificación        Empleado        Respuesta                           Fecha
                                C2                  E4              Desapareció y se fue sin pagar.     06/01/01 - 3pm


                */
                comentarios = u->listarComentarios("barli@mail.com");
                if (comentarios.empty())
                {
                    cout << "Estadia no calificada " << endl;
                }
                u->ingresarRespuesta("Desapareció y se fue sin pagar.", "frodo@mail.com", "barli@mail.com", 1);
                //  ingresarRespuesta(string respuesta, string mailHuesped,string mailEmpleado, int codEstadia)
                datosCargados = true;
            }
            else
                cout << "Datos de prueba ya cargados";
            break;

        default:
            cout << "Opción inválida.\n";
            break;
        }
        // cin.ignore();
        // cin.clear();
        emails.clear();
        emailsReserva.clear();

        cout << endl
             << "Presiona enter para continuar\n";

        while (getchar() != '\n')
            ;
        system("clear");
    } while (opcion != 17);
    return 0;
}

bool comparar(dataTime fecha, dataTime fecha2)
{
    if (fecha <= fecha2)
    {
        return true; // Fecha de checkout posterior o igual a la de checkin
    }
    else
    {
        return false; // Fecha de checkout anterior a la de checkin
    }
}