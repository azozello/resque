//
// Created by azozello on 12.05.17.
//

#ifndef BARBERSHOP_HAIRDRESSER_H
#define BARBERSHOP_HAIRDRESSER_H


#include "Human.h"

class HairDresser : public Human {
private:
    float salary;
public:
    HairDresser(bool sex, const string &name, float salary);

    HairDresser();

    float getSalary() const;

    void setSalary(float salary);
};


#endif //BARBERSHOP_HAIRDRESSER_H
