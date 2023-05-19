#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QMainWindow>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>

#include "./ui_mainwindow.h"
#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

#include "GISMapWidget.h"


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

private:

    GISMapWidget* map = nullptr;
    QgsVectorLayer* PointsLayer = new QgsVectorLayer("Point", "Points", "memory");

    void addControlPoint(const QgsPointXY &point);
    void ClearPoint(const QgsPoint &point);
};

#endif // MENUCONTROLLER_H
//QObject
