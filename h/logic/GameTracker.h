#include "Controller.h"
#include "../util/FieldPrinter.h"
#include "../util/impl/KeyboardInput.h"
#define VICTORY_MASSAGE "VICTORY!"
#define DIE_MASSAGE "You DIED!"

#ifndef GAMETRACKER_H_INCLUDED
#define GAMETRACKER_H_INCLUDED

class GameTracker {
private:
    Controller& controller;
    FieldPrinter& fieldPrinter;
    std::map<char, Command> commands;

public:
    GameTracker(Controller&, FieldPrinter&, std::map<char, Command>);
    bool tracking(Point&);
    bool newGame(InputAction&);
};

#endif
