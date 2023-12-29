#include <iostream>
#include "../../h/util/FieldGenerator.h"
#include <stdlib.h>
#include <ctime>

Field* FieldGenerator::generateRandom(Controller& action, unsigned x, unsigned y) {
    Field* field = new Field(x, y);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i == 0 || i == x - 1 || j == 0 || j == y - 1) {
                field->getCell(i, j)->setPassability(false);
            }
        }
    }

    unsigned startX = 1;
    unsigned startY = y - 2;
    unsigned endX = x - 2;
    unsigned endY = y - 2;
    field->setPoints(startX, startY, endX, endY);

    unsigned weight = (x - 2) * (y - 2) - 1;
    unsigned bombsCount = weight / BOMB_FREQUENCY + 1;
    unsigned totemsCount = weight / TOTEM_FREQUENCY + 1;
    unsigned teleportsCount = weight / TELEPORT_FREQUENCY + 1;
    unsigned curBombsCount = 0;
    unsigned curTotemsCount = 0;
    unsigned curTeleportsCount = 0;

    srand(time(NULL));
    while (true) {
        unsigned curX = rand() % (x - 2) + 1;
        unsigned curY = rand() % (y - 2) + 1;
        while (curX == 1 && curY == 1 || curX == x - 2 && curY == y - 2) {
            curX = rand() % (x - 2) + 1;
            curY = rand() % (y - 2) + 1;
        }
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