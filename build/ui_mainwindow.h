/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *LayoutOpenGL;
    QPushButton *rotarenX;
    QPushButton *rotarenY;
    QPushButton *rotarenZ;
    QPushButton *selCabeza;
    QPushButton *selPatas;
    QPushButton *selTodo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1059, 818);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 40, 881, 721));
        LayoutOpenGL = new QGridLayout(gridLayoutWidget);
        LayoutOpenGL->setObjectName("LayoutOpenGL");
        LayoutOpenGL->setContentsMargins(0, 0, 0, 0);
        rotarenX = new QPushButton(centralwidget);
        rotarenX->setObjectName("rotarenX");
        rotarenX->setGeometry(QRect(940, 40, 80, 24));
        rotarenY = new QPushButton(centralwidget);
        rotarenY->setObjectName("rotarenY");
        rotarenY->setGeometry(QRect(940, 70, 80, 24));
        rotarenZ = new QPushButton(centralwidget);
        rotarenZ->setObjectName("rotarenZ");
        rotarenZ->setGeometry(QRect(940, 100, 80, 24));
        selCabeza = new QPushButton(centralwidget);
        selCabeza->setObjectName("selCabeza");
        selCabeza->setGeometry(QRect(940, 600, 86, 29));
        selPatas = new QPushButton(centralwidget);
        selPatas->setObjectName("selPatas");
        selPatas->setGeometry(QRect(940, 640, 86, 29));
        selTodo = new QPushButton(centralwidget);
        selTodo->setObjectName("selTodo");
        selTodo->setGeometry(QRect(940, 680, 86, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1059, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rotarenX->setText(QCoreApplication::translate("MainWindow", "Rotar en X", nullptr));
        rotarenY->setText(QCoreApplication::translate("MainWindow", "Rotar en Y", nullptr));
        rotarenZ->setText(QCoreApplication::translate("MainWindow", "Rotar en Z", nullptr));
        selCabeza->setText(QCoreApplication::translate("MainWindow", "Cabeza", nullptr));
        selPatas->setText(QCoreApplication::translate("MainWindow", "Patas", nullptr));
        selTodo->setText(QCoreApplication::translate("MainWindow", "Cerdito", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
