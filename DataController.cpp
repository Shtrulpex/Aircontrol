#include "DataController.h"

QStringList DataController::getAirports(const QString &text)
{
    AirportQuery p;
    p.name.eng = text.toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << AIRPORT;
    sock << p;
    std::vector<Airport> airs;
    sock >> airs;
    sock.close();

    QStringList names;
    for(auto i: airs)
        names.append(QString::fromStdString(i.name.eng + "/" + i.city.rus));

    return names;
}

QStringList DataController::getPlanes(const QString &text)
{
    PlaneQuery p;
    p.name.eng = text.toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << PLANE;
    sock << p;
    std::vector<Plane> planes;
    sock >> planes;
    sock.close();

    QStringList names;
    for(auto i: planes)
        names.append(QString::fromStdString(i.name.eng));

    return names;
}

void DataController::setPlane(const QString &text)
{
    laneQuery p;
    p.name.eng = text.toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << PLANE;
    sock << p;
    std::vector<Plane> planes;
    sock >> planes;
    sock.close();
    if(!planes.empty())
        plane = planes[planes.size()-1];
}

void DataController::setDestination(const QString &text)
{

}

void DataController::setStart(const QString &text)
{

}
