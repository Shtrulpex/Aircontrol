#include "GISMapWidget.h"

void GISMapWidget::OpenMap()
{
    QString path = "/home/sofia/4 semestr/SuperProject/Related Projects/"
                   "Natural_Earth_quick_start/packages/Natural_Earth_quick_start/"
                   "Natural_Earth_quick_start_for_QGIS.qgs";
    emit readLayersFromProjRequest(path, QgsMapCanvas::mapSettings().destinationCrs());
    // emit is an empty macros to show it's a signal
}
