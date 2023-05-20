#include "MapController.h"

MapController::MapController()
{
    map = new GISMapWidget();
    map->OpenMap(PointsLayer, RootLayer);

    QgsCoordinateReferenceSystem crs("EPSG:4326");
    map->setDestinationCrs(crs);
}

MapController::~MapController()
{
    delete map;
    delete PointsLayer;
    delete RootLayer;
}

void MapController::addControlPoint(const QgsPointXY &point)
{
        PointsLayer->startEditing();

        QgsFeature feat;
        feat.setFields(PointsLayer->fields(), true);
        feat.setGeometry(QgsGeometry::fromPointXY(point));
        PointsLayer->addFeature(feat);
        PointsLayer->commitChanges();
}

GISMapWidget* MapController::GetMap() const
{
    return map;
}
 void MapController::ScaleToRect(QgsRectangle rect)
 {
     map->update();
     map->setExtent(rect);
 }

 void MapController::DrawPoint(const QgsPointXY &point)
 {
    addControlPoint(point);
 }

 void MapController::ClearPoint(const QgsPoint &point) //deletes all points
 {
    PointsLayer->startEditing();

    QgsFeature f;
    QgsFeatureIterator iter = PointsLayer->getFeatures();
    //PointsLayer->deleteFeature(f[0]);
    while(iter.nextFeature(f))
        PointsLayer->deleteFeature(f.id());

    PointsLayer->commitChanges();
 }

 void MapController::MapDrawRoot(std::vector<Point> &root)
 {
     RootLayer->startEditing();
     QgsPolylineXY polyline;
     for(auto i:root)
         polyline.append(QgsPointXY{i.longitude, i.latitude});

     QgsFeature feat;
     feat.setFields(RootLayer->fields(), true);

     feat.setGeometry(QgsGeometry::fromPolylineXY(polyline));
     RootLayer->addFeature(feat);
     RootLayer->commitChanges();
 }
