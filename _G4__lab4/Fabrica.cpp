#include "Fabrica.h"
#include "controladores/CTRLHostal.h"

#include "controladores/CTRLUsuario.h"

Fabrica::Fabrica() {
}

Fabrica::Fabrica(const Fabrica& orig) {
    
}
IUsuario* Fabrica::getIUsuario(){
    return ( CTRLUsuario::getInstance());
}

IHostal* Fabrica::getIHostal(){
    return ( CTRLHostal::getInstance());
}

Fabrica::~Fabrica() {
}