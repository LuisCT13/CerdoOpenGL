#include "pata.h"


Pata::Pata(float x1, float x2,
           float y1, float y2,
           float z1, float z2) {

    /* x1, y1 y z1 deben ser números más chicos
     * x2, y2, z2 son números más grandes*/

    Objeto3D* obj = new Objeto3D();
    Superficie* s = new Superficie(1,0,0);

    //parte de ARRIBA
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y2, z4));
    s->agregar(new Vertice(440, y2, z4));
    s->agregar(new Vertice(440, y2, z3));
    s->agregar(new Vertice(390, y2, z3));
    obj->agregar(s);



    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z4));
    s->agregar(new Vertice(440, y1, z4));
    s->agregar(new Vertice(440, y1, z3));
    s->agregar(new Vertice(390, y1, z3));
    obj->agregar(s);



    //parte de derecha
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(440, y1, z4));
    s->agregar(new Vertice(440, y1, z3));
    s->agregar(new Vertice(440, y2, z3));
    s->agregar(new Vertice(440, y2, z4));
    objeto3D->agregar(s);
    objeto3D->agregarPataSupIzq(s);
    objeto3D->agregarPatas(s);



    //parte de izquierda
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z4));
    s->agregar(new Vertice(390, y1, z3));
    s->agregar(new Vertice(390, y2, z3));
    s->agregar(new Vertice(390, y2, z4));
    obj->agregar(s);



    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z3));
    s->agregar(new Vertice(440, y1, z3));
    s->agregar(new Vertice(440, y2, z3));
    s->agregar(new Vertice(390, y2, z3));
    obj->agregar(s);



    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z4));
    s->agregar(new Vertice(440, y1, z4));
    s->agregar(new Vertice(440, y2, z4));
    s->agregar(new Vertice(390, y2, z4));
    obj->agregar(s);


}
