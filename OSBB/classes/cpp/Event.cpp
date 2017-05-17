//
// Created by azozello on 17.05.17.
//

#include "../h/Event.h"

Event::Event() {}

const string &Event::getDescription() const {
    return description;
}

void Event::setDescription(const string &description) {
    Event::description = description;
}

const string &Event::getName() const {
    return name;
}

void Event::setName(const string &name) {
    Event::name = name;
}
