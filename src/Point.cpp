#include <iostream>
#include <cassert>
#include "Point.h"

Point::Point(int x, int y) 
: x{ x }, y { y } {};

bool Point::operator==(const Point& p) const
{
    return x == p.x && y == p.y;
}

bool Point::operator!=(const Point& p) const
{
    return x != p.x || y != p.y;
}

Point Point::getAdjacentPoint(const Direction& d) const
{
    switch(d.getType())
    {
        case Direction::up: return Point { x, y - 1 };
        case Direction::left: return Point { x - 1, y };
        case Direction::down: return Point { x, y + 1 };
        case Direction::right: return Point { x + 1, y };
        default: break;
    }

    assert(0 && "Unsupported direction was passed!");
    return *this;
}
