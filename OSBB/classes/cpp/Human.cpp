//
// Created by azozello on 17.05.17.
//

#include "../h/Human.h"

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
