#include "Controller.h"
#include "Character.h"
#include "Field.h"
#include "GameState.h"
#include "FileReader.h"

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game {
private:
    Controller& controller;
    GameState gameState;
    bool processGame();
    
public:
    Game(Controller&);
    bool startGame();
    bool endGame();
};
#endif