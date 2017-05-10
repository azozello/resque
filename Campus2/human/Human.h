//
// Created by azozello on 09.05.17.
//

#ifndef CAMPUS2_HUMAN_H
#define CAMPUS2_HUMAN_H

#include <array>

using namespace std;

class Human {
private:
    bool sex;
    string name;
public:
    Human(bool sex, const string &name);
    Human();

    bool isSex() const;

    void setSex(bool sex);

    const string &getName() const;

    void setName(const string &name);
};


#endif //CAMPUS2_HUMAN_H
