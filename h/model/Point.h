#include "../logic/enum/Direction.h"

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#define DEFAULT_VALUE 0

class Point {
private:
    unsigned x;
    unsigned y;
public:
    Point(unsigned x = DEFAULT_VALUE, unsigned y = DEFAULT_VALUE);
    Point(const Point&);
    Point& operator=(const Point&);
    Point(Point&&);
    Point& operator=(Point&&);
    unsigned getX();
    unsigned getY();
    void print();
    bool operator!=(Point&);
    bool operator==(Point&);
    Point move(int);
};

#endif