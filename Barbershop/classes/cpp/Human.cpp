//
// Created by azozello on 12.05.17.
//

#include "../h/Human.h"

bool Human::isSex() const {
    return sex;
}

void Human::setSex(bool sex) {
    Human::sex = sex;
}

Human::Human() {}

const string &Human::getName() const {
    return name;
}

void Human::setName(const string &name) {
    Human::name = name;
}

Human::Human(bool sex, const string &name) : sex(sex), name(name) {}

const string &Human::getSurname() const {
    return surname;
}

void Human::setSurname(const string &surname) {
    Human::surname = surname;
}
