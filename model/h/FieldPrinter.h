#include "Field.h"

#ifndef FIELDPRINTER_H_INCLUDED
#define FIELDPRINTER_H_INCLUDED

class FieldPrinter {
public:
    virtual void print(Point&, unsigned) = 0;
};

#endif
