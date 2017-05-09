//
// Created by azozello on 08.05.17.
//

#ifndef CAMPUS_HUMAN_H
#define CAMPUS_HUMAN_H

#include <array>

using namespace std;

class Human {
private:
    bool sex;
    string name;
public:
    Human();
    Human(bool sex, const string &name);

    bool isSex() const;
    void setSex(bool sex);
    const string &getName() const;
    void setName(const string &name);
};


#endif //CAMPUS_HUMAN_H
