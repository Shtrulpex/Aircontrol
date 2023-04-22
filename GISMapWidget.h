#ifndef GISMAPWIDGET_H
#define GISMAPWIDGET_H

#include <qgsvectorlayer.h>
#include <QMainWindow>

#include <qgsmapcanvas.h>

class GISMapWidget: public QgsMapCanvas
{
    Q_OBJECT

public:
    explicit GISMapWidget(QWidget* parent = nullptr);
    //~GISMapWidget();

    void OpenMap();
    void updateLayers(QList<QgsMapLayer*> layers);
signals:
    void readLayersFromProjRequest(const QString& path, const QgsCoordinateReferenceSystem destCoord);
};

#endif // GISMAPWIDGET_H
