#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

#include <qgsrectangle.h> //for zoom
#include <random>
#include "server/socket.h"
#include "server/data_struct.h"
#include <iostream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ////////////////////////
    Socket sock;
    PlaneQuery p;
    sock.connect("127.0.0.1", 5433);
    sock << PLANE;
    sock << p;
    std::cout << "connected, sent" << std::endl;
    std::vector<Plane> airs;
    sock >> airs;
    std::cout << "recieved" << std::endl;
    std::cout << airs.size() << std::endl;
    sock.close();
    ////////////////////////
    ui->setupUi(this);
    map = new GISMapWidget(this);
    this->setCentralWidget(map);
    map->OpenMap(PointsLayer);

    this->addControlPoint(QgsPointXY{-5.755119, 50.057426});
}

MainWindow::~MainWindow()
{
    delete ui;
    delete map;
    delete PointsLayer;
}

void MainWindow::on_lineEdit_departureCity_textChanged(const QString &arg1)
{
    ui->listWidget_departureCity->clear();

    QStringList names;
    names.append("smth");
    names.append("smth2");
    ui->listWidget_departureCity->addItems(names);

    ui->listWidget_departureCity->addItem(arg1);
}

void MainWindow::on_listWidget_departureCity_itemClicked(QListWidgetItem *item)
{
    //Меняем цвет, хотя нафиг надо
    if(item->backgroundColor() == Qt::blue)
        item->setBackgroundColor(Qt::white);
    else
        item->setBackgroundColor(Qt::blue);

    //меняем сам текст
    ui->listWidget_departureCity->addItem("Ты кликнул на что-то");

    // generating random coordinates
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-50, 50); // define the range

    QgsRectangle rect(distr(gen), distr(gen), distr(gen), distr(gen));
    map->update();
    map->setExtent(rect);
}

void MainWindow::addControlPoint(const QgsPointXY &point)
{
        PointsLayer->startEditing();

        QgsFeature feat;
        feat.setFields(PointsLayer->fields(), true);
        //feat.setAttribute("fid", twoPoints.size() - 1);
        feat.setGeometry(QgsGeometry::fromPointXY(point));

        feat.setGeometry(QgsGeometry::fromPolylineXY({point, QgsPointXY{0,0}, QgsPointXY{50,0}}));
        PointsLayer->addFeature(feat);
        PointsLayer->commitChanges();
}
