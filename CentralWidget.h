#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QMainWindow>

#include "MapController.h"
#include "MainWindow.h"

class CentralWidget: public QObject
{
    Q_OBJECT
public:
    CentralWidget();
    ~CentralWidget();
private:

    MapController* map_controller = nullptr;
    MainWindow* window_controller = nullptr;
};

#endif // CENTRALWIDGET_H
