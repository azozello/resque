//
// Created by azozello on 25.05.17.
//

#include "Building.h"

Building::Building() {}

int Building::getHash() const {
    return hash;
}

void Building::setHash(int hash) {
    Building::hash = hash;
}

const string &Building::getStreet() const {
    return street;
}

void Building::setStreet(const string &street) {
    Building::street = street;
}

int Building::getAddres() const {
    return adress;
}

void Building::setAddres(int addres) {
    Building::adress = addres;
}

const vector<Flat> &Building::getFlats() const {
    return flats;
}

void Building::setFlats(const vector<Flat> &flats) {
    Building::flats = flats;
}
