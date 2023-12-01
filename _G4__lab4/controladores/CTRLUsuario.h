#include "../interfaces/IUsuario.h"
#include <set>
#ifndef CTRLUSUARIO
#define CTRLUSUARIO

using namespace std;
class CTRLUsuario : public IUsuario  {
    private:
    string tipoUsuario;
    string nombre;
    string email;
    string password;
    Huesped * hu;
    tipoEmpleado cargo;
    Estadia * estadia;
    Usuario * user;
    bool esTecnoPacker;
    IDictionary * usuarios;
    IDictionary * huespedes;
    IDictionary * empleados;
    CTRLUsuario();
    static CTRLUsuario * instance;
    public:
    IDictionary * huespReserva; // para agregar huespedes en las funciones de registrar reserva
    bool listarEstadias(string email,string nombre);
    static CTRLUsuario * getInstance();
  	std::set<dataCalificacion> listarComentarios(string mail);
    void confirmarAltaUsuario();
    //void finalizarEstadia(int);
    bool existeHuesped(string email);
    void ingresarRespuesta(string, string,string, int);
    //ICollection * listarComentarios(string);
   // ICollection * listarEstadiasFinalizadas(string,string);
    std::set<string*> listarUsuarios();
    bool seleccionEstadia(string email,int codE);
    dataHuesped mostraHuesped();
    dataEmpleado mostrarEmpleado();
    bool registrarEmpleado(string, string, string, tipoEmpleado);
    bool registrarHuesped(string, string, string, bool);
    void finalizarEstadia(int);
    void seleccionarReserva(int,string);
    void seleccionarUsuario(string);
    void seleccionarHuesped(string algo);
    set<dataEstadia> ListarEstadiasFinalizadas(string mail,string nombre);
    IDictionary * ListarReservasHuesped(string mail,string nombre);
    void confirmarAsignacionEmpleadoHostal(string email,string cargo,string nombreH);
    void calificarEstadia(string mail,int codigo, int calificacion, const string comentario);
    virtual ~CTRLUsuario();
    void mostrarDatos(); 
    std::set<string *> ListarHuespedes();
    std::set<string*> listarEmpleados();
    bool existeUsuario(string nombre);
    bool existeEmpleado(string email);
    dataReserva mostrarReserva();
    dataCalificacion mostrarCalificacion();
    
};

#endif

