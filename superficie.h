#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include "vertice.h"
#include "linea.h"
#include <vector>
using namespace std;

class Superficie
{
public:
    float r,v,a;
    vector<Vertice*> vertices;
    Superficie(float,float,float);
    ~Superficie();
    void agregar(Vertice*);
    Superficie* copia();
    void desplegar();
    void transformar(Matriz3D*);
    void trasladar(float, float, float);

};

#endif // SUPERFICIE_H
