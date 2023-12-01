#ifndef DATATIME
#define DATATIME
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;
class dataTime{
	public:
		int anio;
		int mes;
		int dia;
		int hora;
		dataTime(int _anio,int _mes,int _dia, int _hora){
			anio = _anio;
			mes = _mes;
			dia = _dia;
			hora = _hora;
		}
		dataTime(){
			anio = 0;
			mes = 0;
			dia = 0;
			hora = 0;
		}
		bool empty(){
			return (anio == 0 && mes == 0 && dia == 0 && hora == 0);
		}
		friend bool operator<=(const dataTime& dt1, const dataTime& dt2);
		friend std::ostream& operator<<(std::ostream& os, const dataTime& dt);
};



#endif