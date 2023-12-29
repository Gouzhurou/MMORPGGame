#include "Ring.h"
#include "Apple.h"

#ifndef BAG_H_INCLUDED
#define BAG_H_INCLUDED
#define BAG_SIZE 10

class Bag{
private:
    Ring rings[BAG_SIZE];
    Apple apples[BAG_SIZE];
public:
    Bag();
    void deleteRing(unsigned);
    void addRing(Ring);
    void deleteApple(unsigned);
    void addApple(Apple);
    Ring* getRings();
    Apple* getApples();
    bool applesIsFull();
    bool ringsIsFull();
};

#endif // BAG_H_INCLUDED
