//
// Created by azozello on 14.05.17.
//

#ifndef RADIO_HUMAN_H
#define RADIO_HUMAN_H

#include <array>

using namespace std;

class Human {
private:
    string name, surname;
public:
    Human();

    Human(const string &name, const string &surname);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);
};


#endif //RADIO_HUMAN_H
