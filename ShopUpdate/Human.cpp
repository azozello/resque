//
// Created by azozello on 11.05.17.
//

#include "../h/Human.h"

Human::Human(const string &name) : name(name) {}

Human::Human() {}

const string &Human::getName() const {
    return name;
}

void Human::setName(const string &name) {
    Human::name = name;
}
