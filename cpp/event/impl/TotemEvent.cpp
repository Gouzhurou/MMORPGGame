#include <iostream>
#include "../../../h/event/impl/TotemEvent.h"

TotemEvent::TotemEvent(Controller& action) {
    this->action = &action;
}

void TotemEvent::event() {
    Character* hero = this->action->getHero();
    hero->setHp(hero->getMaxHp());
}