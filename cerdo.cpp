#include "cerdo.h"
#include "cabeza.h"
#include "torso.h"
#include "pata.h"


Cerdo::Cerdo() {
    cabezaCerdo= new Cabeza();
    torsoCerdo= new Torso();
    pataSupIzq = new Pata(0.1, 0.3, -0.35, 0.3, 0.3, 0.5);
    pataSupDer = new Pata(0.6, 0.8, -0.35, 0.3, 0.3, 0.5);
    pataInfIzq = new Pata(0.1, 0.3, -0.35, 0.3, -0.45, -0.25);
    pataInfDer = new Pata(0.6, 0.8, -0.35, 0.3, -0.45, -0.25);

}
Cerdo::Cerdo(Cabeza* cab, Torso *tor, Pata* supIzq, Pata* supDer, Pata* infDer, Pata* infIzq) {
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
void Cerdo::trasladar(float x, float y, float z){
    cabezaCerdo->trasladar(x,y,z);
    torsoCerdo->trasladar(x,y,z);
    pataInfDer->trasladar(x,y,z);
    pataInfIzq->trasladar(x,y,z);
    pataSupDer->trasladar(x,y,z);
    pataSupIzq->trasladar(x,y,z);
    //trasladar ejes de las patas
    pataInfDer->trasladarEjesPata(x,y,z);
    pataInfIzq->trasladarEjesPata(x,y,z);
    pataSupDer->trasladarEjesPata(x,y,z);
    pataSupIzq->trasladarEjesPata(x,y,z);
}
Cerdo* Cerdo::copia(){
    // Crear las copias de todas las partes del cerdo
    Cerdo *copia= new Cerdo();
    copia->cabezaCerdo=this->cabezaCerdo->copia();
    copia->torsoCerdo=this->torsoCerdo->copia();
    copia->pataInfDer=this->pataInfDer->copia();
    copia->pataInfIzq=this->pataInfIzq->copia();
    copia->pataSupDer=this->pataSupDer->copia();
    copia->pataSupIzq=this->pataSupIzq->copia();
    return copia;
}
void Cerdo:: escalarPiezas(Matriz3D *M){
    cabezaCerdo->transformar(M);
    torsoCerdo->transformar(M);
    pataSupIzq->transformar(M);
    pataSupDer->transformar(M);
    pataInfDer->transformar(M);
    pataInfIzq->transformar(M);
    //escalar los ejes de las patas
    pataSupIzq->transformarEjesPata(M);
    pataSupDer->transformarEjesPata(M);
    pataInfDer->transformarEjesPata(M);
    pataInfIzq->transformarEjesPata(M);

}

void Cerdo::mover(float dx, float dy, float dz) {
    cabezaCerdo->mover(dx, dy, dz);
    torsoCerdo->mover(dx, dy, dz);
    pataSupIzq->mover(dx, dy, dz);
    pataSupDer->mover(dx, dy, dz);
    pataInfDer->mover(dx, dy, dz);
    pataInfIzq->mover(dx, dy, dz);
}

void Cerdo::moverPatas(float angulo, char opcion){
    if(opcion=='x')
    {
        pataSupDer->rotar(angulo, pataSupDer->EjePX);
        pataInfDer->rotar(angulo, pataInfDer->EjePX);
        pataSupIzq->rotar(angulo, pataSupIzq->EjePX);
        pataInfIzq->rotar(angulo, pataInfIzq->EjePX);
    }

    if(opcion=='z'){
        pataSupDer->rotar(angulo, pataSupDer->EjePZ);
        pataInfDer->rotar(angulo, pataInfDer->EjePZ);
        pataSupIzq->rotar(angulo, pataSupIzq->EjePZ);
        pataInfIzq->rotar(angulo, pataInfIzq->EjePZ);
    }
}

void Cerdo::moverCabeza(float angulo, char opcion) {
    if(opcion=='x')
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeX);
    if(opcion=='y')
        cabezaCerdo->rotar(angulo, cabezaCerdo->EjeY);
}
