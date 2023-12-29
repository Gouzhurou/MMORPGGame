#ifndef CONSOLEFIELDPRINTER_H_INCLUDED
#define CONSOLEFIELDPRINTER_H_INCLUDED

#include "../../util/FieldPrinter.h"
#include "../../model/Point.h"
#include "../../event/impl/BombEvent.h"
#include "../../event/impl/TotemEvent.h"
#include "../../event/impl/TeleportEvent.h"
#define BOMB_SYMBOL 'x'
#define TOTEM_SYMBOL '*'
#define TELEPORT_SYMBOL 'o'
#define HERO_SYMBOL 'H'
#define BORDER_SYMBOL '#'
#define OTHER_SYMBOL ' '

class ConsoleFieldPrinter: public FieldPrinter {
private:
    Field* field;
    void printEvent(GameEvent*);
    void printCell(unsigned, unsigned);

public:
    ConsoleFieldPrinter(Field*);
    virtual void print(Point&, unsigned); 
}; 

#endif