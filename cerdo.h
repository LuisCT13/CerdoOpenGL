#ifndef CERDO_H
#define CERDO_H
#include "cabeza.h"
#include "torso.h"
#include "pata.h"

class Cerdo
{
public:
    Cerdo();
    Cabeza *cabezaCerdo;
    Torso *torsoCerdo;
    Pata* pataSupIzq;
    Pata* pataSupDer;
    Pata* pataInfIzq;
    Pata* pataInfDer;
    void desplegar();
};

#endif // CERDO_H
