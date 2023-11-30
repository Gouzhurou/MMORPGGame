#ifndef NOTHINGEVENT_H_INCLUDED
#define NOTHINGEVENT_H_INCLUDED

#include "GameEvent.h"

class NothingEvent: public GameEvent {
public:
    void event(); 
    void print();   
}; 

#endif