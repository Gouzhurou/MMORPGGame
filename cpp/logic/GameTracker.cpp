#include "../../h/logic/GameTracker.h"
#include <iostream>

GameTracker::GameTracker(Controller& controller, FieldPrinter& fieldPrinter, std::map<char, Command> commands) : 
    controller(controller), fieldPrinter(fieldPrinter) {
        this->commands = commands;
}

bool GameTracker::tracking(Point& prevPoint) {
    Point* curPoint = controller.getPoint();
    if (prevPoint != *curPoint) {
            controller.getHero()->printHp();
            prevPoint = *curPoint;
            fieldPrinter.print(prevPoint, controller.getHero()->getVisionRadius());
        }

    if (this->controller.getField()->getEnd() == *curPoint) {
        std::cout << VICTORY_MASSAGE << std::endl;
        return false;
    }

    if (this->controller.getHero()->getHp() == 0) {
        std::cout << DIE_MASSAGE << std::endl;
        return false;
    }

    return true;
}

bool GameTracker::newGame(InputAction& inputAction) {
    std::cout << "Do you wanna start new game?" << std::endl;
    std::cout << "r - restart, something - not restart" << std::endl;
    Command command = inputAction.input(commands);
    switch(command) {
        case Command::RESTART:
            return true;
    }
    return false;
}