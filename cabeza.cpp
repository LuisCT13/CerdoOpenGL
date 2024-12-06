#include "cabeza.h"

Cabeza::Cabeza(){
    //CREACION DE LA CABEZA Y NARIZ
    Superficie* s=new Superficie(1,0,0);
    float  z5 = 0.975, z6 = 0.9, x3 = 0.3, x4 = 0.6, y3= 0.6, y4 = 0.8;

    // ---- NARIZ DEL CERDO ----
    //frente
    s->agregar(new Vertice(x4,y4,z5));
    s->agregar(new Vertice(x3,y4,z5));
    s->agregar(new Vertice(x3,y3,z5));
    s->agregar(new Vertice(x4,y3,z5));
    agregar(s);

    //cara derecha
    s = new Superficie(1,0,0);
    s->agregar(new Vertice(x4, y3, z5));
    s->agregar(new Vertice(x4, y3, z6));
    s->agregar(new Vertice(x4, y4, z6));
    s->agregar(new Vertice(x4, y4, z5));
    agregar(s);

    //cara trasera
    s = new Superficie(1,0,0);
    s->agregar(new Vertice(x4,y4,z6));
    s->agregar(new Vertice(x3,y4,z6));
    s->agregar(new Vertice(x3,y3,z6));
    s->agregar(new Vertice(x4,y3,z6));
    agregar(s);

    //cara izquierda
    s = new Superficie(1,0,0);
    s->agregar(new Vertice(x3, y3, z6));
    s->agregar(new Vertice(x3, y3, z5));
    s->agregar(new Vertice(x3, y4, z5));
    s->agregar(new Vertice(x3, y4, z6));
    agregar(s);

    //cara superior
    s = new Superficie(1,0,0);
    s->agregar(new Vertice(x3, y3, z6));
    s->agregar(new Vertice(x4, y3, z6));
    s->agregar(new Vertice(x4, y3, z5));
    s->agregar(new Vertice(x3, y3, z5));
    agregar(s);

    //cara inferior
    s = new Superficie(1,0,0);
    s->agregar(new Vertice(x3, y4, z6));
    s->agregar(new Vertice(x4, y4, z6));
    s->agregar(new Vertice(x4, y4, z5));
    s->agregar(new Vertice(x3, y4, z5));
    agregar(s);

    // ---- CABEZA DEL CERDO ----
    //y menor 0.5 y y mayor de 1
    // la x menor va a ser de 0.2 a 0.7
    //cara principal
    s = new Superficie(1,0,0);
    s->agregar(new Vertice( 0.2,0.5,0.9));
    s->agregar(new Vertice( 0.7,0.5,0.9));
    s->agregar(new Vertice( 0.7,1,0.9));
    s->agregar(new Vertice( 0.2,1,0.9));
    agregar(s);

    //cara derecha
    s = new Superficie(1,0,0);
    s->agregar(new Vertice( 0.7, 0.5, 0.9));
    s->agregar(new Vertice( 0.7, 0.5, 0.5));
    s->agregar(new Vertice( 0.7, 1,  0.5));
    s->agregar(new Vertice( 0.7, 1, 0.9));
    agregar(s);

    //cara trasera
    s = new Superficie(1,0,0);
    s->agregar(new Vertice( 0.7, 0.5,  0.5));
    s->agregar(new Vertice( 0.2, 0.5,  0.5));
    s->agregar(new Vertice( 0.2, 1, 0.5));
    s->agregar(new Vertice( 0.7, 1, 0.5));
    agregar(s);

    //cara izquierda
    s = new Superficie(1,0,0);
    s->agregar(new Vertice( 0.2, 0.5,  0.5));
    s->agregar(new Vertice( 0.2, 0.5, 0.9));
    s->agregar(new Vertice( 0.2, 1, 0.9));
    s->agregar(new Vertice( 0.2, 1,  0.5));
    agregar(s);

    //cara superior
    s = new Superficie(1,0,0);
    s->agregar(new Vertice( 0.2, 1, 0.9));
    s->agregar(new Vertice( 0.7, 1, 0.9));
    s->agregar(new Vertice( 0.7, 1, 0.5));
    s->agregar(new Vertice( 0.2, 1, 0.5));
    agregar(s);

    //cara inferior
    s = new Superficie(1,0,0);
    s->agregar(new Vertice( 0.2, 0.5, 0.9));
    s->agregar(new Vertice( 0.2, 0.5,  0.5));
    s->agregar(new Vertice( 0.7, 0.5,  0.5));
    s->agregar(new Vertice( 0.7, 0.5, 0.9));
    agregar(s);


}

Cabeza* Cabeza::copia(){
    Cabeza *pCopia = new Cabeza();
    for(Superficie *s:this->superficies){
        pCopia->agregar(s->copia());
    }
    pCopia->EjeX = this->EjeX->copia();
    pCopia->EjeY = this->EjeY->copia();
    pCopia->EjeZ = this->EjeZ->copia();
    return pCopia;
}
