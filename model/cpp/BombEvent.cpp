#include <iostream>
#include "BombEvent.h"

BombEvent::BombEvent(Controller& action) {
    this->action = &action;
}

void BombEvent::event() {
    Character* hero = this->action->getHero();
    int hp = hero->getHp() - hero->getMaxHp() / 4;
    hero->setHp(hp < 0 ? 0 : hp);
}