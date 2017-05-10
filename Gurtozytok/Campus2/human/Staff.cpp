//
// Created by azozello on 09.05.17.
//

#include "Staff.h"

Staff::Staff() {}

Staff::Staff(bool sex, const string &name, float salary, const string &job) : Human(sex, name), salary(salary),
                                                                              job(job) {}

float Staff::getSalary() const {
    return salary;
}

void Staff::setSalary(float salary) {
    Staff::salary = salary;
}

const string &Staff::getJob() const {
    return job;
}

void Staff::setJob(const string &job) {
    Staff::job = job;
}
