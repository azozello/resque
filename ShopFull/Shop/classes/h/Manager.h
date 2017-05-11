//
// Created by azozello on 02.05.17.
//

#ifndef SHOP_MANAGER_H
#define SHOP_MANAGER_H

#include <array>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Item.h"
#include "Human.h"

using namespace std;

class Manager : public Human {
private:
    string password;

public:
    Manager();

    Manager(const string &name, const string &password);

    vector<Item> loadItems();
    const string &getPassword() const;
    void setPassword(const string &password);
    void addItem(Item item);
};


#endif //SHOP_MANAGER_H
