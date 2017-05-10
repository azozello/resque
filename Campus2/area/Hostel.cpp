//
// Created by azozello on 09.05.17.
//

#include <vector>
#include "Hostel.h"

Hostel::Hostel(const string &name) : name(name) {}

Hostel::Hostel() {}

const string &Hostel::getName() const {
    return name;
}

void Hostel::setName(const string &name) {
    Hostel::name = name;
}
