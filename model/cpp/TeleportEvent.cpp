#include <iostream>
#include "Direction.h"
#include "TeleportEvent.h"

TeleportEvent::TeleportEvent(Action& action) {
    this->action = &action;
    std::cout << "Teleport was created" << std::endl;
}

void TeleportEvent::event() {
    this->action->move(Direction::LEFT);
    this->action->move(Direction::UP);
}

void TeleportEvent::print() {
    std::cout << "o";
}