//
// Created by azozello on 17.05.17.
//

#ifndef OSBB_HUMAN_H
#define OSBB_HUMAN_H

#include <string>
#include <array>

using namespace std;

class Human {
private:
    string name, surname;
public:
    Human();

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);
};


#endif //OSBB_HUMAN_H
