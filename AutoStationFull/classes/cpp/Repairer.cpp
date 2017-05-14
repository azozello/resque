//
// Created by azozello on 10.05.17.
//

#include "../h/Repairer.h"

Repairer::Repairer(const string &name, float salary) : Human(name), salary(salary) {}

Repairer::Repairer() {}

float Repairer::getSalary() const {
    return salary;
}

void Repairer::setSalary(float salary) {
    Repairer::salary = salary;
}
