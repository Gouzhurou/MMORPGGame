#include <iostream>
#include "Field.h"

Field::Field(unsigned width, unsigned height) {
    if (this->widthIsCorrect(width)) {
        this->width = width;
    }
    else {
        this->width = FIELD_SIZE;
    }
    if (this->heightIsCorrect(height)) {
        this->height = height;
    }
    else {
        this->height = FIELD_SIZE;
    }
    this->field = new Cell*[height];
    for (unsigned i = 0; i < height; i++) {
        this->field[i] = new Cell[width];
    }
    this->start = Point(START, START);
    this->end = Point(height - 1, width - 1);
}

bool Field::widthIsCorrect(unsigned width) {
    return width > 0;
}

bool Field::heightIsCorrect(unsigned height) {
    return height > 0;
}

void Field::setPoints(unsigned startX, unsigned startY, unsigned endX, unsigned endY) {
    Point start(startX, startY);
    Point end(endX, endY);
    if (this->pointIsCorrect(start)) {
        this->start = Point(startX, startY);
    }
    if (this->pointIsCorrect(end)) {
        this->end = Point(endX, endY);
    }
}

bool Field::pointIsCorrect(Point& point) {
    return point.getX() >= 0 && point.getX() < this->width &&
        point.getY() >= 0 && point.getY() < this->height;
}

Field::Field() : Field(FIELD_SIZE, FIELD_SIZE) {}

Field::Field(const Field& other) : 
    width(other.width), height(other.height), start(other.start),
    end(other.end), field(nullptr) {
    this->field = new Cell*[this->height];
    for (unsigned i = 0; i < this->height; i++) {
        this->field[i] = new Cell[this->width];
    }
    for (unsigned i = 0; i < this->height; i++) {
        memcpy(this->field[i], other.field[i], sizeof(Cell) * this->width);
    }
}

Field& Field::operator=(const Field& other) {
    if (this->field) this->~Field();
    this->width = other.width;
    this->height = other.height;
    this->start = other.start;
    this->end = other.end;
    this->field = new Cell*[this->height];
    for (unsigned i = 0; i < this->height; i++) {
        this->field[i] = new Cell[this->width];
    }
    for (unsigned i = 0; i < this->height; i++) {
        memcpy(this->field[i], other.field[i], sizeof(Cell) * this->width);
    }
    return *this;
}

Field::Field(Field&& moved) :
    width(moved.width), height(moved.height), start(moved.start),
    end(moved.end), field(moved.field) {
    moved.field = nullptr;
}

Field& Field::operator=(Field&& moved) {
    if (this->field) this->~Field();
    this->width = moved.width;
    this->height = moved.height;
    this->start = moved.start;
    this->end = moved.end;
    this->field = moved.field;
    moved.field = nullptr;
    return *this;
}

Field::~Field() {
    for (unsigned i = 0; i < this->height; i++) {
        delete[] this->field[i];
    }
    delete[] this->field;
    // std::cout << "Field was destroyed" << std::endl;
}

void Field::print(Point& characterPoint) {
    for (unsigned j = 0; j < this->width; j++) {
        for (unsigned i = 0; i < this->height; i++) {
            if (i == characterPoint.getX() && j == characterPoint.getY()) {
                std::cout << 'H';
            }
            else {
                this->getCell(i, j)->print();
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Cell* Field::getCell(unsigned x, unsigned y) {
    return &(this->field[y][x]);
}

Point Field::getStart() {
    return this->start;
}

Point Field::getEnd() {
    return this->end;
}

void Field::setEventInCell(unsigned x, unsigned y, GameEvent* event) {
    (this->field[y] + x)->setEvent(event);
}

void Field::printSize() {
    std::cout << this->width << " " << this->height << std::endl;
}