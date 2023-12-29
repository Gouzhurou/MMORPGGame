#include "enum/Direction.h"
#include "../model/Character.h"
#include "../model/Field.h"
#include "../model/Point.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

class Controller {
private:
    Character* hero;
    Point point;
    Field* field;
public:
    Controller(Character*, Field* field = nullptr);
    void move(Direction);
    Character* getHero();
    Point* getPoint();
    Field* getField();
    void setField(Field*);
    void setPoints(unsigned, unsigned, unsigned, unsigned);
};

#endif