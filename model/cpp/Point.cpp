#include <iostream>
#include "Point.h"

Point::Point(unsigned x, unsigned y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Point::Point(Point&& moved) : x(moved.x), y(moved.y) {
}

Point& Point::operator=(Point&& moved) {
    this->x = moved.x;
    this->y = moved.y;
    return *this;
}

bool Point::operator!=(Point& point) {
    return this->x != point.getX() || this->y != point.getY();
}

bool Point::operator==(Point& point) {
    return this->x == point.getX() && this->y == point.getY();
}

unsigned Point::getX() {
    return this->x;
}

unsigned Point::getY() {
    return this->y;
}

Point Point::move(int direction) {
    unsigned x = this->x;
    unsigned y = this->y;
    switch (direction) {
        case static_cast<int>(Direction::UP):
            y += 1;
            break;
        case static_cast<int>(Direction::DOWN):
            y -= 1;
            break;
        case static_cast<int>(Direction::LEFT):
            x -= 1;
            break;
        case static_cast<int>(Direction::RIGHT):
            x += 1;
            break;
    }

    return Point(x, y);
}

void Point::print() {
    std::cout << this->x << " " << this->y << std::endl;
}