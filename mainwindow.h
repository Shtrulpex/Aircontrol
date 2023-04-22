#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dockWidget_allowedAreasChanged(const Qt::DockWidgetAreas &allowedAreas);
    void on_dockWidget_windowIconChanged(const QIcon &icon);

private:
    void ShowMap();

    QgsMapCanvas* map = nullptr;
    QgsVectorLayer* earthLayer = new QgsVectorLayer("/home/sofia/4 semestr/SuperProject/"
                                                    "Related Projects/maps/"
                                                    "kx-world-land-areas-110-million-SHP/"
                                                    "world-land-areas-110-million.shp",
                                                    "earth", "ogr");
    QgsVectorLayer* oceanLayer = new QgsVectorLayer("/home/sofia/4 semestr/SuperProject/"
                                                    "Related Projects/maps/"
                                                    "kx-world-bathymetry-110-million-SHP/"
                                                    "world-bathymetry-110-million.shp",
                                                    "water", "ogr");


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
