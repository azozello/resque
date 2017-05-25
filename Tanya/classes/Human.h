//
// Created by azozello on 25.05.17.
//

#ifndef TANYA_HUMAN_H
#define TANYA_HUMAN_H

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


#endif //TANYA_HUMAN_H
