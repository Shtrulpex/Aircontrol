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
    void DrawPoint(const QgsPointXY &point);
    void MapDrawRoot(std::vector<Point>& root);

private:

    GISMapWidget* map = nullptr;
    QgsVectorLayer* PointsLayer = new QgsVectorLayer("Point", "Points", "memory");
    QgsVectorLayer* RootLayer = new QgsVectorLayer("linestring", "line", "memory");

    void addControlPoint(const QgsPointXY &point);
    void ClearPoint(const QgsPoint &point);
};

#endif // MENUCONTROLLER_H
//QObject
