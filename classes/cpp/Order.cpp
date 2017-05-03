//
// Created by azozello on 02.05.17.
//

#include <iostream>
#include "../h/Order.h"

Order::Order() {}

float Order::getPrice() {
    float price = 0;
    for (int i = 0; i < getProducts().size(); i++) {
        price += getProducts()[i].getSellPrice();
        cout<<price<<endl;
    }
    return price;
}
void Order::addItem(Item item) {
    products.insert(getProducts().end(),item);
}

const vector<Item> &Order::getProducts() const {
    return products;
}

void Order::setProducts(const vector<Item> &products) {
    Order::products = products;
}
