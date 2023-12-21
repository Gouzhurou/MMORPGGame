#include <iostream>
#include "BombEvent.h"

BombEvent::BombEvent(Controller& action) {
    this->action = &action;
    // std::cout << "Bomb was created" << std::endl;
}

void BombEvent::event() {
    Character* hero = this->action->getHero();
    int hp = hero->getHp() - hero->getMaxHp() / 4;
    hero->setHp(hp < 0 ? 0 : hp);
    // std::cout << "The bomb did its job" << std::endl;
    // hero->printInfo();
}

void BombEvent::print() {
    // std::cout << "Bomb print message" << std::endl;
    std::cout << "x";
}