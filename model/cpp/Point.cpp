#include <iostream>
#include "Point.h"

Point::Point(unsigned x, unsigned y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
    // std::cout << "Point coped in constructor" << std::endl;
}

Point& Point::operator=(const Point& other) {
    this->x = other.x;
    this->y = other.y;
    // std::cout << "Point coped" << std::endl;
    // this->print();
    return *this;
}

Point::Point(Point&& moved) : x(moved.x), y(moved.y) {
    // std::cout << "Point moved in constructor" << std::endl;
}

Point& Point::operator=(Point&& moved) {
    this->x = moved.x;
    this->y = moved.y;
    // std::cout << "Point moved" << std::endl;
    // this->print();
    return *this;
}

unsigned Point::getX() {
    return this->x;
}

unsigned Point::getY() {
    return this->y;
}

void Point::print() {
    std::cout << this->x << " " << this->y << std::endl;
}