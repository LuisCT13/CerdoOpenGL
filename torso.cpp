#include "torso.h"

Torso::Torso() {
    //CREACION DE L TORSO DEL CERDO
    //En z comeinza en 0.5 y termina el -0.2
    //En X 0.1 y termina en 1
    // EN Y en 0.75 y termina en 0.2
    //lado derecho
    Superficie *s;
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(0.8, 0.2, 0.5 ));
    s->agregar(new Vertice(0.8, 0.2, -0.45));
    s->agregar(new Vertice(0.8, 0.75, -0.45));
    s->agregar(new Vertice(0.8, 0.75, 0.5));
    agregar(s);

    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(0.1, 0.2, 0.5));
    s->agregar(new Vertice(0.8, 0.2, 0.5));
    s->agregar(new Vertice(0.8, 0.75, 0.5));
    s->agregar(new Vertice(0.1, 0.75, 0.5));
    agregar(s);

    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(0.1, 0.75, -0.45));
    s->agregar(new Vertice(0.8, 0.75, -0.45));
    s->agregar(new Vertice(0.8, 0.2, -0.45));
    s->agregar(new Vertice(0.1, 0.2, -0.45));
    agregar(s);

    //lado izquierdo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(0.1, 0.2, -0.45));
    s->agregar(new Vertice(0.1, 0.2, 0.5));
    s->agregar(new Vertice(0.1, 0.75, 0.5));
    s->agregar(new Vertice(0.1, 0.75, -0.45));
    agregar(s);

    //parte de arriba
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(0.1, 0.75, 0.5));
    s->agregar(new Vertice(0.8, 0.75, 0.5));
    s->agregar(new Vertice(0.8, 0.75, -0.45));
    s->agregar(new Vertice(0.1, 0.75, -0.45));
    agregar(s);

    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(0.1, 0.2, -0.45));
    s->agregar(new Vertice(0.8, 0.2, -0.45));
    s->agregar(new Vertice(0.8, 0.2, 0.5));
    s->agregar(new Vertice(0.1, 0.2, 0.5));
    agregar(s);
}

Torso* Torso::copia() {
    Torso* copia = new Torso();
    for(Superficie *s:this->superficies){
        copia->agregar(s->copia());
    }
    copia->EjeX = this->EjeX->copia();
    copia->EjeY = this->EjeY->copia();
    copia->EjeZ = this->EjeZ->copia();
    return copia;
}
