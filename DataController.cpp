#include "DataController.h"

QStringList DataController::getAirports(const QString &text)
{
    AirportQuery p;
    p.name.rus = text.toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << AIRPORT;
    sock << p;
    std::vector<Airport> airs;
    sock >> airs;
    sock.close();

    QStringList names;
    for(auto i: airs)
        names.append(QString::fromStdString(i.name.rus + "/" + i.city.rus));

    return names;
}

QStringList DataController::getPlanes(const QString &text)
{
    PlaneQuery p;
    p.name.rus = text.toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << PLANE;
    sock << p;
    std::vector<Plane> planes;
    sock >> planes;
    sock.close();

    QStringList names;
    for(auto i: planes)
        names.append(QString::fromStdString(i.name.rus));

    return names;
}

void DataController::setPlane(const QString &text)
{
    PlaneQuery p;
    p.name.rus = text.toStdString();

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
    AirportQuery a;
    a.name.rus = text.split("/")[0].toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << AIRPORT;
    sock << a;
    std::vector<Airport> airs;
    sock >> airs;
    sock.close();
    if(!airs.empty())
        to = airs[airs.size()-1];
}


void DataController::setStart(const QString &text)
{
    AirportQuery a;
    a.name.rus = text.split("/")[0].toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << AIRPORT;
    sock << a;
    std::vector<Airport> airs;
    sock >> airs;
    sock.close();
    if(!airs.empty())
        from = airs[airs.size()-1];
}


QStringList DataController::getDestAirports(const QString &text)
{
    AirportQuery a;
    a.name.rus = text.toStdString();

    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << REACHABLE;
    sock << a << from << plane;
    std::vector<Airport> airs;
    sock >> airs;
    sock.close();

    QStringList names;
    for(auto i: airs)
        names.append(QString::fromStdString(i.name.rus + "/" + i.city.rus));

    return names;
}

bool DataController::isEmpty()
{
    return from.name.rus.empty() || plane.name.rus.empty();
}

std::vector<Point> DataController::getPath()
{
    Socket sock;
    sock.connect(ip.toStdString(), port);
    sock << PATH_2D;
    sock << from << to;
    std::vector<Point> path;
    sock >> path;

    return path;
}
