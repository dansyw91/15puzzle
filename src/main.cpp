#include <iostream>
#include <iomanip>
#include <string>

#include "Tile.h"
#include "Board.h"
#include "UserInput.h"
#include "Direction.h"
#include "Point.h"

int main()
{
    Board board {};
    board.randomize(board);
    std::cout << board;

    while (!board.playerWon())
    {
        char command { UserInput::getCommandFromUser() };
        
        if (command == 'q')
        {
            std::cout << "\nBye!\n";
            return 0;
        }

        Direction direction{ UserInput::charToDirection(command) };

        bool userMoved { board.moveTile(direction) };
        if (userMoved)
            std::cout << board;
    }

    std::cout << "\n\nYou won!\n\n";
    return 0;
    }
