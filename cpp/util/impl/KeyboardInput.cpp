#include <iostream>
#include "../../../h/util/impl/KeyboardInput.h"

Command KeyboardInput::input(std::map<char, Command> commands) {
    char command;
    std::cin >> command;
    if (commands.find(command) != commands.end()) {
        return commands[command];
    } 
    return Command::OTHER;
}
