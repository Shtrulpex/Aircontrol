#include "MainWindow.h"
#include "./ui_mainwindow.h"

#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

#include <qgsrectangle.h> //for zoom
#include <random>
#include "server/socket.h"
#include "server/data_struct.h"
#include <iostream>
#include <vector>
#include "DataController.h"

MainWindow::MainWindow(GISMapWidget* map, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(map);

    //connect(ui->lineEdit_plane, &QAction::changed, this, &WindowController::lineEdit_plane_changed);
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_lineEdit_departureCity_textChanged(const QString &arg1)
{

    QStringList names = dc.getAirports(arg1);
    ui->listWidget_departureCity->clear();
    ui->listWidget_departureCity->addItems(names);
}

void MainWindow::on_lineEdit_plane_textChanged(const QString &arg1)
{

    QStringList names = dc.getPlanes(arg1);
    ui->listWidget_plane->clear();
    ui->listWidget_plane->addItems(names);

}

void MainWindow::on_lineEdit_arrivalCity_textChanged(const QString &arg1)
{
    QStringList cities = dc.getAirports(arg1);
    ui->listWidget_departureCity->clear();
    ui->listWidget_arrivalCity->addItems(cities);
}

void MainWindow::on_listWidget_departureCity_itemClicked(QListWidgetItem *item)
{
    dc.setStart(item->text());
    //std::cout << item->text().toStdString() << "^(((((((((((((((((((((((((((((((" << std::endl;
    Airport start = dc.getStart();
    // generating random coordinates
    /*std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-50, 50); // define the range

    QgsRectangle rect(distr(gen), distr(gen), distr(gen), distr(gen));

*/  //emit ItemClicked(rect);

    emit DrawPoint(QgsPoint{start.loc.latitude, start.loc.longitude});
    ui->lineEdit_departureCity->setText(item->text());
}

void MainWindow::on_listWidget_plane_itemClicked(QListWidgetItem *item)
{
    dc.setPlane(item->text());
    ui->lineEdit_plane->setText(item->text());
}

void MainWindow::on_listWidget_arrivalCity_itemClicked(QListWidgetItem *item)
{
    dc.setDestination(item->text());
    Airport start = dc.getStart();
    QgsPoint point{start.loc.latitude,start.loc.longitude};
    emit DrawPoint(point);
    ui->lineEdit_arrivalCity->setText(item->text());
}


void MainWindow::on_MakeRootButton_clicked()
{
    //dc.getTransport();
    std::vector<Point> root; // FIXME take root from query
    emit DrawRoot(root);
}
