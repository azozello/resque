//
// Created by azozello on 12.05.17.
//

#include "../h/HairDresser.h"

HairDresser::HairDresser() {}

HairDresser::HairDresser(bool sex, const string &name, float salary) : Human(sex, name), salary(salary) {}

float HairDresser::getSalary() const {
    return salary;
}

void HairDresser::setSalary(float salary) {
    HairDresser::salary = salary;
}
