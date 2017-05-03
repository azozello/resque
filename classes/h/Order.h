//
// Created by azozello on 02.05.17.
//

#ifndef SHOP_ORDER_H
#define SHOP_ORDER_H

#include <vector>
#include <iterator>
#include "Item.h"

class Order {
private:
vector<Item> products;
public:
    void addItem(Item item);
    float getPrice();

    const vector<Item> &getProducts() const;

    void setProducts(const vector<Item> &products);

    Order();
};


#endif //SHOP_ORDER_H
