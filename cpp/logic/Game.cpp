#include "../../h/logic/Game.h"
#include <iostream>
#include <vector>

Game::Game(Controller& controller, std::map<char, Command> commands) : 
    controller(controller){
    this->gameState = GameState::NOT_STARTED;
    this->commands = commands;
}

bool Game::startGame() {
    controller.getHero()->reload();
    FieldGenerator generator;
    controller.setField(generator.generateRandom(controller, 20, 7)); 
    this->gameState = GameState::PLAYING;
    std::cout << "Game is started\n";
    return processGame();
}

bool Game::endGame() {
    this->gameState = GameState::COMPLETED;
    std::cout << "Game is completed\n";
    return false;
}

bool Game::processGame() {
    KeyboardInput inputAction;
    ConsoleFieldPrinter fieldPrinter(controller.getField());
    GameTracker gameTracker(controller, fieldPrinter, commands);

    Command command;
    bool continueFlag = true;
    Point prevPoint = *(this->controller.getPoint());
    controller.getHero()->printHp();
    fieldPrinter.print(prevPoint, controller.getHero()->getVisionRadius());

    while (continueFlag) {
        command = inputAction.input(commands);

        Direction direction;
        switch (command) {
            case Command::UP:
                direction = Direction::UP;
                break;
            case Command::LEFT:
                direction = Direction::LEFT;
                break;
            case Command::DOWN:
                direction = Direction::DOWN;
                break;
            case Command::RIGHT:
                direction = Direction::RIGHT;
                break;
            case Command::INFO:
                this->controller.getHero()->printInfo();
                continue;
            case Command::RESTART:
                return true;
            case Command::EXIT:
                continueFlag = false;
                continue;
            default:
                continue;
        }

        this->controller.move(direction);

        continueFlag = gameTracker.tracking(prevPoint);
    }

    if(gameTracker.newGame(inputAction)) {
        return true;
    }

    return endGame();
}