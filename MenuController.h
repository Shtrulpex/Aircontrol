#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QAction>
#include <QMenuBar>
#include <QToolBar>

#include "mainwindow.h"

class MenuController:public QObject {
    Q_OBJECT
private:
    MenuController(MainWindow* parent = nullptr);
    MainWindow* window;
public:
    void departureCity_textChanged(const QString &text);
    void departureCity_itemClicked(QListWidgetItem *item);
signals:


};

#endif // MENUCONTROLLER_H
//QObject
