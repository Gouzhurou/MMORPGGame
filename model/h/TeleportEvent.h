#ifndef TELEPORTEVENT_H_INCLUDED
#define TELEPORTEVENT_H_INCLUDED

#include "GameEvent.h"

class TeleportEvent: public GameEvent {
private:
    Controller* action;
public:
    TeleportEvent(Controller&);
    void event();    
};

#endif