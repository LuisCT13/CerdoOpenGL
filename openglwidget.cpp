#include "openglwidget.h"
#include "cabeza.h"
#include "torso.h"
#include "cerdo.h"

bool rotarX = false;
bool rotarY = false;
bool rotarZ = false;
int lastMouseX = 0;
int lastMouseY = 0;

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
    this->opcionesdeRotacion='x';
    cerdito = new Cerdo();

}

void OpenGLWidget::initializeGL() {
    glClearColor(1,1,1,0);
}

void OpenGLWidget::timerEvent(QTimerEvent *) {
    if (rotarX) {
        cerdito->rotar((angulo / 3.14) / 180, 'x');
    }
    if (rotarY) {
        cerdito->rotar((angulo / 3.14) / 180, 'y');
    }
    if (rotarZ) {
        cerdito->rotar((angulo / 3.14) / 180, 'z');
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
    if (e->buttons() & Qt::LeftButton) {
        int dx = e->x() - lastMouseX;
        int dy = e->y() - lastMouseY;

        // Ajusta la sensibilidad de la rotación según sea necesario
        float anguloX = -dy / 100.0f;
        float anguloY = -dx / 100.0f;

        cerdito->rotar(anguloX, 'x');
        cerdito->rotar(anguloY, 'y');
    }
    lastMouseX = e->x();
    lastMouseY = e->y();
    update();
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
}

void OpenGLWidget::rotarEnX() {
    rotarX = !rotarX;
}

void OpenGLWidget::rotarEnY() {
    rotarY = !rotarY;
}

void OpenGLWidget::rotarEnZ() {
    rotarZ = !rotarZ;
}
