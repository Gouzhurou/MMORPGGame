#include "GameEvent.h"

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

class GameEvent;
class Cell {
private:
    bool passability;
    GameEvent* event;
public:
    Cell(bool passability = true, GameEvent* event = nullptr);
    void setPassability(bool);
    bool getPassability();
    void print();
    GameEvent* getEvent();
    void setEvent(GameEvent*);
};

#endif