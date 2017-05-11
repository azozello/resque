//
// Created by azozello on 02.05.17.
//

#ifndef SHOP_STOCK_H
#define SHOP_STOCK_H

#include <vector>
#include "Item.h"
#include "Serializer.h"

class Stock : public Serializer {
public:
    vector<Item> orderItem(Item item, int quantity);
};


#endif //SHOP_STOCK_H
