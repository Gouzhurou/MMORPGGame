#include "Cell.h"
#include "Point.h"
#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#define FIELD_SIZE 7
#define START 0

class Field {
private:
    unsigned width;
    unsigned height;
    Point start;
    Point end;
    Cell **field;
public:
    Field(unsigned, unsigned);
    void setPoints(unsigned, unsigned, unsigned, unsigned);
    bool pointIsCorrect(Point&);
    bool widthIsCorrect(unsigned);
    bool heightIsCorrect(unsigned);
    Field();
    Field(const Field&);
    Field& operator=(const Field&);
    Field(Field&&);
    Field& operator=(Field&&);
    ~Field();
    void print();
    Cell* getCell(unsigned, unsigned);
    Point getStart();
    void setEventInCell(unsigned, unsigned, GameEvent*);
    void printSize();
};

#endif