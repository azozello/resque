//
// Created by azozello on 10.05.17.
//

#include "../h/City.h"

City::City(const string &name, int distance) : name(name), distance(distance) {}

City::City() {}

const string &City::getName() const {
    return name;
}

void City::setName(const string &name) {
    City::name = name;
}

int City::getDistance() const {
    return distance;
}

void City::setDistance(int distance) {
    City::distance = distance;
}
