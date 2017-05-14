//
// Created by azozello on 14.05.17.
//

#include "../h/Human.h"

Human::Human(const string &name, const string &surname) : name(name), surname(surname) {}

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
