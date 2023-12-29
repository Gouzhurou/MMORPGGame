#include <iostream>
#include "Cell.h"

Cell::Cell(bool passability, GameEvent* event){
    this->passability = passability;
    this->event = event; 
}

void Cell::setPassability(bool passability){
    this->passability = passability;
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