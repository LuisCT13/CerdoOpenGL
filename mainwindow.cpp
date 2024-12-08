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
    connect(ui->selTodo, &QPushButton::clicked, this, &MainWindow::on_selTodo_clicked);
    connect(ui->selCabeza, &QPushButton::clicked, this, &MainWindow::on_selCabeza_clicked);
    connect(ui->selPatas, &QPushButton::clicked, this, &MainWindow::on_selPatas_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_rotarenX_clicked()
{
    if (openGLWidget->opcionesdeRotacion == 'x') {
        openGLWidget->opcionesdeRotacion = ' '; // Desactivar la rotación
        openGLWidget->timer.stop();
    } else {
        openGLWidget->opcionesdeRotacion = 'x';
        openGLWidget->timer.start(50, openGLWidget);
    }
}
void MainWindow::on_rotarenY_clicked()
{
    if (openGLWidget->opcionesdeRotacion == 'y') {
        openGLWidget->opcionesdeRotacion = ' ';
        openGLWidget->timer.stop();
    } else {
        openGLWidget->opcionesdeRotacion = 'y';
        openGLWidget->timer.start(50, openGLWidget);
    }
}
void MainWindow::on_rotarenZ_clicked()
{
    if (openGLWidget->opcionesdeRotacion == 'z') {
        openGLWidget->opcionesdeRotacion = ' ';
        openGLWidget->timer.stop();
    } else {
        openGLWidget->opcionesdeRotacion = 'z';
        openGLWidget->timer.start(50, openGLWidget);
    }
}

void MainWindow::on_selTodo_clicked(){

    openGLWidget->estado = 1;
}

void MainWindow::on_selCabeza_clicked(){

    openGLWidget->estado = 2;
}

void MainWindow::on_selPatas_clicked(){

    openGLWidget->estado = 3;
}
