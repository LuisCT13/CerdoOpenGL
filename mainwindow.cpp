#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "openglwidget.h"

OpenGLWidget* openGLWidget;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLWidget=new OpenGLWidget();
    ui->LayoutOpenGL->addWidget(openGLWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_rotarenX_clicked()
{
    if (openGLWidget->opcionesdeRotacion == 'x') {
        openGLWidget->opcionesdeRotacion = ' '; // Desactivar la rotación si se presiona el mismo botón
        openGLWidget->timer.stop();
    } else {
        openGLWidget->opcionesdeRotacion = 'x';
        openGLWidget->timer.start(50, openGLWidget);
    }
}
void MainWindow::on_rotarenY_clicked()
{
    if (openGLWidget->opcionesdeRotacion == 'y') {
        openGLWidget->opcionesdeRotacion = ' '; // Desactivar la rotación si se presiona el mismo botón
        openGLWidget->timer.stop();
    } else {
        openGLWidget->opcionesdeRotacion = 'y';
        openGLWidget->timer.start(50, openGLWidget);
    }
}
void MainWindow::on_rotarenZ_clicked()
{
    if (openGLWidget->opcionesdeRotacion == 'z') {
        openGLWidget->opcionesdeRotacion = ' '; // Desactivar la rotación si se presiona el mismo botón
        openGLWidget->timer.stop();
    } else {
        openGLWidget->opcionesdeRotacion = 'z';
        openGLWidget->timer.start(50, openGLWidget);
    }
}
