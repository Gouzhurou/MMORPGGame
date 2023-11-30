#include "Direction.h"
#include "Character.h"
#include "Field.h"
#include "Point.h"

#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

class Action {
private:
    Character* hero;
    Point point;
    Field* field;
public:
    Action(Character*, Field* field = nullptr);
    void move(Direction);
    Character* getHero();
    Point* getPoint();
    Field* getField();
    void setField(Field*);
    void setPoints(unsigned, unsigned, unsigned, unsigned);
};

#endif