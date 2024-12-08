#ifndef CERDO_H
#define CERDO_H
#include "cabeza.h"
#include "torso.h"
#include "linea.h"
#include "pata.h"
#include "matriz3d.h"


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
    void rotar(float,  char);
    void trasladar(float, float, float);
    Cerdo *copia();
    void escalarPiezas(Matriz3D *);
    void mover(float, float, float);
    void moverCabeza(float, char);
    void moverPatas(float, char);

};

#endif // CERDO_H
