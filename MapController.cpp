#include "MapController.h"

MapController::MapController()
{
    map = new GISMapWidget();
    map->OpenMap(PointsLayer);

    QgsCoordinateReferenceSystem crs("EPSG:4326");
    map->setDestinationCrs(crs);
}

MapController::~MapController()
{
    delete map;
    delete PointsLayer;
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

     QgsPoint point{10.,10.};
     QgsFeature feat;
     feat.setFields(RootLayer->fields(), true);
     //feat.setAttribute("fid", twoPoints.size() - 1);
     //feat.setGeometry(QgsGeometry::fromPointXY(point));

     feat.setGeometry(QgsGeometry::fromPolyline({point, QgsPoint{20,20}}));
     RootLayer->addFeature(feat);
     RootLayer->commitChanges();
 }
