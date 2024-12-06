#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QBasicTimer>
#include <QMouseEvent>
#include "objeto3d.h"
#include "linea.h"
#include "cerdo.h"

class OpenGLWidget : public QOpenGLWidget
{
public:
    OpenGLWidget();
    char opcionesdeRotacion;

private:
    Cerdo *cerdito;
    Cerdo *inf;
    Cerdo *sup;
    Cerdo *lat;
    int angulo;
    int anguloX;
    int anguloY;
    int anguloZ;
    QBasicTimer timer;
    int sentido;
    float focoX;
    float focoY;
    Objeto3D* objeto3D;
    void initializeGL();
    void paintGL();
    void mouseMoveEvent(QMouseEvent *);
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void rotarenEje(Linea*);
    void desplegarCopias();
};

#endif // OPENGLWIDGET_H
