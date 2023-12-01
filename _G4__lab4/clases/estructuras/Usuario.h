#ifndef USUARIO
#define USUARIO
#include <iostream>

#include "../../ICollection/interfaces/OrderedKey.h"
#include "../../ICollection/interfaces/ICollectible.h"
using namespace std;

class Usuario: public ICollectible{
    protected:
        string nombre;
        string password;
        string email;
    public:
    Usuario(string _nombre, string _email, string _password);
    void setNombre( string nombre);
    void setPassword( string password);
    string getPassword() ;
    void setEmail( string email);
    void setName(string);
    string getEmail() ;
    string getName() ;
    };

/* class UserKey : public OrderedKey{
    public:
        string email;
        UserKey(string);
        bool equals( OrderedKey * otra) ;
        ComparisonRes compare(OrderedKey *k)const ;
        ~UserKey();
}; */

#endif