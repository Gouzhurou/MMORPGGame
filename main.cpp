#include <iostream>
#include <string>
#include "model/h/Level.h"
#include "model/h/Character.h"
#include "model/h/Action.h"
#include "model/h/Ring.h"
#include "model/h/Apple.h"
#include "model/h/Bag.h"
#include "model/h/Point.h"
#include "model/h/Cell.h"
#include "model/h/Field.h"
#include "model/h/BombEvent.h"
#include "model/h/TeleportEvent.h"
#include "model/h/FieldGenerator.h"

int main()  
{
    // Point p1(1, 1);
    // Point p2(3, 4);
    // Field f2;
    // f2.setPoints(p1, p2);
    // Field f1(f2);
    // f1.print();
    Character hero {"Joe"};
    // Ring winterRing ("winterRing", RingType::DAMAGE, 2);
    // Ring dragonRing ("dragonRing", RingType::DEFENSE, 3);
    // Ring ring;
    // Apple apple(3);
    // hero.printInfo();
    // hero.bringRing(winterRing);
    // hero.printInfo();
    // hero.bringRing(dragonRing);
    // hero.printInfo();
    // hero.bringApple(apple);
    // hero.eatApple(0);
    hero.printInfo();
    Action action(&hero);
    FieldGenerator generator;
    action.setField(generator.generateRandom(action)); 
    action.getField()->print();
    // BombEvent bomb(action);
    // TeleportEvent teleport(action);
    // action.getField()->setEventInCell(2, 1, &bomb);
    // action.move(Direction::RIGHT);
    // hero.printInfo();
    // action.getField()->setEventInCell(2, 2, &teleport);
    // action.move(Direction::DOWN);
    std::cout << "point ";
    action.getPoint()->print();
    std::cout << "start moving" << std::endl;
    action.move(Direction::RIGHT);
    action.move(Direction::RIGHT);
    action.move(Direction::UP);
    action.move(Direction::RIGHT);
    action.move(Direction::RIGHT);
    action.move(Direction::DOWN);
    action.move(Direction::DOWN);
    action.move(Direction::RIGHT);
    action.move(Direction::DOWN);
    action.move(Direction::DOWN);
    action.move(Direction::LEFT);
    action.move(Direction::LEFT);
    action.move(Direction::UP);
    action.move(Direction::UP);

    return 0;
}
