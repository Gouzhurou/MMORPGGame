#include "../../h/model/Ring.h"
#include <string>

Ring::Ring(std::string name, RingType type, unsigned value) {
    this->name = name;
    this->type = type;
    this->value = value;
}
unsigned Ring::getValue() {
    return this->value;
}
void Ring::setValue(unsigned value) {
    this->value = value;
}
RingType Ring::getType() {
    return this->type;
}
void Ring::setType(RingType type) {
    this->type = type;
}
std::string Ring::getName() {
    return this->name;
}
void Ring::setName(std::string name) {
    this->name = name;
}
bool Ring::isEqual(Ring& other) {
    return this->name == other.getName() &&
        this->type == other.getType() &&
        this->value == other.getValue();
}

void Ring::copy(Ring& other) {
    this->value = other.getValue();
    this->type = other.getType();
    this->name = other.getName();
}
