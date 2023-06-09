#include "GISMapWidget.h"

GISMapWidget::GISMapWidget(QWidget* parent)
             : QgsMapCanvas(parent)
{
    enableAntiAliasing(true);
    setCanvasColor(QColor(204, 229, 255));
    setVisible(true);
    setMapSettingsFlags(mapSettings().flags() | QgsMapSettings::RenderPreviewJob);
    setParallelRenderingEnabled(true);
    setCachingEnabled(true);
    setPreviewJobsEnabled(true);
    setMapUpdateInterval(500);
    setMinimumSize(600,400);
}

GISMapWidget::~GISMapWidget()
{
    delete earthLayer;
}

void GISMapWidget::OpenMap(QgsVectorLayer* controlPointLayer1, QgsVectorLayer* controlPointLayer2, QgsVectorLayer* RootLayer)
{
    setLayers({controlPointLayer2, controlPointLayer1, RootLayer, earthLayer});
    setExtent(earthLayer->extent());
    QgsCoordinateReferenceSystem crs("EPSG:4326");
    setDestinationCrs(crs);
    refresh();

}
