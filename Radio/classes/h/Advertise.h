//
// Created by azozello on 14.05.17.
//

#ifndef RADIO_ADVERTISE_H
#define RADIO_ADVERTISE_H


#include "Item.h"

class Advertise : public Item{
private:
    string path;
public:
    Advertise();

    Advertise(float price, const string &author, const string &path);

    const string &getPath() const;

    void setPath(const string &path);
};


#endif //RADIO_ADVERTISE_H
