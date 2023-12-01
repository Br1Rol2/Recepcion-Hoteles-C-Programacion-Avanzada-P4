#ifndef DATACONSUMO
#define DATACONSUMO
#include <iostream>
#include <string.h>
using namespace std;
class dataConsumo{

    public: 
        int codigo;
        string nombre;
        int precio; 
        dataConsumo(){
            
        }
        dataConsumo(int _codigo, string _nombre, int _precio){
            codigo = _codigo;
            nombre = _nombre;
            precio = _precio;
        }

        //getters
        int getCodigo() const {
            return codigo;
        }
        string getNombre() const {
            return nombre;
        }
        int getPrecio() const {
            return precio;
        }

        //setters
        void setCodigo(int _codigo){
            codigo = _codigo;
        }
        void setNombre(string _nombre){
            nombre= _nombre;
        }
        void setPrecio(int _precio){
            precio = _precio;
        }


};
#endif