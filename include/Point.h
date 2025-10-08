#ifndef POINT_H
#define POINT_H

#include "Direction.h"

struct Point
{
    Point(int x, int y);

    int x {};
    int y {};

    bool operator==(const Point& p) const;
    bool operator!=(const Point& p) const;

    Point getAdjacentPoint(const Direction& d) const;
};

#endif
