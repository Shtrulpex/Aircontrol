#include "MapController.h"

MapController::MapController()
{
    map = new GISMapWidget();
    map->OpenMap(PointsLayer);

    QgsCoordinateReferenceSystem crs("EPSG:4326");
    map->setDestinationCrs(crs);

    //std::pair<double, double> b = LatLongToMerc(50, 50);
    //this->addControlPoint(QgsPointXY{b.first, b.second});
    this->addControlPoint(QgsPointXY{180,80}); //180,80
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
