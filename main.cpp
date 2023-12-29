#include <iostream>
#include <string>
#include "h/logic/Game.h"

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
