#ifndef DATAESTADIA
#define DATAESTADIA
#include <iostream>
#include "dataTime.h"
#include <string.h>
using namespace std;

class dataEstadia{
	public:
		
		int codReserva;
		string nombreHostal;
		string emailHuesped;
		int nroHabitacion;
		dataTime checkIn;
		dataTime checkOut;
		string promo;
		int codigoEstadia;
		dataEstadia(){
		}
	
		dataEstadia(int _codReserva,string _nombreHostal,string _emailHuesped,int _nroHabitacion,dataTime _checkin, dataTime _checkout,string _promo, int _codigoEstadia){
			codReserva = _codReserva;
			nombreHostal = _nombreHostal;
			emailHuesped = _emailHuesped;
			nroHabitacion = _nroHabitacion;
			checkIn = _checkin;
			checkOut = _checkout;
			promo = _promo;
			codigoEstadia = _codigoEstadia;
			
		}
		friend bool operator<(const dataEstadia& lhs, const dataEstadia& rhs) {
			// Comparación basada en algún criterio, por ejemplo, por código de reserva
			return lhs.codigoEstadia < rhs.codigoEstadia;
    	}
		//getters
		int getCodReserva()  {
			return codReserva;
		}
		string  getNombreHostal()  {
			return 	nombreHostal;
		}
		string getEmailHuesped() {
			return emailHuesped;
		}
		int getNroHabitacion()  {
			return nroHabitacion;
		}
		dataTime getCheckIn() {
			return checkIn;
		}
		dataTime getCheckOut() {
			return checkOut;
		}
		string getPromo()  {
			return promo;
		}
		int getCodigoEstadia() {
			return codigoEstadia;
		}

		//setters
		void setCodReserva(int _codReserva) {
			codReserva = _codReserva;
		}
		void setNombreHostal(string _nombreHostal){
			nombreHostal = _nombreHostal;
		}
		void setEmailHuesped(string _emailHuesped){
			emailHuesped = _emailHuesped;
		}
		void setNroHabitacion(int _nroHabitacion){
			nroHabitacion = _nroHabitacion;
		}
		void setCheckIn(dataTime _checkIn){
			checkIn = _checkIn;
		}
		void setCheckOut(dataTime _checkOut){
			checkOut = _checkOut;
		}
		void setPromo(string _promo){
			promo = _promo;
		}
		void setCodigoEstadia(int _codigoEstadia){
			codigoEstadia = _codigoEstadia;
		}
};
#endif