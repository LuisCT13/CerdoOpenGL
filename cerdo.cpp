#include "cerdo.h"
#include "cabeza.h"
#include "torso.h"
#include "pata.h"


Cerdo::Cerdo() {
    cabezaCerdo= new Cabeza();
    torsoCerdo= new Torso();
    pataSupIzq = new Pata(0.1, 0.3, -0.35, 0.2, 0.3, 0.5);
    pataSupDer = new Pata(0.6, 0.8, -0.35, 0.2, 0.3, 0.5);
    pataInfIzq = new Pata(0.1, 0.3, -0.35, 0.2, -0.45, -0.25);
    pataInfDer = new Pata(0.6, 0.8, -0.35, 0.2, -0.45, -0.25);

}
Cerdo::Cerdo(Cabeza *cab, Torso *tor, Pata* supIzq, Pata* supDer, Pata* infDer, Pata* infIzq) {
    cabezaCerdo= cab;
    torsoCerdo= tor;
    pataSupIzq = supIzq;
    pataSupDer = supDer;
    pataInfDer = infDer;
    pataInfIzq = infIzq;
}
void Cerdo::desplegar(){
    cabezaCerdo->desplegar();
    torsoCerdo->desplegar();
    pataSupIzq->desplegar();
    pataSupDer->desplegar();
    pataInfDer->desplegar();
    pataInfIzq->desplegar();

}
void Cerdo::rotar(float angulo, char opcion){
    if(opcion=='x'){
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeX);
        torsoCerdo->rotar(angulo, torsoCerdo->EjeX);
        pataSupIzq->rotar(angulo, pataSupIzq->EjeX);
        pataSupDer->rotar(angulo, pataSupIzq->EjeX);
        pataInfDer->rotar(angulo, pataSupIzq->EjeX);
        pataInfIzq->rotar(angulo, pataSupIzq->EjeX);

    }
    if(opcion=='y'){
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeY);
        torsoCerdo->rotar(angulo, torsoCerdo->EjeY);
        pataSupIzq->rotar(angulo, pataSupIzq->EjeY);
        pataSupDer->rotar(angulo, pataSupIzq->EjeY);
        pataInfDer->rotar(angulo, pataSupIzq->EjeY);
        pataInfIzq->rotar(angulo, pataSupIzq->EjeY);
    }
    if(opcion=='z'){
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeZ);
        torsoCerdo->rotar(angulo, torsoCerdo->EjeZ);
        pataSupIzq->rotar(angulo, pataSupIzq->EjeZ);
        pataSupDer->rotar(angulo, pataSupIzq->EjeZ);
        pataInfDer->rotar(angulo, pataSupIzq->EjeZ);
        pataInfIzq->rotar(angulo, pataSupIzq->EjeZ);
    }
}

