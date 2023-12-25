#include "Game.h"
#include "KeyboardInput.h"
#include "FieldGenerator.h"
#include <iostream>
#include <vector>

Game::Game(Controller& controller) : controller(controller) {
    this->gameState = GameState::NOT_STARTED;
}

bool Game::startGame() {
    controller.getHero()->reload();
    FieldGenerator generator;
    controller.setField(generator.generateRandom(controller)); 
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
    Command command;
    bool flag = true;
    Point prevPoint = *(this->controller.getPoint());
    this->controller.getHero()->printInfo();
    this->controller.getField()->print(prevPoint);

    FileReader fileReader = FileReader();
    std::map<char, Command> commands = fileReader.getCommands();
    KeyboardInput inputAction;

    while (flag) {
        if (prevPoint != *(this->controller.getPoint())) {
            this->controller.getHero()->printInfo();
            prevPoint = *(this->controller.getPoint());
            this->controller.getField()->print(prevPoint);
        }

        command = inputAction.input(commands);
        Direction direction;
        std::cout << static_cast<int>(command) << std::endl;
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
            case Command::RESTART:
                return true;
            case Command::EXIT:
                flag = false;
            default:
                continue;
        }

        this->controller.move(direction);

        Point curPoint = *(this->controller.getPoint());
        if (this->controller.getField()->getEnd() == curPoint) {
            std::cout << "VICTORY!" << std::endl;
            break;
        }

        if (this->controller.getHero()->getHp() == 0) {
            std::cout << "You DIED!" << std::endl;
            break;
        }        
    }

    return endGame();
}