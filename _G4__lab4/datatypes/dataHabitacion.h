#ifndef DATAHABITACION
#define DATAHABITACION
#include <string.h>
#include <iostream>
using namespace std;
class dataHabitacion{
	public:
		int numero;
		int precio;
		int capacidad;

		dataHabitacion(){
			
		}
		dataHabitacion(int _numero,int _precio,int _capacidad){
			numero = _numero;
			precio = _precio;
			capacidad = _capacidad;
		}
		
		//getters
		int getNumero() const {
			return numero;
		}
		int getPrecio() const {
			return precio;
		}
		int getCapacidad() const {
			return capacidad;
		}

		//setters
		void setNumero(int _numero){
			numero = _numero;
		}
		void setPrecio(int _precio){
			precio = _precio;
		}
		void setCapacidad(int _capacidad){
			capacidad = _capacidad;
		}
};




#endif