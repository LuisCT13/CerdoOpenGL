#include "cerdo.h"
#include "cabeza.h"
#include "torso.h"

Cerdo::Cerdo() {
    cabezaCerdo= new Cabeza();
    torsoCerdo= new Torso();
}
void Cerdo::desplegar(){
    cabezaCerdo->desplegar();
    torsoCerdo->desplegar();
}
