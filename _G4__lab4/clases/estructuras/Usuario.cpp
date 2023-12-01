#include "Usuario.h"
#include <iostream>
using namespace std;

void Usuario::setName(string nombre)
{
    this->nombre = nombre;
}
Usuario::Usuario(string _nombre, string _email, string _password)
{
    nombre = _nombre;
    email = _email;
    password = _password;
}
string Usuario::getName()
{
    return nombre;
}
void Usuario::setPassword(string password)
{
    this->password = password;
}

string Usuario::getPassword()
{
    return password;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}

string Usuario::getEmail()
{
    return email;
}
