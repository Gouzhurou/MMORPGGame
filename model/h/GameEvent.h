#ifndef GAMEEVENT_H_INCLUDED
#define GAMEEVENT_H_INCLUDED

#include "Controller.h"

class GameEvent {
public:
    virtual void event() = 0; 
    virtual void print() = 0;   
};

#endif