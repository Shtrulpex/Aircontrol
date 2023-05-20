#include "MapController.h"

MapController::MapController()
{
    map = new GISMapWidget();
    map->OpenMap(PointLayer1, RootLayer, PointLayer2);

    QgsCoordinateReferenceSystem crs("EPSG:4326");
    map->setDestinationCrs(crs);
}

MapController::~MapController()
{
    delete map;
    delete PointLayer1;
    delete PointLayer2;
    delete RootLayer;
}

void MapController::addControlPoint(const QgsPointXY &point, QgsVectorLayer* PointsLayer)
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

 void MapController::DrawPoint(const QgsPointXY &point, bool choose)
 {
    ClearPoint(point, choose);
    if(choose)
        addControlPoint(point, PointLayer1);
    else
        addControlPoint(point, PointLayer2);
 }

 void MapController::ClearPoint(const QgsPointXY &point, bool choose) //deletes all points
 {
    QgsVectorLayer* PointsLayer;
    if(choose)
        PointsLayer = PointLayer1;
    else
        PointsLayer = PointLayer2;
    PointsLayer->startEditing();

    QgsFeature f;
    QgsFeatureIterator iter = PointsLayer->getFeatures();
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
