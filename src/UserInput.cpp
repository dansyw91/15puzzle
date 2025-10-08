#include <iostream>
#include <cassert>
#include <limits>
#include "UserInput.h"


bool UserInput::isValidCommand(char ch)
{
    return ch == 'w'
        || ch == 'a'
        || ch == 's'
        || ch == 'd'
        || ch == 'q';
}

void UserInput::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char UserInput::getCharacter()
{
    char operation {};
    std::cin >> operation;
    ignoreLine();
    return operation;
}

char UserInput::getCommandFromUser()
{
    char command {};
    while (!isValidCommand(command))
        command = getCharacter();
    
    return command;
}  

Direction UserInput::charToDirection(char ch)
{
    switch (ch)
    {
        case 'w': return Direction{ Direction::up };
        case 'a': return Direction{ Direction::left };
        case 's': return Direction{ Direction::down };
        case 'd': return Direction{ Direction::right };
        default: break;
    }

    assert(0 && "Unsupported direction was passed!");
    return Direction{ Direction::up };
}
