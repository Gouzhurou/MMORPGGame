#ifndef TOTEMEVENT_H_INCLUDED
#define TOTEMEVENT_H_INCLUDED

#include "GameEvent.h"

class TotemEvent: public GameEvent {
private:
    Action* action;
public:
    TotemEvent(Action&);
    virtual void event();    
    void print();
}; 

#endif