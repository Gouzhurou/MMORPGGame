#include "../../h/model/Apple.h"

Apple::Apple(unsigned hp) {
    this->hp = hp;
}

unsigned Apple::getHp() {
    return this->hp;
}

void Apple::setHp(unsigned hp) {
    this->hp = hp;
}

bool Apple::isEqual(Apple& other) {
    return this->hp == other.getHp();
}

void Apple::copy(Apple& other) {
    this->hp = other.getHp();
}
