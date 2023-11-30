#include <iostream>
#include "Action.h"

Action::Action(Character* hero, Field* field) {
    std::cout << "action was created" << std::endl;
    this->hero = hero;
    this->field = field;
    if (field != nullptr) {
        this->point = field->getStart();
    }
    // std::cout << "You are here: ";
    // this->point.print();
}

void Action::move(Direction direction) {
    Point futurePoint;
    int futureX;
    int futureY;
    switch(direction) {
        case Direction::RIGHT:
            futureX = point.getX() + 1;
            futureY = point.getY();
            futurePoint = Point(futureX, futureY);
            if (this->field->pointIsCorrect(futurePoint) && 
                this->field->getCell(futureX, futureY)->getPassability()) {
                this->point = futurePoint;
            }
            break;
        case Direction::DOWN:
            futureX = point.getX();
            futureY = point.getY() + 1;
            futurePoint = Point(futureX, futureY);
            if (this->field->pointIsCorrect(futurePoint) && 
                this->field->getCell(futureX, futureY)->getPassability()) {
                this->point = futurePoint;
            }
            break;
        case Direction::LEFT:
            futureX = point.getX() - 1;
            futureY = point.getY();
            if (futureX < 0) break;
            futurePoint = Point(futureX, futureY);
            if (this->field->pointIsCorrect(futurePoint) && 
                this->field->getCell(futureX, futureY)->getPassability()) {
                this->point = futurePoint;
            }
            break;
        case Direction::UP:
            futureX = point.getX();
            futureY = point.getY() - 1;
            if (futureY < 0) break;
            futurePoint = Point(futureX, futureY);
            if (this->field->pointIsCorrect(futurePoint) && 
                this->field->getCell(futureX, futureY)->getPassability()) {
                this->point = futurePoint;
            }
            break;
    }
    std::cout << "You are here: ";
    this->point.print();
    GameEvent* event = field->getCell(
        this->point.getX(), this->point.getY()
    )->getEvent();
    if (event != nullptr) {
        event->event();
    }
}

Character* Action::getHero() {
    return this->hero;
}

Point* Action::getPoint() {
    return &(this->point);
}

Field* Action::getField() {
    return this->field;
}

void Action::setField(Field* field) {
    this->field = field;
    this->point = field->getStart();
}

void Action::setPoints(unsigned startX, unsigned startY, unsigned endX, unsigned endY) {
    std::cout << "points setting in action" << std::endl;
    this->field->setPoints(startX, startY, endX, endY);
    this->point = Point(startX, startY);
}
