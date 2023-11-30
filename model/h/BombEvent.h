#ifndef BOMBEVENT_H_INCLUDED
#define BOMBEVENT_H_INCLUDED

#include "GameEvent.h"

class BombEvent: public GameEvent {
private:
    Action* action;
public:
    BombEvent(Action&);
    void event();    
    void print();
};

#endif