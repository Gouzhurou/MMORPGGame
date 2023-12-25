#include "Controller.h"
#include "Character.h"
#include "Field.h"
#include "GameState.h"
#include "FileReader.h"
#include "InputAction.h"

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