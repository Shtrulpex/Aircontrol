/*
в мейн виндоу
коннект (имя объекта (книпки в юи), действие, указатель на кого, какая функция)
*/
#include "MenuController.h"

MenuController::MenuController(MainWindow* parent = nullptr)
    : window{parent} {}

MenuController::departureCity_itemClicked(QListWidgetItem *item)
{

}

MenuController::departureCity_textChanged(const QString &text)
{
    QStringList names;
    names.append("smth");
    names.append("smth2");

}
