#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dockWidget_allowedAreasChanged(const Qt::DockWidgetAreas &allowedAreas)
{

}

void MainWindow::on_dockWidget_windowIconChanged(const QIcon &icon)
{

}
