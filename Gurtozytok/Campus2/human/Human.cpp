//
// Created by azozello on 09.05.17.
//

#include "Human.h"

Human::Human() {}

Human::Human(bool sex, const string &name) : sex(sex), name(name) {}

bool Human::isSex() const {
    return sex;
}

void Human::setSex(bool sex) {
    Human::sex = sex;
}

const string &Human::getName() const {
    return name;
}

void Human::setName(const string &name) {
    Human::name = name;
}
