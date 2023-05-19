#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include "GISMapWidget.h"
#include "./server/data_struct.h"
#include "DataController.h"

#include "DataController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(GISMapWidget* map, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_departureCity_textChanged(const QString &arg1);
    void on_listWidget_departureCity_itemClicked(QListWidgetItem *item);

    void on_lineEdit_plane_textChanged(const QString &arg1);

    void on_lineEdit_arrivalCity_textChanged(const QString &arg1);

    void on_listWidget_plane_itemClicked(QListWidgetItem *item);

    void on_listWidget_arrivalCity_itemClicked(QListWidgetItem *item);

    void on_MakeRootButton_clicked();

signals:
    void ItemClicked(QgsRectangle rect);
    void DrawPoint(const QgsPointXY &point);
    void DrawRoot(std::vector<Point>& root);

private: 
    QStringList ServerCommunication(const QString &text);
    Ui::MainWindow *ui;
    DataController dc;


    //void lineEdit_plane_changed(const QString &arg1);

};
#endif // MAINWINDOW_H
