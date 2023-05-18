#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QMainWindow>

#include "MapController.h"
#include "WindowController.h"

class CentralWidget: public QObject
{
    Q_OBJECT
public:
    CentralWidget();
    ~CentralWidget();
private:

    MapController* map_controller = nullptr;
    WindowController* window_controller = nullptr;
};

#endif // CENTRALWIDGET_H
