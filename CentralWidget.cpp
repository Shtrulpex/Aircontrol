#include "CentralWidget.h"

CentralWidget::CentralWidget()
{
    map_controller = new MapController();
    window_controller = new WindowController(map_controller->GetMap());
}

CentralWidget::~CentralWidget() {}
