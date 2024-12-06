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
void Cerdo::desplegar(){
    cabezaCerdo->desplegar();
    torsoCerdo->desplegar();
    pataSupIzq->desplegar();
    pataSupDer->desplegar();
    pataInfDer->desplegar();
    pataInfIzq->desplegar();
}
