//
// Created by azozello on 12.05.17.
//

#include "../h/HairDress.h"

HairDress::HairDress() {}

HairDress::HairDress(const string &name, float price) : name(name), price(price) {}

const string &HairDress::getName() const {
    return name;
}

void HairDress::setName(const string &name) {
    HairDress::name = name;
}

float HairDress::getPrice() const {
    return price;
}

void HairDress::setPrice(float price) {
    HairDress::price = price;
}
