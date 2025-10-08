#ifndef BOARD_H
#define BOARD_H

#include <utility>

#include "Tile.h"
#include "Point.h"
#include "Direction.h"

constexpr int g_consoleLines { 25 };

class Board
{
public:
    Board() = default;

    friend std::ostream& operator<<(std::ostream& out, Board& b);

    bool operator==(Board& b);

    static bool isValidPoint(Point& p);

    Point findEmptyPoint() const;

    void swapPoints(Point& p1, Point& p2);

    bool moveTile(const Direction& d);

    void randomize(Board& b);

    bool playerWon();

private:
    static constexpr int s_size { 4 };
    Tile m_tiles[s_size][s_size]{
        Tile { 1 }, Tile { 2 }, Tile { 3 }, Tile { 4 },
        Tile { 5 }, Tile { 6 }, Tile { 7 }, Tile { 8 },
        Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
        Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 }
    };
};

#endif
