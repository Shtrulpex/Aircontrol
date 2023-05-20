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
    ~GISMapWidget();

    void OpenMap(QgsVectorLayer* controlPointsLayer, QgsVectorLayer* RootLayer);

private:

    QgsVectorLayer* earthLayer = new QgsVectorLayer("/home/sofia/4 semestr/SuperProject/Related Projects"
                                                    "/maps/kx-world-land-areas-110-million-SHP"
                                                    "/world-land-areas-110-million.shp",
                                                    "earth", "ogr");

signals:
    void readLayersFromProjRequest(const QString& path, const QgsCoordinateReferenceSystem destCoord);
};

#endif // GISMAPWIDGET_H
