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
    DataController dc;
    QStringList names = dc.getPlanes(arg1);
    ui->listWidget_departureCity->clear();
    ui->listWidget_departureCity->addItems(names);
}

void MainWindow::on_lineEdit_plane_textChanged(const QString &arg1)
{
    ui->listWidget_plane->addItem(arg1);
}

void MainWindow::on_lineEdit_arrivalCity_textChanged(const QString &arg1)
{
    ui->listWidget_arrivalCity->addItem(arg1);
}

void MainWindow::on_listWidget_plane_itemClicked(QListWidgetItem *item)
{

}

void MainWindow::on_listWidget_arrivalCity_itemClicked(QListWidgetItem *item)
{

    const QgsPoint point{0.,0.};
    emit DrawPoint(point);
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
    emit ItemClicked(rect);
    emit DrawPoint(QgsPoint{20., 20.});
}
