#ifndef BOMBEVENT_H_INCLUDED
#define BOMBEVENT_H_INCLUDED

#include "GameEvent.h"

class BombEvent: public GameEvent {
private:
    Controller* action;
public:
    BombEvent(Controller&);
    void event();    
};

#endif