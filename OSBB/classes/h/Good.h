//
// Created by azozello on 17.05.17.
//

#ifndef OSBB_GOOD_H
#define OSBB_GOOD_H

#include <array>

using namespace std;

class Good {
private:
    string name;
    float price;
public:
    Good();

    const string &getName() const;

    void setName(const string &name);

    float getPrice() const;

    void setPrice(float price);
};


#endif //OSBB_GOOD_H
