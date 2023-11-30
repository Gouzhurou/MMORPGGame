#include <iostream>
#include "TotemEvent.h"

TotemEvent::TotemEvent(Action& action) {
    this->action = &action;
    std::cout << "Totem was created" << std::endl;
}

void TotemEvent::event() {
    Character* hero = this->action->getHero();
    hero->setHp(hero->getMaxHp());
    std::cout << "totem did its job" << std::endl;
    hero->printInfo();
}

void TotemEvent::print() {
    std::cout << "*";
}