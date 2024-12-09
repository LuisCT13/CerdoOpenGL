#include "torso.h"

Torso::Torso() {

    // Calcular el centro del torso
    float centroX = 0.45f;
    float centroY = 0.475f;
    float centroZ = 0.025f;

    // Definir la longitud de los ejes (ajusta el valor según sea necesario)
    float longitudEje = 0.5f;

    // Crear los ejes de rotación
    /*this->EjeX = new Linea(centroX - longitudEje, centroY, centroZ, centroX + longitudEje, centroY, centroZ);
    this->EjeY = new Linea(centroX, centroY + longitudEje, centroZ, centroX, centroY - longitudEje, centroZ);
    this->EjeZ = new Linea(centroX, centroY, centroZ + longitudEje, centroX, centroY, centroZ - longitudEje);*/


    //CREACION DE L TORSO DEL CERDO
    //En z comeinza en 0.5 y termina el -0.2
    //En X 0.1 y termina en 1
    // EN Y en 0.75 y termina en 0.2
    //lado derecho
    Superficie *s = new Superficie(1,0,0);// X    Y    Z
    agregarFigura(s, 0.1, 0.8, 0.2, 0.75, -0.45, 0.5);

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
