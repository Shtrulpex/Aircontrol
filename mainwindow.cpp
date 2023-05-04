#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <qgsmapcanvas.h>
#include <qgsmapsettings.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new GISMapWidget(this);
    this->setCentralWidget(map);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete map;
}
