#ifndef OBJETO3D_H
#define OBJETO3D_H

#include "superficie.h"
#include "linea.h"

class Objeto3D
{
public:
    vector<Superficie*> superficies;
    Objeto3D();
    ~Objeto3D();
    void agregar(Superficie*);
    void desplegar();
    Objeto3D *copia();
    void rotar(float,Linea*);
    void transformar(Matriz3D*);
    void trasladar(float, float, float);
    void mover(float, float, float);
    Linea *EjeX;
    Linea *EjeY;
    Linea *EjeZ;

};

#endif // OBJETO3D_H
