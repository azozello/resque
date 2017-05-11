//
// Created by azozello on 12.05.17.
//

#include "../h/Order.h"

Order::Order() {}

Order::Order(const string &hairDress, const string &hairDresser, float price) : hairDress(hairDress),
                                                                                hairDresser(hairDresser),
                                                                                price(price) {}

const string &Order::getHairDress() const {
    return hairDress;
}

void Order::setHairDress(const string &hairDress) {
    Order::hairDress = hairDress;
}

const string &Order::getHairDresser() const {
    return hairDresser;
}

void Order::setHairDresser(const string &hairDresser) {
    Order::hairDresser = hairDresser;
}

float Order::getPrice() const {
    return price;
}

void Order::setPrice(float price) {
    Order::price = price;
}
