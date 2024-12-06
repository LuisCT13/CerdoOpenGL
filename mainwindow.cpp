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
    openGLWidget->opcionesdeRotacion='x';

}
void MainWindow::on_rotarenY_clicked()
{
    openGLWidget->opcionesdeRotacion='y';

}
void MainWindow::on_rotarenZ_clicked()
{
    openGLWidget->opcionesdeRotacion='z';

}
