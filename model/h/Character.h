#include <string>
#include "Level.h"
#include "Bag.h"
#include "Apple.h"
#include "Ring.h"
#include "RingType.h"
#define START_VISION_RADIUS 5
#define START_MAX_HP 100
#define SCALE_SIZE 10

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

class Character
{
private:
    unsigned hp;
    unsigned maxHp;
    unsigned damage;
    unsigned defense;
    unsigned visionRadius;
    Level level;
    std::string name;
    Bag bag;
public:
    Character(std::string name="");
    void printInfo();
    void printHp();
    void eatApple(unsigned);
    bool canBringApple();
    void bringApple(Apple);
    bool canBringRing();
    void bringRing(Ring);
    void deleteRing(unsigned);
    void addExp(unsigned);
    void setHp(unsigned);
    unsigned getMaxHp();
    unsigned getHp();
    void reload();
    unsigned getVisionRadius();
};

#endif // CHARACTER_H_INCLUDED
