#include <iostream>
#include "BombEvent.h"

BombEvent::BombEvent(Action& action) {
    this->action = &action;
    std::cout << "Bomb was created" << std::endl;
}

void BombEvent::event() {
    Character* hero = this->action->getHero();
    hero->setHp(hero->getHp() - hero->getMaxHp() / 4);
    std::cout << "The bomb did its job" << std::endl;
    hero->printInfo();
}

void BombEvent::print() {
    // std::cout << "Bomb print message" << std::endl;
    std::cout << "x";
}