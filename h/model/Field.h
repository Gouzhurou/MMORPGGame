#include "Cell.h"
#include "Point.h"
#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#define FIELD_SIZE 7
#define START 1

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
    Cell* getCell(unsigned, unsigned);
    Point getStart();
    Point getEnd();
    void setEventInCell(unsigned, unsigned, GameEvent*);
    unsigned getWidth();
    unsigned getHeight();
};

#endif