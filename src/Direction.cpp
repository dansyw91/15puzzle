#include <cassert>
#include <iostream>

#include "Direction.h"
#include "Random.h"

Direction::Type Direction::getType() const { return m_type; }

Direction Direction::getRandomDirection()
{
    Direction::Type random { static_cast<Direction::Type>(Random::get(0, Direction::maxDirection - 1)) };
    return Direction{ random };
}


std::ostream& operator<<(std::ostream& out, const Direction& d)
{
    switch(d.getType())
    {
        case Direction::up: return (out << "up");
        case Direction::left: return (out << "left");
        case Direction::right: return (out << "right");
        case Direction::down: return (out << "down");
        default: break;
    }
    assert(0 && "Unsupported direction weas passed!");
    return (out << "unknown direction");
}

Direction Direction::operator-() const
{
    switch(m_type)
    {
        case up: return Direction { down };
        case left: return Direction { right };
        case right: return Direction { left };
        case down: return Direction { up };
        default: break;
    }
    assert(0 && "Unsupported direction was passed!");
    return Direction { up };
}
