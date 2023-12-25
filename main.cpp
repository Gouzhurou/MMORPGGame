#include <iostream>
#include <string>
#include "model/h/Level.h"
#include "model/h/Character.h"
#include "model/h/Controller.h"
#include "model/h/Ring.h"
#include "model/h/Apple.h"
#include "model/h/Bag.h"
#include "model/h/Point.h"
#include "model/h/Cell.h"
#include "model/h/Field.h"
#include "model/h/BombEvent.h"
#include "model/h/TeleportEvent.h"
#include "model/h/FieldGenerator.h"
#include "model/h/Game.h"

int main()  
{
    Character hero {"Joe"};
    Controller action(&hero);
    Game game(action);
    while (game.startGame()) {}

    return 0;
}
