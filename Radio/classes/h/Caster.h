//
// Created by azozello on 14.05.17.
//

#ifndef RADIO_CASTER_H
#define RADIO_CASTER_H


#include "Human.h"

class Caster : public Human {
private:
    float salary;
public:
    Caster();

    Caster(const string &name, const string &surname, float salary);

    float getSalary() const;

    void setSalary(float salary);
};


#endif //RADIO_CASTER_H
