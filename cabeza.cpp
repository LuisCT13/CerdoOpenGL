#include "cabeza.h"

Cabeza::Cabeza(){
    //CREACION DE LA CABEZA Y NARIZ
    Superficie* s=new Superficie(1,0,0);
    float  z5 = 0.975, z6 = 0.9, x3 = 0.3, x4 = 0.6, y3= 0.6, y4 = 0.8;
    //Superficie *s;

    // ---- NARIZ DEL CERDO ----
    agregarFigura(s, 0.3, 0.6, 0.6, 0.8, 0.9, 0.975);

    // ---- CABEZA DEL CERDO ----
    //y menor 0.5 y y mayor de 1
    // la x menor va a ser de 0.2 a 0.7
    agregarFigura(s, 0.2, 0.7, 0.5, 1.0, 0.5, 0.9);

    // ---- OJOS DEL CERDO ----
    agregarFigura(s, 0.2, 0.7, 0.5, 1.0, 0.5, 0.9);


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
