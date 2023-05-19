#include "CentralWidget.h"

CentralWidget::CentralWidget()
{
    map_controller = new MapController();
    window_controller = new MainWindow(map_controller->GetMap());

    connect(window_controller, SIGNAL(ItemClicked(QgsRectangle)),
            map_controller, SLOT(ScaleToRect(QgsRectangle)));
    connect(window_controller, SIGNAL(DrawPoint(QgsPointXY)),
            map_controller, SLOT(DrawPoint(QgsPointXY)));
    connect(window_controller, SIGNAL(DrawRoot(std::vector<Point>&)),
            map_controller, SLOT(MapDrawRoot(std::vector<Point>&)));
}

CentralWidget::~CentralWidget() {}
