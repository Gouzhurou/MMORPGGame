#ifndef TELEPORTEVENT_H_INCLUDED
#define TELEPORTEVENT_H_INCLUDED

#include "GameEvent.h"

class TeleportEvent: public GameEvent {
private:
    Action* action;
public:
    TeleportEvent(Action&);
    void event();    
    void print();
};

#endif