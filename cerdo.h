#ifndef CERDO_H
#define CERDO_H
#include "cabeza.h"
#include "torso.h"
#include "linea.h"
#include "pata.h"


class Cerdo
{
public:
    Cerdo();
    Cerdo(Cabeza*, Torso*, Pata*, Pata*, Pata*, Pata*);
    Cabeza *cabezaCerdo;
    Torso *torsoCerdo;
    Pata* pataSupIzq;
    Pata* pataSupDer;
    Pata* pataInfIzq;
    Pata* pataInfDer;
    void desplegar();
    void mover(float, float, float);
    void moverCabeza(float);
    void rotar(float,  char);
};

#endif // CERDO_H
