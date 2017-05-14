//
// Created by azozello on 14.05.17.
//

#include "../h/Item.h"

Item::Item(float price, const string &author) : price(price), author(author) {}

Item::Item() {}

float Item::getPrice() const {
    return price;
}

void Item::setPrice(float price) {
    Item::price = price;
}

const string &Item::getAuthor() const {
    return author;
}

void Item::setAuthor(const string &author) {
    Item::author = author;
}
