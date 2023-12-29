#include "enum/Command.h"
#include <map>
#include <set>
#include <fstream>
#define FILENAME "commands.txt"

#ifndef FILEREADER_H_INCLUDED
#define FILEREADER_H_INCLUDED

class FileReader {
private:
    std::fstream* in;
    std::map<char, Command> commands;
    void setDefault();
    std::set<std::string> splitString(std::string);
    bool check(std::fstream*);

public:
    FileReader();
    std::map<char, Command> getCommands();
    ~FileReader();
};
#endif