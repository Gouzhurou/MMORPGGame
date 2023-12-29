#ifndef TOTEMEVENT_H_INCLUDED
#define TOTEMEVENT_H_INCLUDED

#include "../GameEvent.h"

class TotemEvent: public GameEvent {
private:
    Controller* action;
public:
    TotemEvent(Controller&);
    virtual void event();    
}; 

#endif