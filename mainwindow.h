#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>

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

private:
    GISMapWidget* map = nullptr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
