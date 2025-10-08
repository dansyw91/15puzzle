#ifndef USERINPUT_H
#define USERINPUT_H

#include "Direction.h"

namespace UserInput
{
    bool isValidCommand(char ch);
    void ignoreLine();
    char getCharacter();
    char getCommandFromUser();
    Direction charToDirection(char ch);
}

#endif
