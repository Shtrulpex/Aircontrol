#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QMainWindow>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>

#include "./ui_mainwindow.h"
#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

#include "GISMapWidget.h"
#include "./server/data_struct.h"



class MapController:public QObject
{
    Q_OBJECT
public:
    MapController();
    ~MapController();

    GISMapWidget* GetMap() const;

public slots:
    void ScaleToRect(QgsRectangle rect);
    void DrawPoint(const QgsPointXY &point, bool choose);
    void MapDrawRoot(std::vector<Point>& root);

private:

    GISMapWidget* map = nullptr;
    QgsVectorLayer* PointLayer1 = new QgsVectorLayer("Point", "Points", "memory");
    QgsVectorLayer* PointLayer2 = new QgsVectorLayer("Point", "Points", "memory");
    QgsVectorLayer* RootLayer = new QgsVectorLayer("linestring", "line", "memory");

    void addControlPoint(const QgsPointXY &point, QgsVectorLayer* PointsLayer);
    void ClearPoint(const QgsPointXY &point, bool choose);
    void clearRoot();
};

#endif // MENUCONTROLLER_H
//QObject
