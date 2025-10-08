#include <iostream>
#include <cassert>

#include "Board.h"

std::ostream& operator<<(std::ostream& out, Board& b)
{
    for (int i { 0 }; i < g_consoleLines; ++i)
        std::cout << '\n';
    
    for (int y { 0 }; y < b.s_size; ++y)
    {
        for (int x { 0 }; x < b.s_size; ++x)
            out << b.m_tiles[y][x];
        out << '\n';
    }

    return out;
}

bool Board::operator==(Board& b)
{
    for (int y { 0 }; y < b.s_size; ++y)
        for (int x { 0 }; x < b.s_size; ++x)
        {
            if (m_tiles[y][x].getNum() != b.m_tiles[y][x].getNum())
                return false;
        }
    return true;
}

bool Board::isValidPoint(Point& p)
{
    return p.x >= 0 && p.x < s_size && p.y >= 0 && p.y < s_size; 
}

Point Board::findEmptyPoint() const
{
    for (int y { 0 }; y < s_size; ++y)
        for (int x { 0 }; x < s_size; ++x)
        {
            if (m_tiles[y][x].isEmpty())
                return Point { x, y };
        }
    assert(0 && "No empty tile found!");
    return Point { -1, 1 };
}

void Board::swapPoints(Point& p1, Point& p2)
{
    std::swap(m_tiles[p1.y][p1.x], m_tiles[p2.y][p2.x]);
}

bool Board::moveTile(Direction& d)
{
        Point empty { findEmptyPoint() };
        Point adj { empty.getAdjacentPoint(-d) };

        if (!isValidPoint(adj))
            return false;

        swapPoints(adj, empty);
        return true;
}

void Board::randomize(Board& b)
{
    for (int i { 0 }; i < 1000;)
    {
        if (moveTile(Direction::getRandomDirection()))
            ++i;
    }
}

bool Board::playerWon()
{
    static Board s_solved {};
    return s_solved == *this;
}
