#include <iostream>
#include "../../h/model/Level.h"

Level::Level(){
    this->level = 1;
    this->exp = 0;
}

void Level::addExp(unsigned exp) {
    this->exp += exp;
    if (this->exp >= MAX_EXP){
        this->exp -= MAX_EXP;
        this->level += 1;
    }
    std::cout << "exp: " << this->exp << std::endl;
}
