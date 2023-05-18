#include <QApplication>
#include <iostream>

#include "CentralWidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CentralWidget w;
    //WindowController w;
    //w.show();
    return a.exec();
}
