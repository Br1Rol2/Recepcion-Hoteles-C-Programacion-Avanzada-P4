#ifndef DATAHOSTAL
#define DATAHOSTAL
#include <iostream>
#include <string.h>
using namespace std;
class dataHostal{
    public: 
        string nombre;
        string direccion;
        int calificacion;
        string* comentarios;
        int telefono;
    
        bool operator<(dataHostal const &p) const {
            return this->nombre<p.getNombre();
        }
        dataHostal(){ 
        }
        dataHostal(string _nombre, string _direccion, int _telefono){
            nombre = _nombre;
            direccion = _direccion;
            telefono = _telefono;
        }
        dataHostal(string _nombre, string _direccion, int _calificacion, string* _comentarios){
            nombre = _nombre;
            direccion = _direccion;
            calificacion = _calificacion;
            comentarios = _comentarios;
        }

        //getters
        string getNombre() const {
            return nombre;
        }
        string getDireccion() const{
            return direccion;
        }
        int getCalificacion() const{
            return calificacion;
        }
        string* getComentarios() const{
            return comentarios;
        }
        int getTelefono() const{
            return telefono;
        }

        //setters
        void setNombre(string _nombre){
            nombre = _nombre;
        }
        void setDireccion(string _direccion){
            direccion = _direccion;
        }
        void setCalificacion(int _calificacion){
            calificacion = _calificacion;
        }
        void setComentarios(string* _comentarios){
            comentarios = _comentarios;
        }
        friend std::ostream& operator <<(std::ostream& os, const dataHostal& ho){
			os<<"Nombre: "<<ho.getNombre()<<"\n"<<
                "Direccion: " <<ho.getDireccion()<<"\n"<<
                "Telefono: "<<ho.getTelefono()<<"\n";
            return os;
        }


};
#endif