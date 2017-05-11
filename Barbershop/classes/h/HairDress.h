//
// Created by azozello on 12.05.17.
//

#ifndef BARBERSHOP_HAIRDRESS_H
#define BARBERSHOP_HAIRDRESS_H

#include <array>

using namespace std;

class HairDress {
private:
    string name;
    float price;
public:
    HairDress(const string &name, float price);

    HairDress();

    const string &getName() const;

    void setName(const string &name);

    float getPrice() const;

    void setPrice(float price);
};


#endif //BARBERSHOP_HAIRDRESS_H
