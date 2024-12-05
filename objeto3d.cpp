#include "objeto3d.h"
#include <cmath>

Objeto3D::Objeto3D() {
}

Objeto3D::~Objeto3D() {
    for (Superficie* superficie:superficies) {
        delete superficie;
    }
}

void Objeto3D::agregar(Superficie* superficie) {
    superficies.push_back(superficie);
}

void Objeto3D::desplegar() {
    for (Superficie* superficie:superficies) {
        superficie->desplegar();
    }
}

Objeto3D* Objeto3D::copia() {
    Objeto3D* copia=new Objeto3D();
    for (Superficie* superficie:superficies) {
        copia->agregar(superficie->copia());
    }
    return copia;
}

void Objeto3D::transformar(Matriz3D* M) {
    for (Superficie* superficie:superficies) {
        superficie->transformar(M);
    }
}

void Objeto3D::rotar(float teta,Linea* eje) {
    float a=eje->p2->x-eje->p1->x;
    float b=eje->p2->y-eje->p1->y;
    float c=eje->p2->z-eje->p1->z;
    float alfa=atan2(b,c);
    float d=sqrt(pow(b,2)+pow(c,2));
    float beta=atan2(a,d);
    Matriz3D* T1=new Matriz3D(1,0,0,-eje->p1->x,
                                0,1,0,-eje->p1->y,
                                0,0,1,-eje->p1->z);
    Matriz3D* R1x=new Matriz3D(1,0,0,0,
                                0,cos(alfa),-sin(alfa),0,
                                0,sin(alfa),cos(alfa),0);
    Matriz3D* R1y=new Matriz3D(cos(-beta),0,sin(-beta),0,
                                0,1,0,0,
                                -sin(-beta),0,cos(-beta),0);
    Matriz3D* Rz=new Matriz3D(cos(teta),-sin(teta),0,0,
                                sin(teta),cos(teta),0,0,
                                0,0,1,0);
    Matriz3D* R2y=new Matriz3D(cos(beta),0,sin(beta),0,
                                 0,1,0,0,
                                 -sin(beta),0,cos(beta),0);
    Matriz3D* R2x=new Matriz3D(1,0,0,0,
                                 0,cos(-alfa),-sin(-alfa),0,
                                 0,sin(-alfa),cos(-alfa),0);
    Matriz3D* T2=new Matriz3D(1,0,0,eje->p1->x,
                                0,1,0,eje->p1->y,
                                0,0,1,eje->p1->z);
    Matriz3D* M=T2->mult(R2x->mult(R2y->mult(Rz->mult(R1y->mult(R1x->mult(T1))))));
    transformar(M);
    delete T1;
    delete R1x;
    delete R1y;
    delete Rz;
    delete R2y;
    delete R2x;
    delete T2;
    delete M;
}


















