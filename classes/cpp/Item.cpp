//
// Created by azozello on 02.05.17.
//

#include "../h/Item.h"

Item::Item(const string &name, float sellPrice, float buyPrice) : name(name), sellPrice(sellPrice),
                                                                  buyPrice(buyPrice) {}

Item::Item() {}

const string &Item::getName() const {
    return name;
}

void Item::setName(const string &name) {
    Item::name = name;
}

float Item::getSellPrice() const {
    return sellPrice;
}

void Item::setSellPrice(float sellPrice) {
    Item::sellPrice = sellPrice;
}

float Item::getBuyPrice() const {
    return buyPrice;
}

void Item::setBuyPrice(float buyPrice) {
    Item::buyPrice = buyPrice;
}
