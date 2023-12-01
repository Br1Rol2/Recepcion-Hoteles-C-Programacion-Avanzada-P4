#ifndef DATARESERVA
#define DATARESERVA
#include <iostream>
#include "dataTime.h"
#include "dataCalificacion.h"
#include "../ICollection/interfaces/ICollectible.h"
#include <set>
#include <string.h>
using namespace std;
class dataReserva: public ICollectible{
	public:
		int codReserva;
		string nombreHostal;
		std::set<string> emailHuesped;
		int nroHabitacion;
		dataTime checkIn;
		dataTime checkOut;
		//builder parametrisado
		dataReserva(int _codReserva,string _nombreHostal,std::set<string> _emailHuesped,int _nroHabitacion,dataTime _checkin, dataTime _checkout){
			codReserva = _codReserva;
			nombreHostal = _nombreHostal;
			emailHuesped = _emailHuesped;
			nroHabitacion = _nroHabitacion;
			checkIn = _checkin;
			checkOut = _checkout;
		}
		dataReserva(){}
		friend std::ostream& operator <<(std::ostream& os, const dataReserva& res){
			string auxiliar;
			os<<"Codigo: "<<res.codReserva<<"\n"<<
                "Hostal:" <<res.nombreHostal<<"\n"<<
                "Nro Habitacion:" <<res.nroHabitacion<<"\n"<<
                "CheckIn:" <<res.checkIn<<"\n"<<
                "CheckOut:" <<res.checkOut<<"\n"<<
                "Email Huesped:"<<endl;
				for(auto &it:res.emailHuesped){
					auxiliar = (it);
					os<<auxiliar<<"\n";
				} 
            return os;
        }
};
#endif