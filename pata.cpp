#include "pata.h"


Pata::Pata(float x1, float x2,
           float y1, float y2,
           float z1, float z2) {

    /* x1, y1 y z1 deben ser números más chicos
     * x2, y2, z2 son números más grandes*/

    Superficie* s = new Superficie(1,0,0);

    //parte de ARRIBA
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y1, z1));
    s->agregar(new Vertice(x2, y1, z1));
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x1, y1, z2));
    agregar(s);



    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y2, z1));
    s->agregar(new Vertice(x2, y2, z1));
    s->agregar(new Vertice(x2, y2, z2));
    s->agregar(new Vertice(x1, y2, z2));
    agregar(s);



    //parte de derecha
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y2, z1));
    s->agregar(new Vertice(x2, y2, z2));
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x2, y1, z1));
    agregar(s);



    //parte de izquierda
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y2, z1));
    s->agregar(new Vertice(x1, y2, z2));
    s->agregar(new Vertice(x1, y1, z2));
    s->agregar(new Vertice(x1, y1, z1));
    agregar(s);



    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y2, z2));
    s->agregar(new Vertice(x2, y2, z2));
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x1, y1, z2));
    agregar(s);



    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y2, z1));
    s->agregar(new Vertice(x2, y2, z1));
    s->agregar(new Vertice(x2, y1, z1));
    s->agregar(new Vertice(x1, y1, z1));
    agregar(s);


}

void Pata::moverPatas(float dx, float dz){
    // Acumula las transformaciones
    glTranslatef(dx, 0.0f, dz);
}


