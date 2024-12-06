#ifndef PATA_H
#define PATA_H
#include "objeto3d.h"

class Pata : public Objeto3D {
public:
    Pata(float, float,  //x1, x2
         float, float,  //y1, y2
         float, float); //z1, z2
    void moverPatas(float, float);
};

#endif // PATA_H
