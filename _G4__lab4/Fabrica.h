#ifndef FABRICA_H
#define FABRICA_H
#include "interfaces/IHostal.h"

#include "interfaces/IUsuario.h"

class Fabrica {
public:
    Fabrica();
    Fabrica(const Fabrica& orig);
    IHostal * getIHostal();
    IUsuario * getIUsuario();
    virtual ~Fabrica();
private:

};

#endif /* FABRICA_H */
