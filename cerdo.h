#ifndef CERDO_H
#define CERDO_H
#include "cabeza.h"
#include "torso.h"

class Cerdo
{
public:
    Cerdo();
    Cabeza *cabezaCerdo;
    Torso *torsoCerdo;
    void desplegar();
};

#endif // CERDO_H
