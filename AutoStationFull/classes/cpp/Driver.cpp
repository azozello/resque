//
// Created by azozello on 10.05.17.
//

#include "../h/Driver.h"

Driver::Driver(const string &name, float salary) : Human(name), salary(salary) {}

Driver::Driver() {}

float Driver::getSalary() const {
    return salary;
}

void Driver::setSalary(float salary) {
    Driver::salary = salary;
}
