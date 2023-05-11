#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>

#include "./ui_mainwindow.h"
#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

#include "GISMapWidget.h"

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
    void on_lineEdit_departureCity_textChanged(const QString &arg1);
    void on_listWidget_departureCity_itemClicked(QListWidgetItem *item);

private:
    GISMapWidget* map = nullptr;
    Ui::MainWindow *ui;

    QgsVectorLayer* PointsLayer = new QgsVectorLayer("Point", "Points", "memory");


    void addControlPoint(const QgsPointXY &point);
};
#endif // MAINWINDOW_H
