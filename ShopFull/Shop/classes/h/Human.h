//
// Created by azozello on 11.05.17.
//

#ifndef SHOP_HUMAN_H
#define SHOP_HUMAN_H

#include <array>

using namespace std;

class Human {
private:
    string name;
public:
    Human();

    Human(const string &name);

    const string &getName() const;

    void setName(const string &name);
};


#endif //SHOP_HUMAN_H
