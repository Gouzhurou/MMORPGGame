#include <iostream>
#include "Direction.h"
#include "TeleportEvent.h"

TeleportEvent::TeleportEvent(Controller& action) {
    this->action = &action;
    // std::cout << "Teleport was created" << std::endl;
}

void TeleportEvent::event() {
    int direction;
    Point checkPoint = *(action->getPoint());

    for (direction = 0; direction < 4; direction++) {
        Point moved = checkPoint.move(direction);
        if (action->getField()->getCell(moved.getX(), moved.getY())->getPassability()) {
            break;
        }
    }
    this->action->move(static_cast<Direction>(direction));
}

void TeleportEvent::print() {
    std::cout << "o";
}