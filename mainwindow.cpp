#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ShowMap();
}

void MainWindow::ShowMap()
{
    map = new QgsMapCanvas(this);
    map->setLayers({earthLayer, oceanLayer});
    map->setExtent(earthLayer->extent());
    QgsCoordinateReferenceSystem crs("EPSG:4326");
    map->setDestinationCrs(crs);
    map->refresh();
    this->setCentralWidget(map);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete map;
    delete earthLayer;
}

void MainWindow::on_dockWidget_allowedAreasChanged(const Qt::DockWidgetAreas &allowedAreas)
{

}

void MainWindow::on_dockWidget_windowIconChanged(const QIcon &icon)
{

}
