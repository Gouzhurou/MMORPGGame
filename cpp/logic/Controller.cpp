#include <iostream>
#include "../../h/logic/Controller.h"

Controller::Controller(Character* hero, Field* field) {
    this->hero = hero;
    this->field = field;
    if (field != nullptr) {
        this->point = field->getStart();
    }
}

void Controller::move(Direction direction) {
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
    GameEvent* event = field->getCell(
        this->point.getX(), this->point.getY()
    )->getEvent();
    if (event != nullptr) {
        event->event();
    }
    field->getCell(
        this->point.getX(), this->point.getY()
    )->setEvent(nullptr);
}

Character* Controller::getHero() {
    return this->hero;
}

Point* Controller::getPoint() {
    return &(this->point);
}

Field* Controller::getField() {
    return this->field;
}

void Controller::setField(Field* field) {
    this->field = field;
    this->point = field->getStart();
}

void Controller::setPoints(unsigned startX, unsigned startY, unsigned endX, unsigned endY) {
    this->field->setPoints(startX, startY, endX, endY);
    this->point = Point(startX, startY);
}
