#include <iostream>
#include "Cell.h"

Cell::Cell(bool passability, GameEvent* event){
    this->passability = passability;
    this->event = event; 
}

void Cell::setPassability(bool passability){
    this->passability = passability;
}

void Cell::print() {
    if (this->passability) {
        if (this->event != nullptr) {
            this->event->print();
        }
        else {
            std::cout << " ";
        }
    }
    else {
        std::cout << "#";
    }
}

bool Cell::getPassability() {
    return this->passability;
}

GameEvent* Cell::getEvent() {
    return this->event;
}

void Cell::setEvent(GameEvent* event) {
    this->event = event;
}