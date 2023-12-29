#include "../logic/Controller.h"
#include "../event/impl/BombEvent.h"
#include "../event/impl/TotemEvent.h"
#include "../event/impl/TeleportEvent.h"

#define BOMB_FREQUENCY 9
#define TOTEM_FREQUENCY 36
#define TELEPORT_FREQUENCY 25

#ifndef FIELDGENERATOR_H_INCLUDED
#define FIELDGENERATOR_H_INCLUDED

class FieldGenerator {
public:
    Field* generateRandom(Controller&, unsigned x = FIELD_SIZE, unsigned y = FIELD_SIZE);
};

#endif