#ifndef KEYBOARDINPUT_H_INCLUDED
#define KEYBOARDINPUT_H_INCLUDED

#include "../InputAction.h"

class KeyboardInput: public InputAction {
public:
    virtual Command input(std::map<char, Command>);   
}; 

#endif