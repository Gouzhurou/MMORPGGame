#include "enum/Command.h"
#include <map>

#ifndef INPUTACTION_H_INCLUDED
#define INPUTACTION_H_INCLUDED

class InputAction {
public:
    virtual Command input(std::map<char, Command>) = 0;
};

#endif