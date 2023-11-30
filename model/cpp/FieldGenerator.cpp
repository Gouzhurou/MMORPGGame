#include <iostream>
#include "FieldGenerator.h"
#include "BombEvent.h"
#include "TotemEvent.h"
#include "TeleportEvent.h"
#include <stdlib.h>


Field* FieldGenerator::generateRandom(Action& action, unsigned x, unsigned y) {
    Field* field = new Field(x, y);
    std::cout << "field was created" << std::endl;
    field->printSize();

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i == 0 || i == x - 1 || j == 0 || j == y - 1) {
                field->getCell(i, j)->setPassability(false);
            }
        }
    }
    std::cout << "borders was setted" << std::endl;

    unsigned startX = 1;
    unsigned startY = 1;
    unsigned endX = x - 2;
    unsigned endY = y - 2;
    field->setPoints(startX, startY, endX, endY);
    std::cout << "points was setted" << std::endl;

    unsigned weight = (x - 2) * (y - 2) - 1;
    unsigned bombsCount = weight / BOMB_FREQUENCY + 1;
    unsigned totemsCount = weight / TOTEM_FREQUENCY + 1;
    unsigned teleportsCount = weight / TELEPORT_FREQUENCY + 1;
    unsigned curBombsCount = 0;
    unsigned curTotemsCount = 0;
    unsigned curTeleportsCount = 0;

    std::cout << bombsCount << " bombs" << std::endl;
    std::cout << totemsCount << " totems" << std::endl;
    std::cout << teleportsCount << " teleports" << std::endl;

    while (true) {
        unsigned curX = rand() % (x - 2) + 1;
        unsigned curY = rand() % (y - 2) + 1;
        Cell* cur_cell = field->getCell(curX, curY);
        if (cur_cell->getPassability() && cur_cell->getEvent() == nullptr) {
            if (curBombsCount < bombsCount) {
                BombEvent* bomb = new BombEvent(action);
                curBombsCount += 1;
                cur_cell->setEvent(bomb);
            }
            else if (curTotemsCount < totemsCount) {
                TotemEvent* totem = new TotemEvent(action);
                curTotemsCount += 1;
                cur_cell->setEvent(totem);
            }
            else if (curTeleportsCount < teleportsCount) {
                TeleportEvent* teleport = new TeleportEvent(action);
                curTeleportsCount += 1;
                cur_cell->setEvent(teleport);
            }
        }
        if (curBombsCount == bombsCount && curTotemsCount == totemsCount &&
            curTeleportsCount == teleportsCount) {
                break;
            }
    }

    return field;
}

Field* FieldGenerator::generateRandom(Action& action) {
    return this->generateRandom(action, FIELD_SIZE, FIELD_SIZE);
}