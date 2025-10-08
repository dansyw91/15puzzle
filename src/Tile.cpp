#include <iostream>
#include <string>
#include "Tile.h"

Tile::Tile(int num)
    : m_num { num } {}

bool Tile::isEmpty() const
{
    return m_num == 0;
}

int Tile::getNum() const
{
    return m_num;
}

std::ostream& operator<<(std::ostream& out, Tile& t)
{
    if (t.isEmpty())
        out << "    ";
    else
    {
        std::string numStr { std::to_string(t.getNum()) };
        int padding { 4 - static_cast<int>(numStr.size()) };
        
        int left {};
        int right {};
        if (numStr.size() == 1)
        {
            left = 2;
            right = 1;
        }
        else
        {
            left = 1;
            right = 1;
        }

        out << std::string(left, ' ') << numStr << std::string(right, ' ');
    }
    return out;
}
