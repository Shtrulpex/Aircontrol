#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H

#include "./server/socket.h"
#include "./server/data_struct.h"
#include <vector>
#include <qstring.h>
#include <qstringlist.h>


class DataController
{
    Airport from, to;
    Plane plane;
    const QString ip = "127.0.0.1";
    const int port = 5433;

public:
    QStringList getAirports(const QString& text);
    QStringList getPlanes(const QString& text);
    Airport getDestination() {return to;}
    Airport getStart() {return from;}
    Plane getTransport() {return plane;}
    void setPlane(const QString& text);
    void setDestination(const QString& text);
};

#endif // DATACONTROLLER_H

