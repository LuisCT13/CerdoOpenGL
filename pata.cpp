#include "pata.h"


Pata::Pata(float x1, float x2,
           float y1, float y2,
           float z1, float z2) {

    /* x1, y1 y z1 deben ser números más chicos
     * x2, y2, z2 son números más grandes*/

    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
    this->z1 = z1;
    this->z2 = z2;

    /*float centroX = (x1 + x2) / 2;
    float centroY = y2;
    float centroZ = (z1 + z2) / 2;

    // Definir la longitud de los ejes (ajusta el valor según sea necesario)
    float longitudEje = 0.5f;

    this->EjeX = new Linea(centroX - longitudEje, centroY, centroZ, centroX + longitudEje, centroY, centroZ);
    this->EjeY = new Linea(centroX, centroY + longitudEje, centroZ, centroX, centroY - longitudEje, centroZ);
    this->EjeZ = new Linea(centroX, centroY, centroZ + longitudEje, centroX, centroY, centroZ - longitudEje);*/

    Superficie* s;

    //parte de ARRIBA
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x2, y1, z1));
    s->agregar(new Vertice(x2, y2, z1));
    s->agregar(new Vertice(x2, y2, z2));
    agregar(s);

    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y1, z2));
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x2, y2, z2));
    s->agregar(new Vertice(x1, y2, z2));
    agregar(s);

    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y2, z1));
    s->agregar(new Vertice(x2, y2, z1));
    s->agregar(new Vertice(x2, y1, z1));
    s->agregar(new Vertice(x1, y1, z1));
    agregar(s);

    //lado izquierdo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y1, z1));
    s->agregar(new Vertice(x1, y1, z2));
    s->agregar(new Vertice(x1, y2, z2));
    s->agregar(new Vertice(x1, y2, z1));
    agregar(s);

    //parte de arriba
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y2, z2));
    s->agregar(new Vertice(x2, y2, z2));
    s->agregar(new Vertice(x2, y2, z1));
    s->agregar(new Vertice(x1, y2, z1));
    agregar(s);

    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y1, z1));
    s->agregar(new Vertice(x2, y1, z1));
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x1, y1, z2));
    agregar(s);


}

void Pata::moverPatas(float dx, float dz){
    // Acumula las transformaciones
    glTranslatef(dx, 0.0f, dz);
}

Pata* Pata::copia() {
    // Obtener los valores de los parámetros del objeto original
    float x1 = this->x1;  // Obtener el valor de x1
    float x2 = this->x2;  // Obtener el valor de x2
    float y1 = this->y1;  // Obtener el valor de y1
    float y2 = this->y2;  // Obtener el valor de y2
    float z1 = this->z1;  // Obtener el valor de z1
    float z2 = this->z2;  // Obtener el valor de z2

    Pata* copia = new Pata(x1, x2, y1, y2, z1, z2); // Crear una nueva instancia de Pata

    // Copiar las superficies
    for (Superficie* superficie : superficies) {
        copia->agregar(superficie->copia());
    }

    // Copiar los ejes
    copia->EjeX = this->EjeX->copia();
    copia->EjeY = this->EjeY->copia();
    copia->EjeZ = this->EjeZ->copia();

    return copia;
}
