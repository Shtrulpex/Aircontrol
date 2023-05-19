#include "WindowController.h"
#include "./ui_mainwindow.h"

#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

#include <qgsrectangle.h> //for zoom
#include <random>
#include "server/socket.h"
#include "server/data_struct.h"
#include <iostream>
#include <vector>

WindowController::WindowController(GISMapWidget* map, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //map = new GISMapWidget(this);
    this->setCentralWidget(map);
    //map->OpenMap(PointsLayer);


    //QgsCoordinateReferenceSystem crs("EPSG:4326"); //EPSG:4326
    //map->setDestinationCrs(crs);

    //std::pair<double, double> b = LatLongToMerc(50, 50);
    //this->addControlPoint(QgsPointXY{b.first, b.second});
    //this->addControlPoint(QgsPointXY{180,80}); //180,80
    this->show();
}

WindowController::~WindowController()
{
    delete ui;
}

void WindowController::on_lineEdit_departureCity_textChanged(const QString &arg1)
{
    AirportQuery p;

    p.name.eng = arg1.toStdString();//ui->lineEdit_departureCity->text().toStdString();
    ui->listWidget_departureCity->clear();

    Socket sock;
    sock.connect("127.0.0.1", 5433);
    sock << AIRPORT;
    sock << p;
    std::vector<Airport> airs;
    sock >> airs;
    sock.close();

    QStringList names;
    for(auto i: airs)
    {
        names.append(QString::fromStdString(i.city.eng + " " + i.name.rus));
        std::cout << i.city.rus << " " << i.name.rus << std::endl;
    }

    std::cout << "///////////////////" << std::endl;

    ui->listWidget_departureCity->addItems(names);

    ui->listWidget_departureCity->addItem(arg1);
}

void WindowController::on_listWidget_departureCity_itemClicked(QListWidgetItem *item)
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
    emit ItemClicked(rect);
    //map->update();
    //map->setExtent(rect);
}
