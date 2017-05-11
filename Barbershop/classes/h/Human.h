//
// Created by azozello on 12.05.17.
//

#ifndef BARBERSHOP_HUMAN_H
#define BARBERSHOP_HUMAN_H


#include <array>

using namespace std;

class Human {
private:
    bool sex;
    string name, surname;
public:
    Human();
    Human(bool sex, const string &name);

    bool isSex() const;
    void setSex(bool sex);
    const string &getName() const;
    void setName(const string &name);

    const string &getSurname() const;
    void setSurname(const string &surname);
};


#endif //BARBERSHOP_HUMAN_H
