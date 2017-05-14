//
// Created by azozello on 14.05.17.
//

#include "../h/Advertise.h"

Advertise::Advertise(float price, const string &author, const string &path) : Item(price, author), path(path) {}

Advertise::Advertise() {}

const string &Advertise::getPath() const {
    return path;
}

void Advertise::setPath(const string &path) {
    Advertise::path = path;
}
