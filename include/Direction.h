#ifndef DIRECTION_H
#define DIRECTION_H 

#include <iostream>

class Direction
{
public:
    enum Type
    {
        up,
        down,
        left,
        right,
        maxDirection
    };

    Direction(Type type)
    : m_type { type } {}

    static Direction getRandomDirection();

    friend std::ostream& operator<<(std::ostream& out, const Direction& d);

    Direction operator-() const;

    Type getType() const;

private:
    Type m_type {};
};

#endif
