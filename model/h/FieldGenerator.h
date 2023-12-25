#include "Field.h"
#include "Controller.h"
#define BOMB_FREQUENCY 9
#define TOTEM_FREQUENCY 36
#define TELEPORT_FREQUENCY 25

#ifndef FIELDGENERATOR_H_INCLUDED
#define FIELDGENERATOR_H_INCLUDED

class FieldGenerator {
public:
    Field* generateRandom(Controller&, unsigned, unsigned);
    Field* generateRandom(Controller&);
};

#endif