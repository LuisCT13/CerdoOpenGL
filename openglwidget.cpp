#include "openglwidget.h"
#include "cabeza.h"
#include "torso.h"

OpenGLWidget::OpenGLWidget() {
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


    // ---- PATA SUPERIOR IZQUIERDA ----

    int z3 = 240/100, z4 = 190/100;

    //parte de ARRIBA
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y2, z4));
    s->agregar(new Vertice(440, y2, z4));
    s->agregar(new Vertice(440, y2, z3));
    s->agregar(new Vertice(390, y2, z3));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupIzq(s);
    // objeto3D->agregarPatas(s);


    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z4));
    s->agregar(new Vertice(440, y1, z4));
    s->agregar(new Vertice(440, y1, z3));
    s->agregar(new Vertice(390, y1, z3));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de derecha
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(440, y1, z4));
    s->agregar(new Vertice(440, y1, z3));
    s->agregar(new Vertice(440, y2, z3));
    s->agregar(new Vertice(440, y2, z4));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de izquierda
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z4));
    s->agregar(new Vertice(390, y1, z3));
    s->agregar(new Vertice(390, y2, z3));
    s->agregar(new Vertice(390, y2, z4));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z3));
    s->agregar(new Vertice(440, y1, z3));
    s->agregar(new Vertice(440, y2, z3));
    s->agregar(new Vertice(390, y2, z3));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, z4));
    s->agregar(new Vertice(440, y1, z4));
    s->agregar(new Vertice(440, y2, z4));
    s->agregar(new Vertice(390, y2, z4));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupIzq(s);
    // objeto3D->agregarPatas(s);



    // ---- PATA INFERIOR IZQUIERDA ----
    //parte de ARRIBA
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y2, 340));
    s->agregar(new Vertice(440, y2, 340));
    s->agregar(new Vertice(440, y2, 390));
    s->agregar(new Vertice(390, y2, 390));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, 340));
    s->agregar(new Vertice(440, y1, 340));
    s->agregar(new Vertice(440, y1, 390));
    s->agregar(new Vertice(390, y1, 390));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de derecha
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(440, y1, 340));
    s->agregar(new Vertice(440, y1, 390));
    s->agregar(new Vertice(440, y2, 390));
    s->agregar(new Vertice(440, y2, 340));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de izquierda
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, 340));
    s->agregar(new Vertice(390, y1, 390));
    s->agregar(new Vertice(390, y2, 390));
    s->agregar(new Vertice(390, y2, 340));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, 390));
    s->agregar(new Vertice(440, y1, 390));
    s->agregar(new Vertice(440, y2, 390));
    s->agregar(new Vertice(390, y2, 390));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfIzq(s);
    // objeto3D->agregarPatas(s);



    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(390, y1, 340));
    s->agregar(new Vertice(440, y1, 340));
    s->agregar(new Vertice(440, y2, 340));
    s->agregar(new Vertice(390, y2, 340));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfIzq(s);
    // objeto3D->agregarPatas(s);



    // ---- PATA INFERIOR DERECHA ----


    //parte de ARRIBA
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y2, z2));
    s->agregar(new Vertice(x1, y2, z2));
    s->agregar(new Vertice(x1, y2, z1));
    s->agregar(new Vertice(x2, y2, z1));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfDer(s);
    // objeto3D->agregarPatas(s);



    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x1, y1, z2));
    s->agregar(new Vertice(x1, y1, z1));
    s->agregar(new Vertice(x2, y1, z1));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfDer(s);
    // objeto3D->agregarPatas(s);



    //parte de derecha
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y1, z2));
    s->agregar(new Vertice(x1, y1, z1));
    s->agregar(new Vertice(x1, y2, z1));
    s->agregar(new Vertice(x1, y2, z2));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfDer(s);
    // objeto3D->agregarPatas(s);



    //parte de izquierda
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x2, y1, z1));
    s->agregar(new Vertice(x2, y2, z1));
    s->agregar(new Vertice(x2, y2, z2));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfDer(s);
    // objeto3D->agregarPatas(s);



    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z1));
    s->agregar(new Vertice(x1, y1, z1));
    s->agregar(new Vertice(x1, y2, z1));
    s->agregar(new Vertice(x2, y2, z1));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfDer(s);
    // objeto3D->agregarPatas(s);



    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z2));
    s->agregar(new Vertice(x1, y1, z2));
    s->agregar(new Vertice(x1, y2, z2));
    s->agregar(new Vertice(x2, y2, z2));
    objeto3D->agregar(s);
    // objeto3D->agregarPataInfDer(s);
    // objeto3D->agregarPatas(s);



    // ---- PATA SUPERIOR DERECHA ----
    //parte de ARRIBA
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y2, z4));
    s->agregar(new Vertice(x1, y2, z4));
    s->agregar(new Vertice(x1, y2, z3));
    s->agregar(new Vertice(x2, y2, z3));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupDer(s);
    // objeto3D->agregarPatas(s);



    //parte de abajo
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z4));
    s->agregar(new Vertice(x1, y1, z4));
    s->agregar(new Vertice(x1, y1, z3));
    s->agregar(new Vertice(x2, y1, z3));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupDer(s);
    // objeto3D->agregarPatas(s);



    //parte de derecha
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x1, y1, z4));
    s->agregar(new Vertice(x1, y1, z3));
    s->agregar(new Vertice(x1, y2, z3));
    s->agregar(new Vertice(x1, y2, z4));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupDer(s);
    // objeto3D->agregarPatas(s);



    //parte de izquierda
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z4));
    s->agregar(new Vertice(x2, y1, z3));
    s->agregar(new Vertice(x2, y2, z3));
    s->agregar(new Vertice(x2, y2, z4));
    objeto3D->agregar(s);
    //objeto3D->agregarPataSupDer(s);
    //objeto3D->agregarPatas(s);



    //parte de atrás
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z3));
    s->agregar(new Vertice(x1, y1, z3));
    s->agregar(new Vertice(x1, y2, z3));
    s->agregar(new Vertice(x2, y2, z3));
    objeto3D->agregar(s);
    //objeto3D->agregarPataSupDer(s);
    //objeto3D->agregarPatas(s);



    //parte de enfrente
    s = new Superficie(1,0,0);// X    Y    Z
    s->agregar(new Vertice(x2, y1, z4));
    s->agregar(new Vertice(x1, y1, z4));
    s->agregar(new Vertice(x1, y2, z4));
    s->agregar(new Vertice(x2, y2, z4));
    objeto3D->agregar(s);
    // objeto3D->agregarPataSupDer(s);
    //objeto3D->agregarPatas(s);
}

void OpenGLWidget::initializeGL() {
    glClearColor(1,1,1,0);
}

void OpenGLWidget::timerEvent(QTimerEvent *) {
    angulo+=sentido;
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

    glTranslatef(0.25, 0.25, -3.5);
    glRotated(angulo, 0, 1, 0);
    glRotated(15, 1, 0, 0);
    glTranslatef(-0.25, -0.25, 0.25);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,2.0,10.0);
    glMatrixMode(GL_MODELVIEW);

    QSize tam=size();
    //glViewport(tam.width()/2,tam.height()/2,tam.width()/2,tam.height()/2);
    Cabeza *cabeza1 = new Cabeza();
    Torso *torso1 = new Torso();
    cabeza1->desplegar();
    torso1->desplegar();

    //objeto3D->desplegar();

    //Objeto3D* copia=objeto3D->copia();
    //copia->transformar(new Matriz3D(1,0,0,1,0,1,0,0,0,0,1,0));
    //float ang=(angulo*5*3.14159)/180.0;
    // copia->rotar(ang,new Linea(1.25,0.25,0.0,1.25,0.25,-0.5));
    //copia->desplegar();
}
