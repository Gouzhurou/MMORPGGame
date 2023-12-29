#include <iostream>
#include <string>
#include "../../h/model/Character.h"

Character::Character(std::string name) {
    this->hp = START_MAX_HP;
    this->maxHp = START_MAX_HP;
    this->damage = 1;
    this->defense = 0;
    this->visionRadius = START_VISION_RADIUS;
    this->name = name;
}

void Character::printInfo() {
    std::cout << "hp: " << this->hp << std::endl;
    std::cout << "max hp: " << this->maxHp << std::endl;
    std::cout << "damage: " << this->damage << std::endl;
    std::cout << "defence: " << this->defense << std::endl;
    std::cout << "vision: " << this->visionRadius << std::endl;
    std::cout << "name: " << this->name << std::endl;
    std::cout << std::endl;
}

void Character::printHp() {
    std::cout << "hp: ";
    unsigned hpSize = hp / SCALE_SIZE;
    unsigned maxHpSize = maxHp / SCALE_SIZE;
    for (int i = 0; i < hpSize; i++) {
        std::cout << '*' << " ";
    }
    for (int i = 0; i < maxHpSize - hpSize; i++) {
        std::cout << '-' << ' ';
    }
    std::cout << std::endl;
}

void Character::eatApple(unsigned index) {
    Apple* apples = this->bag.getApples();
    if (this->hp + apples[index].getHp() >= this->maxHp) {
        this->hp = this->maxHp;
    }
    else this->hp += apples[index].getHp();
    this->bag.deleteApple(index);
}

bool Character::canBringApple() {
    return !(this->bag.applesIsFull());
}

void Character::bringApple(Apple apple) {
    if (!(this->canBringApple())) return;
    this->bag.addApple(apple);
}

bool Character::canBringRing() {
    return !(this->bag.ringsIsFull());
}

void Character::bringRing(Ring ring) {
    if (!(this->canBringRing())) return;
    this->bag.addRing(ring);
    unsigned value = ring.getValue();
    switch(ring.getType()) {
        case RingType::DAMAGE:
            this->damage += value;
            break;
        case RingType::DEFENSE:
            this->defense += value;
            break;
        case RingType::HP:
            this->maxHp += value;
            break;
        case RingType::VISION:
            this->visionRadius += value;
            break;
    }
}

void Character::deleteRing(unsigned index) {
    Ring ring = this->bag.getRings()[index];
    Ring emptyRing;
    if (ring.isEqual(emptyRing)) return;
    unsigned value = ring.getValue();
    switch(ring.getType()) {
        case RingType::DAMAGE:
            this->damage -= value;
            break;
        case RingType::DEFENSE:
            this->defense -= value;
            break;
        case RingType::HP:
            this->maxHp -= value;
            break;
        case RingType::VISION:
            this->visionRadius -= value;
            break;
    }
    this->bag.deleteRing(index);
}

void Character::addExp(unsigned exp) {
    this->level.addExp(exp);
}

void Character::setHp(unsigned hp) {
    this->hp = hp;
}

unsigned Character::getMaxHp() {
    return this->maxHp;
}

unsigned Character::getHp() {
    return this->hp;
}

void Character::reload() {
    this->hp = START_MAX_HP;
    this->maxHp = START_MAX_HP;
    this->damage = 1;
    this->defense = 0;
    this->visionRadius = START_VISION_RADIUS;
}

unsigned Character::getVisionRadius() {
    return visionRadius;
}