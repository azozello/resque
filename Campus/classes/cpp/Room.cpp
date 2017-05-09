//
// Created by azozello on 08.05.17.
//

#include "../h/Room.h"

Room::Room(int number) : number(number) {}

Room::Room() {}

int Room::getNumber() const {
    return number;
}

void Room::setNumber(int number) {
    Room::number = number;
}

const string &Room::getInfo() const {
    return info;
}

void Room::setInfo(const string &info) {
    Room::info = info;
}
