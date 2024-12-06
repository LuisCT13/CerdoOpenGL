#include "cerdo.h"
#include "cabeza.h"
#include "torso.h"

Cerdo::Cerdo() {
    cabezaCerdo= new Cabeza();
    torsoCerdo= new Torso();
}
Cerdo::Cerdo(Cabeza *cab, Torso *tor) {
    cabezaCerdo= cab;
    torsoCerdo= tor;
}
void Cerdo::desplegar(){
    cabezaCerdo->desplegar();
    torsoCerdo->desplegar();
}
void Cerdo::rotar(float angulo, char opcion){
    if(opcion=='x'){
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeX);
        torsoCerdo->rotar(angulo, torsoCerdo->EjeX);
    }
    if(opcion=='y'){
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeY);
        torsoCerdo->rotar(angulo, torsoCerdo->EjeY);
    }
    if(opcion=='z'){
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeZ);
        torsoCerdo->rotar(angulo, torsoCerdo->EjeZ);
    }
}

