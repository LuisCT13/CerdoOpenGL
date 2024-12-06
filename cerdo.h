#ifndef CERDO_H
#define CERDO_H
#include "cabeza.h"
#include "torso.h"
#include "linea.h"


class Cerdo
{
public:
    Cerdo();
    Cerdo(Cabeza*, Torso*);
    Cabeza *cabezaCerdo;
    Torso *torsoCerdo;
    void desplegar();
    void rotar(float,  char);
};

#endif // CERDO_H
