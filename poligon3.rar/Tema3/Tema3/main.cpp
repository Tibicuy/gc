#include "InterpolationWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InterpolationWidget w;
    w.show();
    return a.exec();
}
