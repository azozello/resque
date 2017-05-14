//
// Created by azozello on 14.05.17.
//

#include "../h/Caster.h"

Caster::Caster(const string &name, const string &surname, float salary) : Human(name, surname), salary(salary) {}

Caster::Caster() {}

float Caster::getSalary() const {
    return salary;
}

void Caster::setSalary(float salary) {
    Caster::salary = salary;
}
