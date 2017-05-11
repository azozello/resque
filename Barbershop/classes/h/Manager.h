//
// Created by azozello on 12.05.17.
//

#ifndef BARBERSHOP_MANAGER_H
#define BARBERSHOP_MANAGER_H

#include <array>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Human.h"
#include "Order.h"
#include "HairDress.h"
#include "HairDresser.h"

using namespace std;

class Manager : public Human {
private:
    string password;

public:
    Manager();

    Manager(bool sex, const string &name, const string &password);

    const string &getPassword() const;
    void setPassword(const string &password);

    vector<Order> loadOrders();
    vector<HairDress> loadHairDresses();
    vector<HairDresser> loadHairDressers();

    Order getOrderByName(string name);
    HairDress getHairDressByName(string name);
    HairDresser getHairDresserByName(string name);

    void addOrder(Order order);
    void addHairDress(HairDress hairDress);
    void addHairDresser(HairDresser hairDresser);
};



#endif //BARBERSHOP_MANAGER_H
