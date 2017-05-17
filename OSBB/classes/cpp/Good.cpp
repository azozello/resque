//
// Created by azozello on 17.05.17.
//

#include "../h/Good.h"

Good::Good() {}

const string &Good::getName() const {
    return name;
}

void Good::setName(const string &name) {
    Good::name = name;
}

float Good::getPrice() const {
    return price;
}

void Good::setPrice(float price) {
    Good::price = price;
}
