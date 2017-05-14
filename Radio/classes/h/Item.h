//
// Created by azozello on 14.05.17.
//

#ifndef RADIO_ITEM_H
#define RADIO_ITEM_H

#include <array>

using namespace std;

class Item {
private:
    float price;
    string author;
public:
    Item();

    Item(float price, const string &author);

    float getPrice() const;

    void setPrice(float price);

    const string &getAuthor() const;

    void setAuthor(const string &author);
};


#endif //RADIO_ITEM_H
