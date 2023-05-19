#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include "GISMapWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class WindowController : public QMainWindow
{
    Q_OBJECT

public:
    WindowController(GISMapWidget* map, QWidget *parent = nullptr);
    ~WindowController();

private slots:
    void on_lineEdit_departureCity_textChanged(const QString &arg1);
    void on_listWidget_departureCity_itemClicked(QListWidgetItem *item);

signals:
    void ItemClicked(QgsRectangle rect);
private: 
    QStringList ServerCommunication(const QString &text);
    Ui::MainWindow *ui;

    //void lineEdit_plane_changed(const QString &arg1);

};
#endif // MAINWINDOW_H
