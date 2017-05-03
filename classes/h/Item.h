//
// Created by azozello on 02.05.17.
//

#ifndef SHOP_ITEM_H
#define SHOP_ITEM_H

#include <array>

using namespace std;

class Item {
private:
    string name;
    float sellPrice, buyPrice;
public:
    Item();
    Item(const string &name, float sellPrice, float buyPrice);

    const string &getName() const;

    void setName(const string &name);

    float getSellPrice() const;

    void setSellPrice(float sellPrice);

    float getBuyPrice() const;

    void setBuyPrice(float buyPrice);
};


#endif //SHOP_ITEM_H
