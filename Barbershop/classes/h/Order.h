//
// Created by azozello on 12.05.17.
//

#ifndef BARBERSHOP_ORDER_H
#define BARBERSHOP_ORDER_H

#include <array>

using namespace std;

class Order {
private:
    string hairDress, hairDresser;
    float price;
public:
    Order();

    Order(const string &hairDress, const string &hairDresser, float price);

    const string &getHairDress() const;

    void setHairDress(const string &hairDress);

    const string &getHairDresser() const;

    void setHairDresser(const string &hairDresser);

    float getPrice() const;

    void setPrice(float price);
};


#endif //BARBERSHOP_ORDER_H
