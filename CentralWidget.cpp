#include "CentralWidget.h"

CentralWidget::CentralWidget()
{
    map_controller = new MapController();
    window_controller = new MainWindow(map_controller->GetMap());

    connect(window_controller, SIGNAL(ItemClicked(QgsRectangle)),
            map_controller, SLOT(ScaleToRect(QgsRectangle)));
}

CentralWidget::~CentralWidget() {}
