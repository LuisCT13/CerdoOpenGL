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

    centroX = (x1 + x2) / 2;
    centroY = y2;
    centroZ = (z1 + z2) / 2;

    // Definir la longitud de los ejes (ajusta el valor según sea necesario)
    float longitudEje = 0.5f;

    this->EjePX = new Linea(centroX - longitudEje, centroY, centroZ, centroX + longitudEje, centroY, centroZ);
    this->EjePY = new Linea(centroX, centroY + longitudEje, centroZ, centroX, centroY - longitudEje, centroZ);
    this->EjePZ = new Linea(centroX, centroY, centroZ + longitudEje, centroX, centroY, centroZ - longitudEje);

    Superficie* s=new Superficie(1,0,0);
    agregarFigura(s, x1, x2, y1, y2, z1, z2);


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
void Pata:: trasladarEjesPata(float x, float y, float z){
    EjePX->trasladar(x,y,z);
    EjePY->trasladar(x,y,z);
    EjePZ->trasladar(x,y,z);

}

void Pata:: transformarEjesPata(Matriz3D *m){
    EjePX->transformar(m);
    EjePY->transformar(m);
    EjePZ->transformar(m);
}
