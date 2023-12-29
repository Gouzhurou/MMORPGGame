#include <string>
#include "enum/RingType.h"

#ifndef RING_H_INCLUDED
#define RING_H_INCLUDED

class Ring {
private:
    std::string name;
    RingType type;
    unsigned value;
public:
    Ring(std::string name="", RingType type=RingType::NONE, unsigned value=0);
    unsigned getValue();
    void setValue(unsigned);
    RingType getType();
    void setType(RingType);
    std::string getName();
    void setName(std::string);
    bool isEqual(Ring&);
    void copy(Ring&);
};

#endif // RING_H_INCLUDED
