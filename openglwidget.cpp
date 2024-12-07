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
    this->opcionesdeRotacion='x';
    cerdito = new Cerdo();
    inf = new Cerdo();
    sup = new Cerdo();
    lat = new Cerdo();
    desplegarCopias();

}

void OpenGLWidget::initializeGL() {
    glClearColor(1,1,1,0);
   // desplegarCopias();
    update();
}

void OpenGLWidget::timerEvent(QTimerEvent *) {

    if(opcionesdeRotacion=='x'){
     cerdito->rotar((angulo/3.14)/180, 'x');
     sup->rotar((angulo/3.14)/180, 'x');
     inf->rotar((angulo/3.14)/180, 'x');
     lat->rotar((angulo/3.14)/180, 'x');


    }
    else if(opcionesdeRotacion=='y'){
    cerdito->rotar((angulo/3.14)/180, 'y');
        sup->rotar((angulo/3.14)/180, 'y');
        inf->rotar((angulo/3.14)/180, 'y');
        lat->rotar((angulo/3.14)/180, 'y');
    }
    else if(opcionesdeRotacion=='z'){
    cerdito->rotar((angulo/3.14)/180, 'z');
        sup->rotar((angulo/3.14)/180, 'z');
        inf->rotar((angulo/3.14)/180, 'z');
        lat->rotar((angulo/3.14)/180, 'z');
    }

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
    //desplegarCopias();
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
void OpenGLWidget::desplegarCopias() {
    // Eliminar las copias previas para evitar fugas de memoria
    // delete sup;
    // delete inf;
    // delete lat;

    // Crear nuevas copias basadas en el estado actual del cerdito
    // sup = cerdito->copia();
    // inf = cerdito->copia();
    // lat = cerdito->copia();

    // Declaración de la matriz de escalado para hacer más pequeñas las vistas
    float factorEscalado = 0.4; // Escala al 40% del tamaño original
    Matriz3D* matrizEscalado = new Matriz3D(factorEscalado, 0, 0, 0,
                                            0, factorEscalado, 0, 0,
                                            0, 0, factorEscalado, 0);

    // Aplicar escalado a las copias
    sup->escalarPiezas(matrizEscalado);
    inf->escalarPiezas(matrizEscalado);
    lat->escalarPiezas(matrizEscalado);

    // Aplicar transformaciones específicas para cada copia
    // Superior
    float angSup = 90.0 * M_PI / 180.0; // Convertir a radianes
    Matriz3D* matrizRotacionSup = new Matriz3D(1, 0, 0, 0,
                                               0, cos(angSup), -sin(angSup), 0,
                                               0, sin(angSup), cos(angSup), 0);
    sup->escalarPiezas(matrizRotacionSup);

    // Inferior
    float angInf = -90.0 * M_PI / 180.0; // Convertir a radianes
    Matriz3D* matrizRotacionInf = new Matriz3D(1, 0, 0, 0,
                                               0, cos(angInf), -sin(angInf), 0,
                                               0, sin(angInf), cos(angInf), 0);
    inf->escalarPiezas(matrizRotacionInf);

    // Lateral
    float angLat = 90.0 * M_PI / 180.0; // Convertir a radianes
    Matriz3D* matrizRotacionLat = new Matriz3D(cos(angLat), 0, sin(angLat), 0,
                                               0, 1, 0, 0,
                                               -sin(angLat), 0, cos(angLat), 0);
    lat->escalarPiezas(matrizRotacionLat);

    // Traslación de las copias
    sup->trasladar(-1.1, -0.8, 0);
    inf->trasladar(-0.3, -1, 0);
    lat->trasladar(1, -1, 0);

    // Liberar memoria de las matrices creadas
    delete matrizEscalado;
    delete matrizRotacionSup;
    delete matrizRotacionInf;
    delete matrizRotacionLat;

}


void OpenGLWidget::paintGL() {
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

    // Configuración de la cámara
    glTranslatef(0.25, 0.25, -3.5);
    glTranslatef(-0.25, -0.25, 0.25);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    // Dibujar la figura principal
    glPushMatrix();
    cerdito->desplegar();
    glPopMatrix();

    if (sup != nullptr) {
        qDebug() << "Dibujando copia sup";
        glPushMatrix();
        sup->desplegar();
        glPopMatrix();
    }

    if (inf != nullptr) {
        qDebug() << "Dibujando copia inf";
        glPushMatrix();
        inf->desplegar();
        glPopMatrix();
    }

    if (lat != nullptr) {
        qDebug() << "Dibujando copia lat";
        glPushMatrix();
        lat->desplegar();
        glPopMatrix();
    }
    update();
}

