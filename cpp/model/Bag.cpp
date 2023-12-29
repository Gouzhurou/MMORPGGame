#include "../../h/model/Bag.h"

Bag::Bag() {
    for (unsigned i = 0; i < BAG_SIZE; i++) {
        Apple apple;
        Ring ring;
        this->rings[i] = ring;
        this->apples[i] = apple;
    }
}

void Bag::deleteRing(unsigned index) {
    Ring emptyRing;
    if (this->rings[index].isEqual(emptyRing)) return;
    this->rings[index].copy(emptyRing);
}

void Bag::addRing(Ring ring) {
    if (this->ringsIsFull()) return;
    Ring emptyRing;
    unsigned index = 0;
    for (index; index < BAG_SIZE; index++) {
        if (this->rings[index].isEqual(emptyRing)) break;
    }
    this->rings[index].copy(ring);
}

void Bag::deleteApple(unsigned index) {
    Apple emptyApple;
    if (this->apples[index].isEqual(emptyApple)) return;
    this->apples[index].copy(emptyApple);
}

void Bag::addApple(Apple apple) {
    if (this->applesIsFull()) return;
    Apple emptyApple;
    unsigned index = 0;
    for (index; index < BAG_SIZE; index++) {
        if (this->apples[index].isEqual(emptyApple)) break;
    }
    this->apples[index].copy(apple);
}

Ring* Bag::getRings() {
    return this->rings;
}

Apple* Bag::getApples() {
    return this->apples;
}

bool Bag::applesIsFull() {
    Apple emptyApple;
    unsigned index = 0;
    for (index; index < BAG_SIZE; index++) {
        if (this->apples[index].isEqual(emptyApple)) break;
    }
    return index == BAG_SIZE;
}

bool Bag::ringsIsFull() {
    Ring emptyRing;
    unsigned index = 0;
    for (index; index < BAG_SIZE; index++) {
        if (this->rings[index].isEqual(emptyRing)) break;
    }
    return index == BAG_SIZE;
}