#include "openglwidget.h"
#include "cabeza.h"
#include "torso.h"
#include "cerdo.h"

OpenGLWidget::OpenGLWidget() {
    anguloX=15;
    anguloY=15;
    anguloZ=15;
    angulo=15;
    sentido=1;
    focoX = 0.0f;
    focoY = 1.0f;
    setMouseTracking(true);
    //QColor rosaCuerpo(255, 188, 191);
    objeto3D=new Objeto3D();
    Superficie* s=new Superficie(1,0,0);
    float x1 = 510, x2 = 460, y1 = 420, y2 = 321, z1 = 390, z2 = 340, z5 = 0.975, z6 = 0.9;
    float x3 = 0.4, x4 = 0.6, y3= 0.6, y4 = 0.8;
    this->opcionesdeRotacion='x';
    cerdito = new Cerdo();

    sup = cerdito->copia();
    inf = cerdito->copia();
    lat = cerdito->copia();


}

void OpenGLWidget::initializeGL() {
    glClearColor(1,1,1,0);
    //desplegarCopias();
    update();

}

void OpenGLWidget::timerEvent(QTimerEvent *) {
    if(opcionesdeRotacion=='x'){
     cerdito->rotar((angulo/3.14)/180, 'x');
    }
    else if(opcionesdeRotacion=='y'){
    cerdito->rotar((angulo/3.14)/180, 'y');
    }
    else if(opcionesdeRotacion=='z'){
    cerdito->rotar((angulo/3.14)/180, 'z');
    }
    desplegarCopias();
    update();
}

void OpenGLWidget::mousePressEvent(QMouseEvent *e){
    timer.start(50, this);
    if(e->button() == Qt::RightButton){
        sentido = 1;
    }
    else if(e->button()==Qt::LeftButton){
        sentido = -1;
    }
    update();
}
void OpenGLWidget::mouseReleaseEvent(QMouseEvent *){
    timer.stop();
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *e) {
    int ancho = width();
    int alto = height();
    focoX = (2.0f * e->position().x() / ancho) - 1.0f;
    focoY = 1.0f - (2.0f * e->position().y() / alto);
    update();
}
void OpenGLWidget::desplegarCopias( ) {


    sup = cerdito->copia();
    inf = cerdito->copia();
    lat = cerdito->copia();

    //Declaración de la Matriz de Escalado para Hcaer mas pequeñas las Vistas
    float factorEscalado = 0.4; // Escala a la mitad del tamaño original
    Matriz3D* matrizEscalado = new Matriz3D(factorEscalado, 0, 0, 0,
                                            0, factorEscalado, 0, 0,
                                            0, 0, factorEscalado, 0);
    float factorEscalado2 = 0.7; // Escala a la mitad del tamaño original
    Matriz3D* matrizEscaladoOrg = new Matriz3D(factorEscalado2, 0, 0, 0,
                                            0, factorEscalado2, 0, 0,
                                            0, 0, factorEscalado2, 0);
    sup->escalarPiezas(matrizEscalado);
    inf->escalarPiezas(matrizEscalado);
    lat->escalarPiezas(matrizEscalado);
    //cerdito->escalarPiezas(matrizEscaladoOrg);

    //Aplicar las Transformaciones para las vistas
    //Superior
    float angSup = 90.0 * M_PI / 180.0; // Convertir a radianes
    Matriz3D* matrizRotacionSup = new Matriz3D(1, 0, 0, 0,
                                               0, cos(angSup), -sin(angSup), 0,
                                               0, sin(angSup), cos(angSup), 0);
    sup->escalarPiezas(matrizRotacionSup);
        //Inferior
    float anguloInf = 90.0 * M_PI / -180.0; // Convertir a radianes
    Matriz3D* matrizRotacionInf = new Matriz3D(1, 0, 0, 0,
                                               0, cos(anguloInf), -sin(anguloInf), 0,
                                               0, sin(anguloInf), cos(anguloInf), 0);
    inf->escalarPiezas(matrizRotacionInf);
        //lateral
    float anguloLat = 90.0 * M_PI / -180.0; // Convertir a radianes
    Matriz3D* matrizRotacionLateral = new Matriz3D(cos(anguloLat), 0, sin(anguloLat), 0,
                                                   0, 1, 0, 0,
                                                   -sin(anguloLat), 0, cos(anguloLat), 0);
    lat->escalarPiezas(matrizRotacionLateral);

    // //Traslación de las Copias
    sup->trasladar(-1.1, -0.8, 0);
    inf->trasladar(-0.3, -1, 0);
    lat->trasladar(1, -1, 0);

    delete matrizEscalado;
    delete matrizRotacionInf;
    delete matrizRotacionLateral;
    delete matrizRotacionSup;

     // inf->desplegar();
     // lat->desplegar();
     // sup->desplegar();

}

void OpenGLWidget::paintGL( ) {


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glLoadIdentity();

    // Configura la luz con las coordenadas dinámicas
    float luzAmbiente[] = {0.2, 0.2, 0.2, 1};
    float luzDifusa[] = {1.0, 1.0, 1.0, 1};
    float luzPosicion[] = {focoX, focoY, 2.0f, 1};
    float luz_aten[] = {0.2};

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_POSITION, luzPosicion);
    glLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, luz_aten);

    glNormal3f(0, 0, 1);
    glColor3f(1.2f, 0.75f, 0.75f);

    //Rotacion de la figura
    glTranslatef(0.25, 0.25, -3.5);
    glTranslatef(-0.25, -0.25, 0.25);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,2.0,10.0);
    glMatrixMode(GL_MODELVIEW);

    cerdito->desplegar();
    //glPushMatrix();
    //desplegarCopias();
    //glPopMatrix();
    // glPushMatrix(); // Guardar el estado de la matriz
    sup->desplegar(); // Dibujar la copia superior
    // glPopMatrix(); // Restaurar el estado de la matriz

    // glPushMatrix(); // Guardar el estado de la matriz
     inf->desplegar(); // Dibujar la copia inferior
    // glPopMatrix(); // Restaurar el estado de la matriz

    // glPushMatrix(); // Guardar el estado de la matriz
     lat->desplegar(); // Dibujar la copia lateral
    // glPopMatrix(); // Restaurar el estado de la matriz

}

