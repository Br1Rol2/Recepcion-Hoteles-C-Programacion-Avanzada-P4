#ifndef DATAEMPLEADO
#define DATAEMPLEADO
#include <iostream>
#include <string.h>
using namespace std;
class dataEmpleado{

	public:
		string nombre;
		string email;
		string password;
		string cargo;
		
		dataEmpleado(string _nombre,string _email,string _password,string _cargo){
			nombre = _nombre;
			email = _email;
			password = _password;
			cargo = _cargo;
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
		string getCargo() const {
			return cargo;
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
		void setCargo(string _cargo){
			cargo = _cargo;
		}
		friend std::ostream& operator <<(std::ostream& os, const dataEmpleado& de){
			os<<"Nombre: "<<de.getNombre()<<"\n"<<
                "Email: " <<de.getEmail()<<"\n"<<
                "Cargo: "<<de.getCargo()<<"\n";
            return os;
        }
};




#endif