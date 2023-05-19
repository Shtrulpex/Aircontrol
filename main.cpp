#include <QApplication>
#include <iostream>

#include "CentralWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CentralWidget w;
    return a.exec();
}
