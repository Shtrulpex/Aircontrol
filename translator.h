#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <utility>
#include <vector>
#include <math.h>

constexpr double EARTH_RADIUS = 6456863;
constexpr double DEGREES_TO_RADIANS = M_PI / 180;
constexpr double RADIANS_TO_DEGREES = 180 / M_PI;

struct EarthEllipsoid
{
    EarthEllipsoid(double fVal = 1 / 298.257223563, double aVal = 6378137.0)
        : f(fVal), a(aVal)
    {
        b = a - a * f;
        e = sqrt(a*a - b*b) / a;
    }

    double f; // сжатие
    double a; // большая полуось
    double b; // малая полуось
    double e; // эксцентриситет
};

inline std::pair<double, double> LatLongToMerc(double latitude, double longitude)
{
    latitude = latitude * DEGREES_TO_RADIANS;
    longitude = longitude * DEGREES_TO_RADIANS;

    EarthEllipsoid ellipsoid;
    double a = ellipsoid.a;
    double e = ellipsoid.e;

    double x = a * longitude;
    double y= a * log(tan(M_PI/4 + latitude/2) * pow( (1-e*sin(latitude))/(1 + e*sin(latitude)), e/2 ));

    return std::make_pair(x, y);
}

#endif // TRANSLATOR_H
