/********************************************************************************
** Form generated from reading UI file 'Tema3.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMA3_H
#define UI_TEMA3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tema3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tema3Class)
    {
        if (Tema3Class->objectName().isEmpty())
            Tema3Class->setObjectName("Tema3Class");
        Tema3Class->resize(600, 400);
        menuBar = new QMenuBar(Tema3Class);
        menuBar->setObjectName("menuBar");
        Tema3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tema3Class);
        mainToolBar->setObjectName("mainToolBar");
        Tema3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Tema3Class);
        centralWidget->setObjectName("centralWidget");
        Tema3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Tema3Class);
        statusBar->setObjectName("statusBar");
        Tema3Class->setStatusBar(statusBar);

        retranslateUi(Tema3Class);

        QMetaObject::connectSlotsByName(Tema3Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tema3Class)
    {
        Tema3Class->setWindowTitle(QCoreApplication::translate("Tema3Class", "Tema3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tema3Class: public Ui_Tema3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMA3_H
