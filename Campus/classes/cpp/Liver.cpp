//
// Created by azozello on 08.05.17.
//

#include "../h/Liver.h"

Liver::Liver() {}

const Room &Liver::getRoom() const {
    return room;
}

void Liver::setRoom(const Room &room) {
    Liver::room = room;
}

Liver::Liver(bool sex, const string &name, const Room &room) : Human(sex, name), room(room) {}
