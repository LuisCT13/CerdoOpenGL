#ifndef TORSO_H
#define TORSO_H
#include "objeto3d.h"

class Torso: public Objeto3D
{
public:
    Torso();
    Torso* copia();
};

#endif // TORSO_H
