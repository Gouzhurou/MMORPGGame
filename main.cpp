#include <iostream>
#include <string>
#include "h/model/Level.h"
#include "h/model/Character.h"
#include "h/logic/Controller.h"
#include "h/model/Ring.h"
#include "h/model/Apple.h"
#include "h/model/Bag.h"
#include "h/model/Point.h"
#include "h/model/Cell.h"
#include "h/model/Field.h"
#include "h/event/impl/BombEvent.h"
#include "h/event/impl/TeleportEvent.h"
#include "h/util/FieldGenerator.h"
#include "h/logic/Game.h"
#include "h/util/impl/KeyboardInput.h"
#include "h/util/FileReader.h"
#include "h/util/enum/Command.h"

int main()  
{
    Character hero {"Joe"};
    Controller controller(&hero);
    FileReader fileReader = FileReader();
    std::map<char, Command> commands = fileReader.getCommands();
    Game game(controller, commands);

    while (game.startGame()) {}

    return 0;
}
