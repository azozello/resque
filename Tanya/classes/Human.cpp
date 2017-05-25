//
// Created by azozello on 25.05.17.
//

#include "Human.h"

Human::Human() {}

const string &Human::getName() const {
    return name;
}

void Human::setName(const string &name) {
    Human::name = name;
}

const string &Human::getSurname() const {
    return surname;
}

void Human::setSurname(const string &surname) {
    Human::surname = surname;
}
