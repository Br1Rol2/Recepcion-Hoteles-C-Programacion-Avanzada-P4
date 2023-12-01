#ifndef DATAHUESPED
#define DATAHUESPED
#include <iostream>
#include <string.h>
using namespace std;
class dataHuesped{
	public:
		string nombre;
		string email;
		string password;
		bool esFinger;
		
		dataHuesped(string _nombre,string _email,string _password,bool _esFinger){
			nombre = _nombre;
			email = _email;
			password = _password;
			esFinger = _esFinger;
		}
		
		//getters
		string getNombre() const {
            return nombre;
        }
        string getEmail() const {
            return email;
        }
		string getPassword() const {
			return password;
		}
		bool getEsFinger() const {
			return esFinger;
		}

		//setters
		void setNombre(string _nombre){
			nombre = _nombre;
		}
		void setEmail(string _email){
			email = _email;
		}
		void setPassword(string _password){
			password = _password;
		}
		void setEsFinger(bool _esFinger){
			esFinger = _esFinger;
		}
		friend std::ostream& operator <<(std::ostream& os, const dataHuesped& dh){
            string calidad="no";
			if(dh.getEsFinger()){
				calidad="si";
			}
			os<<"Nombre: "<<dh.getNombre()<<"\n"<<
                "Email: " <<dh.getEmail()<<"\n"<<
                "Es Finger: "<<calidad<<"\n";
            return os;
        }
};





#endif