#ifndef TORSO_H
#define TORSO_H
#include "objeto3d.h"

class Torso: public Objeto3D
{
public:
    Torso();
    Torso* copia();
    /*Linea *EjeX;
    Linea *EjeY;
    Linea *EjeZ;*/
};

#endif // TORSO_H
