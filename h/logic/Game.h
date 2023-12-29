#include "Controller.h"
#include "../model/Character.h"
#include "../model/Field.h"
#include "enum/GameState.h"
#include "../util/FileReader.h"
#include "../util/InputAction.h"
#include "../util/impl/KeyboardInput.h"
#include "../util/FieldGenerator.h"
#include "../util/impl/ConsoleFieldPrinter.h"
#include "GameTracker.h"

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game {
private:
    Controller& controller;
    GameState gameState;
    std::map<char, Command> commands;
    bool processGame();
    
public:
    Game(Controller&, std::map<char, Command>);
    bool startGame();
    bool endGame();
};
#endif