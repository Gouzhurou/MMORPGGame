#include "FileReader.h"
#include <iostream>

FileReader::FileReader(){
    std::fstream in(FILENAME);
    this->in = &in;
    char command;
    std::string skip;
 
    if (in.is_open()){
        if (!check(this->in)) {
            setDefault();
            return;
        }

        in.seekg(0);
        std::getline(in, skip);
        for (int i = 0; i < COMMAND_SIZE; i++) {
            in >> command;
            commands[command] = static_cast<Command>(i);
            in >> command;
        }
        return;
    }
    
    setDefault();
}

bool FileReader::check(std::fstream* in) {
    std::string s;

    std::getline(*in, s);
    std::set<std::string> names = splitString(s);
    if (names.size() != COMMAND_SIZE) {
        return false;
    }

    std::getline(*in, s);
    std::set<std::string> values = splitString(s);
    if (values.size() != COMMAND_SIZE) {
        return false;
    }

    return true;
}

std::set<std::string> FileReader::splitString(std::string s) {
    size_t pos = 0;
    std::string token;
    std::string delimeter = ";";
    std::set<std::string> set = {};
    while ((pos = s.find(delimeter)) != std::string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + delimeter.length());
        set.insert(token);
    }
    if (s != "") set.insert(s);
    return set;
}

void FileReader::setDefault(){
    commands['w'] = Command::UP;
    commands['s'] = Command::DOWN;
    commands['a'] = Command::LEFT;
    commands['d'] = Command::RIGHT;
    commands['z'] = Command::EXIT;
    commands['r'] = Command::RESTART;
}

std::map<char, Command> FileReader::getCommands(){
    return commands;
}

FileReader::~FileReader() {
    in->close();
    in = nullptr;
}