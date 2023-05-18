#include "WindowController.h".h"
#include "GISMapWidget.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WindowController w;
    w.show();
    return a.exec();
}
