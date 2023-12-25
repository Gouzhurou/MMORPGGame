#include "ConsoleFieldPrinter.h"
#include <iostream>

ConsoleFieldPrinter::ConsoleFieldPrinter(Field* field) {
    this->field = field;
}

void ConsoleFieldPrinter::print(Point& characterPoint, unsigned visionRadius) {
    int startVisionX = characterPoint.getX() - visionRadius;
    int endVisionX = characterPoint.getX() + visionRadius + 1;
    if (startVisionX < 0) startVisionX = 0;
    if (endVisionX > field->getWidth() - 1) endVisionX = field->getWidth();

    for (unsigned j = 0; j < field->getHeight(); j++) {
        for (unsigned i = startVisionX; i < endVisionX; i++) {
            if (i == characterPoint.getX() && j == characterPoint.getY()) {
                std::cout << HERO_SYMBOL;
            }
            else {
                printCell(i, j);
            }
            std::cout << OTHER_SYMBOL;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void ConsoleFieldPrinter::printCell(unsigned x, unsigned y) {
    Cell* curCell = field->getCell(x, y);
    if (curCell->getPassability()) {
        printEvent(curCell->getEvent());
    }
    else {
        std::cout << BORDER_SYMBOL;
    }
}

void ConsoleFieldPrinter::printEvent(GameEvent* event) {
    if (event == nullptr) {
        std::cout << OTHER_SYMBOL;
        return;
    }
    if (dynamic_cast<BombEvent*>(event) != nullptr) {
        std::cout << BOMB_SYMBOL;
        return;
    }
    if (dynamic_cast<TotemEvent*>(event) != nullptr) {
        std::cout << TOTEM_SYMBOL;
        return;
    }
    if (dynamic_cast<TeleportEvent*>(event) != nullptr) {
        std::cout << TELEPORT_SYMBOL;
        return;
    }
}